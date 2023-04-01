#include "./includes/main.h"

int main(int argc, char **argv) {
    int max_time = 0;
    int max_typo = 0;

    if (argc > 2) {
        #if DEBUG
            puts(argv[2]);
        #endif

        char* time_opt = argv[2];
        if (time_opt != NULL) {
            bool non_digit = 0;
            for (int i = 0; time_opt[i] != '\0'; i++)
                if (!isdigit(time_opt[i])) {
                    non_digit = 1;
                }
            if (non_digit) {
                puts("ERROR: Wrong time format!");
                return 3;
            } 
            max_time = atoi(time_opt);
            if (max_time < 0)
                puts("ERROR: Time should be natural!");
        }
    }

    if (argc > 3) {
        #if DEBUG
            puts(argv[3]);
        #endif

        char* max_typo_opt = argv[3];
        if (max_typo_opt != NULL) {
            bool non_digit = 0;
            for (int i = 0; max_typo_opt[i] != '\0'; i++)
                if (!isdigit(max_typo_opt[i])) {
                    non_digit = 1;
                }
            if (non_digit) {
                puts("ERROR: Wrong max typo count format!");
                return 3;
            } 
            max_typo = atoi(max_typo_opt);
            if (max_typo < 0)
                puts("ERROR: max typo count should be natural!");
        }
    }

    char path[64] = "./texts/";
    char *cmd = argv[1];
    if (cmd == NULL) {
        puts("\tERROR: Empty input!");
        puts("\tUse \'-help\' command to read manual\n");
        return -1;
    }
    
    if (strcmp(cmd, "easy") == 0 || strcmp(cmd, "medium") == 0 ||
        strcmp(cmd, "hard") == 0  || strcmp(cmd, "debug") == 0) {

        strcat(cmd, ".txt");
        strcat(path, cmd);

        #if DEBUG
            puts(cmd);
            puts(path);
            printf("argc = %d", argc);
        #endif
        
    } else if (strcmp(cmd, "-help") == 0) {
        char msg[500];

        readfile("./texts/manual.txt", msg);

        puts(msg);
        return 0;

    } else {
        puts("\tCommand not found!");
        puts("\tUse \'-help\' command to read manual\n");
        return 2;
    }


    int x = 0, y = 0;
    int typo_count = 0;
    int max_x, max_y;
    
    char filebuf[BUFFSIZE];

    readfile(path, filebuf);

    char c;
    
    initscr();
    noecho();

    start_color();  // Color initialization
	init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);

    keypad(stdscr, true);

    getmaxyx(stdscr, max_y, max_x);

    int prev = x, current = 0;
    int i = 0;
    while (prev < strlen(filebuf)) {
        if (filebuf[i] == '\n' || filebuf[i] == '\0' ) {
            current = i;
        }
        if (current - prev > max_x) {
            for (int j = prev + max_x; j > prev; j--) {
                if (filebuf[j] == ' ') {
                    filebuf[j] = '\n';
                    prev = j;
                    break;
                }    
            }     
        } else {
            prev = current;
        }
        i++;        
    }
    i = 0;

    #if DEBUG
        endwin();
        printf("max_y = %d\n", max_y);
        printf("max_x = %d\n", max_x);
        puts(filebuf);
        return 0;
    #endif

    /*    Working correctly 
    for (int i = y, j = x, index = 0; index < strlen(filebuf); index++) {
        if (filebuf[index] != '\n') {
            mvaddch(i, j++, filebuf[index]);
        } else {
            mvaddch(i, j++, filebuf[index]);
            i++;
            j = 0;
        }
    }
    */

   // temp
    int start_index = 0;
    for (i = 0; i < max_y - 1; i++) {
        start_index = writeline(filebuf, start_index, i);
    }

    time_t start_time = time(NULL);
    move(y, x);
    int previous_line_showed = 0;
    int next_showed = 0;
    int index = 0;
    double d_time = 0;

    for (; index < strlen(filebuf); index++) {
        if (!next_showed) {
            writeline(filebuf, start_index, max_y - 1);
            move(y, x);
        }
        time_t current_time = time(NULL);
        if (max_time > 0 && (d_time = difftime(current_time, start_time))
                                                    > (double) max_time) {            
            game_stat(typo_count, index, d_time, "Game over: Time is over");
            return 6;
        }
        if (max_typo > 0 && typo_count > max_typo) {
            game_stat(typo_count, index, d_time, "Game over: Too many typos");
            return 7;
        }
        c = getch();
        if (c == filebuf[index] || filebuf[index] == '\n') {
            if (filebuf[index] == '\n') {
                x = 0;
                if (previous_line_showed) {
                    y = 0;
                    move(y, x);
                    deleteln();
                    next_showed = 1;
                } else {
                    previous_line_showed = 1;
                }
                y++;
                move(y, x);
            }
            else {
                attron(COLOR_PAIR(2));
                mvaddch(y, x++, c);
                attroff(COLOR_PAIR(2));
            }
        } else {
            typo_count++;
            attron(COLOR_PAIR(1));
            mvaddch(y, x++, filebuf[index]);
            attroff(COLOR_PAIR(1));
        }

        move(max_y - 1, 0);
        clrtoeol();
        if (next_showed) {
            start_index = writeline(filebuf, start_index, max_y - 1);
            next_showed = 0;
        }
    }
    

    mvprintw(++y, 0, "Press any key to exit...");
    mvprintw(++y, 0, "%d", typo_count);

    game_stat(typo_count, index, d_time, "Congratulations! You've won!");

    getch();  // Pause      

    endwin(); // End.

    return 0;
}

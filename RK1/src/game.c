#include <ncurses.h>

int writeline(char *text, int start_index, int y) {
    int x = 0;
    while (text[start_index + x] != '\n' && text[start_index + x] != '\0') {
        mvaddch(y, x, text[start_index + x]);
        x++;
    }
    if (start_index + x + 1 >= strlen(text)) {
        text[start_index + x] = '\0';
    } else {
        text[start_index + x] = '\n';
    }
    return start_index + x + 1;
}


void game_stat(int errors, int total_printed, float total_time, const char* reason) {
    int correct = total_printed - errors;
    float accuracy = (float) correct / total_printed * 100;
    float speed = total_printed / total_time * 60;

    endwin();

    puts(reason);
    puts("Game statistics.");
    printf("Total entered characters: %d\n", total_printed);
    printf("Correctly entered characters: %d\n", correct);
    printf("Typos count: %d\n", errors);
    printf("Accuracy %.2f%%\n", accuracy);

    if (total_time > 0) {
        printf("Totla time: %.2f s\n", total_time);
        printf("Average speed: %.2f char/min\n", speed);
    }
    return;
}

#include <stdio.h>

int readfile(const char *path, char *str) {
    FILE *file_p = fopen(path, "r");

    if (file_p != NULL) {
        int i = 0;
        char c;

        while ((c = (char) fgetc(file_p)) != EOF) {
            str[i++] = c;
        }
        str[i] = '\0';
        str[i + 1] = '\0';
        fclose(file_p);
    }
    else {
        return 1;
    }
    return 0;
}

#if DEBUG
int main() {
    time_t time1 = time(NULL);
    char path[] = "./texts/hard.txt";
    char s[BUFFSIZE];
    readfile(path, s);
    //puts(s);
    getchar();
    time_t time2 = time(NULL);
   printf("dt = %f\n", difftime(time2, time1));
    
    return 0;
}
#endif

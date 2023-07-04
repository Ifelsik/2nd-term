#include <stdio.h>
#include <stdlib.h>

int readfile(const char *path, char **str) {
    FILE *file_p = fopen(path, "r");

    if (file_p != NULL) {

        fseek(file_p, 0, SEEK_END);
        int len = ftell(file_p);  // len of file
        fseek(file_p, 0, SEEK_SET);

        *str = (char*) malloc(sizeof(char) * (len + 1));
        if (NULL != *str)
            fread(*str, sizeof(char), len + 1, file_p);
        else
            return 1;

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

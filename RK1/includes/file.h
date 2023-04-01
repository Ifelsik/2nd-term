#ifndef FILE_H
#define FILE_H

int readfile(const char* path, char *str);

#define DEBUG 0

#if DEBUG

#include <time.h>

#define BUFFSIZE 4096

#endif

#endif

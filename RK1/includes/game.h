#ifndef GAME_H
#define GAME_H

int writeline(char *text, int start_index, int y);

void game_stat(int errors, int total_printed, float total_time, const char* reason);

#endif

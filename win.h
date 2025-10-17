#ifndef WIN_H
#define WIN_H

#include <stdbool.h>

void init_win_conditions(int ***win_horizontal, int ***win_vertical, int ***win_diagonal);
bool check_win(char *tab_values, int **h, int **v, int **d, char symbole);
void free_win_conditions(int **h, int **v, int **d);

#endif

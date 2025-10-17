#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

char *create_board(void);
void display_board(char *tab_values);
bool is_valid_move(char *tab_values, int number_choice);
void free_board(char *tab_values);

#endif

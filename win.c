#include <stdlib.h>
#include <stdbool.h>
#include "win.h"

// J'initialise les combinaisons gagnantes (horizontal, vertical, diagonal)
void init_win_conditions(int ***win_horizontal, int ***win_vertical, int ***win_diagonal) {
    *win_horizontal = malloc(3 * sizeof(int *));
    *win_vertical = malloc(3 * sizeof(int *));
    *win_diagonal = malloc(2 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        (*win_horizontal)[i] = malloc(3 * sizeof(int));
        (*win_vertical)[i] = malloc(3 * sizeof(int));
    }
    for (int i = 0; i < 2; i++) {
        (*win_diagonal)[i] = malloc(3 * sizeof(int));
    }

    int tmp_horizontal[3][3] = {{0,1,2},{3,4,5},{6,7,8}};
    int tmp_vertical[3][3]   = {{0,3,6},{1,4,7},{2,5,8}};
    int tmp_diagonal[2][3]   = {{0,4,8},{2,4,6}};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            (*win_horizontal)[i][j] = tmp_horizontal[i][j];
            (*win_vertical)[i][j] = tmp_vertical[i][j];
        }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            (*win_diagonal)[i][j] = tmp_diagonal[i][j];
}

// Je vérifie si un joueur a gagné
bool check_win(char *tab_values, int **h, int **v, int **d, char symbole) {
    for (int i = 0; i < 3; i++) {
        if ((tab_values[h[i][0]] == symbole && tab_values[h[i][1]] == symbole && tab_values[h[i][2]] == symbole) ||
            (tab_values[v[i][0]] == symbole && tab_values[v[i][1]] == symbole && tab_values[v[i][2]] == symbole))
            return true;
    }
    for (int i = 0; i < 2; i++) {
        if (tab_values[d[i][0]] == symbole && tab_values[d[i][1]] == symbole && tab_values[d[i][2]] == symbole)
            return true;
    }
    return false;
}

// Je libère la mémoire allouée pour les conditions de victoire
void free_win_conditions(int **h, int **v, int **d) {
    for (int i = 0; i < 3; i++) {
        free(h[i]);
        free(v[i]);
    }
    for (int i = 0; i < 2; i++) {
        free(d[i]);
    }
    free(h);
    free(v);
    free(d);
}

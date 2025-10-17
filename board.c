#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"


//j'attribue une allocation dans la mémoire à mon tableau et j'attribue un caractère ' ' à chaque case pour que le tableau ne bouge pas lorsqu'un symbole est attribuée à une case.
char *create_board(void) {
    char *tab_values = malloc(9 * sizeof(char));
    for (int i = 0; i < 9; i++) tab_values[i] = ' ';
    return tab_values;
}

//Je crée mon tableau et assigne à chacune de mes cases une valeur qui correspond à son indice
void display_board(char *tab_values) {
    printf("\n");
    printf(" %c | %c | %c \n", tab_values[0], tab_values[1], tab_values[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tab_values[3], tab_values[4], tab_values[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tab_values[6], tab_values[7], tab_values[8]);
    printf("\n");
}

//cette fonction permet de vérifier si le chiffre choisi est bien compris entre 1 et 9 et si la case indexée est bien vide
bool is_valid_move(char *tab_values, int number_choice) {
    return number_choice >= 1 && number_choice <= 9 && tab_values[number_choice - 1] == ' ';
}


//clear le tableau après chaque tour de jeu
void free_board(char *tab_values) {
    free(tab_values);
}

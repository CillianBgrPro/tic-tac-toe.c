#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "board.h"
#include "bot.h"
#include "win.h"

int main(void) {
    srand(time(NULL));

    char *tab_values = create_board();
    int **win_horizontal, **win_vertical, **win_diagonal;
    init_win_conditions(&win_horizontal, &win_vertical, &win_diagonal);

    bool premier_tour_bot = true;
    int number_choice, bot;

    while (true) {
        display_board(tab_values);

        printf("Choisissez où jouer (1 à 9) : ");
        scanf("%d", &number_choice);

        if (!is_valid_move(tab_values, number_choice)) {
            printf("Choix invalide, réessayez.\n");
            continue;
        }

        tab_values[number_choice - 1] = 'X';

        if (check_win(tab_values, win_horizontal, win_vertical, win_diagonal, 'X')) {
            display_board(tab_values);
            printf("\nVous avez gagné !\n");
            break;
        }

        bot = choose_bot_move(tab_values, premier_tour_bot);
        premier_tour_bot = false;

        tab_values[bot] = 'O';
        printf("\nL'adversaire a joué en position %d\n", bot + 1);

        if (check_win(tab_values, win_horizontal, win_vertical, win_diagonal, 'O')) {
            display_board(tab_values);
            printf("\nL'adversaire a gagné !\n");
            break;
        }

        system("clear");
    }

    free_board(tab_values);
    free_win_conditions(win_horizontal, win_vertical, win_diagonal);

    return 0;
}

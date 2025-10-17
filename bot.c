#include <stdlib.h>
#include <stdbool.h>
#include "bot.h"


//oblige le bot à remplir la première case de libre lors du premier tour
int choose_bot_move(char *tab_values, bool premier_tour_bot) {
    if (premier_tour_bot) {
        for (int i = 0; i < 9; i++) {
            if (tab_values[i] == ' ')
                return i;
        }
    }
//après le premier tour le bot place ensuite son symbole aléatoirement
    int bot;
    do {
        bot = rand() % 9;
    } while (tab_values[bot] == 'X' || tab_values[bot] == 'O');
    return bot;
}

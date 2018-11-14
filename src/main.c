/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_2018
** File description:
** Created by mcarpentier,
*/

#include "hunter.h"
#include <time.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    my_game_t *game = generate_game();
    game = launch_game(game);
    printf("Score final : %d\n", game->score);
}

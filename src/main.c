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
    my_game_t *game;

    if(ac == 2)
        if(my_strcmp(av[1], "-h") == 0) {
            my_putstr("Welcome to Rocket !\n");
            my_putstr("Rockets will appears on the screen !\n");
            my_putstr("You need to kill them by clicking on them !\n");
            my_putstr("Take care ! You only have three life\n");
            my_putstr("If you missed a rocket of if she go to the other side");
            my_putstr("of the screen, you loose a life !\n");
            my_putstr("Good luck and have fun !\n");
        }
    game = generate_game();
    game = launch_game(game);
}

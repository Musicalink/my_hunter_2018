/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_2018
** File description:
** Created by mcarpentier,
*/

#include "hunter.h"
#include <time.h>
#include <stdlib.h>

void kill_music(sfMusic *music)
{
    sfMusic_stop(music);
    sfMusic_destroy(music);
}

void kill_object(my_object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    free(object);
}

void killer(my_game_t *game)
{
    kill_music(game->music);
    kill_music(game->missed);
    kill_music(game->kill);
    sfClock_destroy(game->clock);
    kill_object(game->bird);
    kill_object(game->window->spr);
    sfRenderWindow_destroy(game->window->window);
    free(game->window);
    free(game);
}
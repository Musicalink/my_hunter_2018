/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_2018
** File description:
** Created by mcarpentier,
*/

#include "hunter.h"
#include <time.h>
#include <stdlib.h>

my_game_t *my_clock(my_game_t *game)
{
    float seconds;
    while (seconds < 0.05 - ((game->score % 100) * 0.05 / 100 + 0.05 / 100)) {
        game->time = sfClock_getElapsedTime(game->clock);
        game = my_event(game);
        seconds = game->time.microseconds / 1000000.0;
    }
    sfClock_restart(game->clock);
    return (game);
}

void display(my_game_t *game)
{
    sfRenderWindow_clear(game->window->window, sfBlack);
    sfRenderWindow_drawSprite(game->window->window, game->window->spr->sprite,
        NULL);
    sfRenderWindow_drawSprite(game->window->window, game->bird->sprite, NULL);
    sfRenderWindow_display(game->window->window);
}

my_game_t *bird_pos(my_game_t *game, int t, int t2)
{
    game->bird->rect = create_IntRect(0, 186 * t, 186, 186);
    game->window->spr->rect = create_IntRect(0, 1920 * t2, 1920, 1080);
    game->bird->pos.x += 15;
    if (game->bird->jumper % 13 < 8 && game->bird->pos.y > 0)
        game->bird->pos.y -= (game->score % 100) * 1.02;
    else if (game->bird->jumper % 13 < 12 && game->bird->jumper % 13 >= 8 &&
        game->bird->pos.y < 1080)
        game->bird->pos.y += (game->score % 100 * 1.02) * 2;
    game->bird->jumper++;
    if (game->bird->pos.x > 1920) {
        game->life--;
        sfMusic_play(game->missed);
        game->bird->status++;
        game->bird->pos.x = 0;
        game->bird->pos.y = (rand() % (1080 - 186));
    }
    sfSprite_setPosition(game->bird->sprite, game->bird->pos);
    sfSprite_setTextureRect(game->bird->sprite, game->bird->rect);
    sfSprite_setTextureRect(game->window->spr->sprite, game->window->spr->rect);
    return (game);
}

my_game_t *launch_game(my_game_t *game)
{
    int t = 0;
    int t2 = 0;

    while (sfRenderWindow_isOpen(game->window->window) && game->life != 0) {
        display(game);
        game = my_clock(game);
        game = bird_pos(game, t, t2);
        t++;
        t2++;
        if (t == 15)
            t = 0;
        if (t2 == 8)
            t2 = 0;
    }
    killer(game);
    return (game);
}
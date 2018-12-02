/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_2018
** File description:
** Created by mcarpentier,
*/

#include "hunter.h"
#include "my.h"
#include <time.h>
#include <stdlib.h>

my_game_t *my_click_event(my_game_t *game, sfVector2f cursor, sfEvent event)
{
    sfVector2f pos = game->bird->pos;

    if (cursor.x >= pos.x && cursor.x <= pos.x + 186 && cursor.y >= pos.y)
        if (cursor.y <= pos.y + 186) {
            game->bird->pos.x = 0;
            game->bird->pos.y = (rand() % (1080 - 186));
            sfSprite_setPosition(game->bird->sprite, game->bird->pos);
            sfMusic_play(game->kill);
            game->score++;
            game->bird->jumper = 0;
            sfText_setString(game->text, my_itoa(game->score));
            return (game);
        }
    game->life--;
    sfMusic_play(game->missed);
    game->life_obj->rect = create_IntRect(0, 0, 100 * game->life, 100);
    sfSprite_setTextureRect(game->life_obj->sprite, game->life_obj->rect);
    game->life_obj->pos.x += 50;
    sfSprite_setPosition(game->life_obj->sprite, game->life_obj->pos);
    return (game);
}

my_game_t *my_event(my_game_t *game)
{
    sfEvent event;
    sfVector2i cursor_pos = sfMouse_getPosition(game->window->window);
    sfVector2f cursor;

    cursor.x = (float)cursor_pos.x;
    cursor.y = (float)cursor_pos.y;
    while (sfRenderWindow_pollEvent(game->window->window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window->window);
        else if (event.type == sfEvtMouseButtonPressed)
            game = my_click_event(game, cursor, event);
    return (game);
}
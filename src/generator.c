/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_2018
** File description:
** Created by mcarpentier,
*/

#include "hunter.h"
#include <time.h>
#include <stdlib.h>

sfIntRect create_IntRect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

my_object_t *generate_object(char *texture_path, int x, int y, int bool)
{
    my_object_t *object = malloc(sizeof(my_object_t));

    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(texture_path, NULL);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    if (bool != 0) {
        object->rect = create_IntRect(0, 0, y, x);
        sfSprite_setTextureRect(object->sprite, object->rect);
    }
    object->status = 0;
    object->pos.x = 0;
    object->pos.y = 0;
    object->jumper = 0;
    return (object);
}

my_window_t *generate_window(void)
{
    my_window_t *window = malloc(sizeof(my_window_t));
    sfVideoMode mode = {1920, 1080, 32};

    window->window = sfRenderWindow_create(mode, "Kill Flappy Bird", sfClose,
        NULL);
    window->spr = generate_object(BG, 0, 0, 0);
    return (window);
}

sfText *gen_score(void)
{
    sfText *text = sfText_create();
    sfVector2f size;
    sfVector2f pos;

    size.x = 3;
    size.y = 3;
    pos.x = 910;
    sfText_setString(text, "0");
    sfText_setScale(text, size);
    sfText_setPosition(text, pos);
    sfFont *font = sfFont_createFromFile(FONT);
    sfText_setFont(text, font);
    return(text);
}

my_game_t *generate_game(void)
{
    my_game_t *game = malloc(sizeof(my_game_t));

    game->bird = generate_object(TEXT, 186, 186, 1);
    game->window = generate_window();
    game->clock = sfClock_create();
    game->music = sfMusic_createFromFile(MUSIC);
    sfMusic_setVolume(game->music, 30);
    game->kill = sfMusic_createFromFile(KILL);
    sfMusic_setVolume(game->kill, 50);
    game->missed = sfMusic_createFromFile(MISSED);
    sfMusic_setVolume(game->missed, 70);
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, sfTrue);
    game->life = 3;
    game->life_obj = generate_object(LIFE, 100, 300, 1);
    game->life_obj->pos.x = 810;
    game->life_obj->pos.y = 980;
    sfSprite_setPosition(game->life_obj->sprite, game->life_obj->pos);
    game->text = gen_score();
    return (game);
}

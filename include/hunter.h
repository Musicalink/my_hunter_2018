/*
** EPITECH PROJECT, 2023
** MUL_my_hunter_2018
** File description:
** Created by mcarpentier,
*/

#ifndef MUL_MY_HUNTER_2018_HUNTER_H
#define MUL_MY_HUNTER_2018_HUNTER_H

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct my_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    int status;
    int jumper;
} my_object_t;

typedef struct my_window {
    sfRenderWindow *window;
    my_object_t *spr;
} my_window_t;

typedef struct my_game {
    my_object_t *bird;
    my_window_t *window;
    sfClock *clock;
    sfTime time;
    sfMusic *music;
    sfMusic *kill;
    sfMusic *missed;
    int score;
    int life;
} my_game_t;

#define TEXT "img/asteroid.png"
#define BG "img/bg2.png"
#define MUSIC "img/music.ogg"
#define KILL "img/kill.ogg"
#define MISSED "img/missed.ogg"
#define LIFE "img/life.png"
#define NOLIFE "img/nolife.png"

sfIntRect create_IntRect(int top, int left, int width, int height);

my_object_t *generate_object(char *texture_path, int x, int y, int bool);

my_window_t *generate_window(void);

my_game_t *generate_game(void);

my_game_t *my_click_event(my_game_t *game, sfVector2f cursor, sfEvent event);

my_game_t *my_event(my_game_t *game);

void kill_music(sfMusic *music);

void kill_object(my_object_t *object);

void killer(my_game_t *game);

my_game_t *my_clock(my_game_t *game);

void display(my_game_t *game);

my_game_t *bird_pos(my_game_t *game, int t, int t2);

my_game_t *launch_game(my_game_t *game);

#endif //MUL_MY_HUNTER_2018_HUNTER_H
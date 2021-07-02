/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** render map
*/

#include "../include/game.h"

static void set_AB_color(tile_t *tile, main_t *main)
{
    sfVector2f player;
    sfVector2f pos;
    float volume = 0;

    if (tile->type == 3 || tile->type == 4 ||
                    tile->type == -3 || tile->type == -4) {
        player = sfSprite_getPosition(PLAYER->sprite);
        pos = sfSprite_getPosition(tile->sprite);
        volume = 10000 / ABS(player.x - pos.x);
        if (volume > 20)
            volume = 20;
        if (volume < 4)
            volume = 0;
        sfSound_setVolume(tile->sound, volume);
        sfSound_play(tile->sound);
        if (tile->type == INTS->state * -1 || tile->type == INTS->state) {
            sfSprite_setTexture(tile->sprite, tile->t_base, 0);
        } else {
            sfSprite_setTexture(tile->sprite, tile->t_second, 0);
        }
    }
}

void AB_switch(main_t *main)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(main->ints->AB_clock)) > 1) {
        if (main->ints->state == 3)
            main->ints->state = 4;
        else
            main->ints->state = 3;
        sfClock_restart(main->ints->AB_clock);
        for (int i = 0; i < main->map->size.y; i++)
            for (int j = 0; j < main->map->size.x + 1; j++)
                set_AB_color(MAP[i][j], main);
    }
}

void map_display(main_t *main, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f end = sfSprite_getPosition(MAP[10][main->map->size.x]->sprite);

    if (PLAYER->pos.x > 12)
        INTS->map_move.x = -10;
    if (pos.x > 900)
        INTS->map_move.x = -14;
    if (end.x < 1280)
        INTS->map_move.x = 0;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        INTS->map_move.x += 10;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        INTS->map_move.x += -10;
    for (int i = 0; i < main->map->size.y; i++)
        for (int j = 0; j < main->map->size.x + 1; j++)
            if (MAP[i][j]->sprite != NULL) {
                sfSprite_move(MAP[i][j]->sprite, INTS->map_move);
                sfRenderWindow_drawSprite(window, MAP[i][j]->sprite, NULL);
            }
}
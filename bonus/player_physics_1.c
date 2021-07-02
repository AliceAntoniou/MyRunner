/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** physics fonctions
*/

#include "../include/game.h"

void set_colision(main_t *main, map_t *map, sfVector2f *pos)
{
    sfVector2f test;

    if (RIGHT_TILE->type == 1 || RIGHT_TILE->type == INTS->state) {
        test = sfSprite_getPosition(RIGHT_TILE->sprite);
        pos->x = test.x - 64 + INTS->map_move.x;
    }
    if (ACTUAL_TILE->type == 1 || ACTUAL_TILE->type == INTS->state) {
        test = sfSprite_getPosition(ACTUAL_TILE->sprite);
        pos->x = test.x + 64 + INTS->map_move.x;
    }
    if (UPPER_TILE->type == 1) {
        pos->y = PLAYER->pos.y * 64 + 132;
    }
    if (RIGHT_TILE->type > 5 || ACTUAL_TILE->type > 5)
        reset(main);
    if (LOWER_TILE->type == 1 || LOWER_RIGHT_TILE->type == 1) {
        pos->y = 132 + PLAYER->pos.y * 64;
        PLAYER->vector.y = 0;
    }
}

void get_moves(main_t *main, map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) == 0
                    && sfKeyboard_isKeyPressed(sfKeyQ) == 0)
        PLAYER->vector.x = INTS->map_move.x;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        PLAYER->vector.x = INTS->map_move.x - 14;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        PLAYER->vector.x = INTS->map_move.x + 14;
}

void set_player_moves(main_t *main, map_t *map)
{
    sfVector2f pos = sfSprite_getPosition(PLAYER->sprite);
    PLAYER->pos.y = ((int)pos.y - 131) / 64;
    sfVector2f a = sfSprite_getPosition(map->map[10][PLAYER->pos.x]->sprite);
    if (a.x < pos.x - 64.00) {
        PLAYER->pos.x++;
    }
    if (a.x > pos.x) {
        PLAYER->pos.x--;
    }
    PLAYER->vector.y += 1.5;
    if (PLAYER->pos.y < 1)
        return;
    if (ACTUAL_TILE->type > 0)
        PLAYER->vector.y = 0;
    set_colision(main, map, &pos);
    get_moves(main, map);
    if (sfKeyboard_isKeyPressed(sfKeySpace) &&
                    (LOWER_TILE->type == 1 || LOWER_RIGHT_TILE->type == 1))
        PLAYER->vector.y -= 20;
    sfSprite_setPosition(PLAYER->sprite, pos);
}
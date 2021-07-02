/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** hitbox
*/

#include "../include/game.h"

static int test_block(int x, int y, main_t *main, spot_t *tmp)
{
    sfVector2f hitbox = sfSprite_getPosition(main->map->map[y][x]->sprite);

    hitbox.x += INTS->map_move.x;
    if (HIT_BLOCK_X && HIT_BLOCK_Y) {
        if (TYPE == -10 || TYPE == INTS->state * -1) {
            hurt_player(main);
            return 1;
        }
        if (TYPE == INTS->state * 1 || TYPE > 20 || TYPE == 10)
            return 1;
        if (TYPE == 20)
            main->win = 1;
    }
    if (HIT_BLOCK_X && HIT_DH_BLOCK_Y) {
        if (TYPE == -7)
            hurt_player(main);
        if (TYPE == 11)
            return 1;
    }
    return 0;
}

static int is_colision(spot_t *tmp, main_t *main)
{
    for (int y = PLAYER->pos.y - 1; y <= PLAYER->pos.y + 2; y++)
        for (int x = PLAYER->pos.x - 1; x <= PLAYER->pos.x + 2; x++) {
            if (TYPE > 2 || TYPE < -2 ) {
                if (test_block(x, y, main, tmp))
                    return 1;
            }
        }
    return 0;
}

static sfVector2f get_vector(int direction)
{
    sfVector2f vector = {0, 0};

    switch (direction) {
    case left:
        vector.x = 0.5F;
        break;
    case right:
        vector.x = -0.5F;
        break;
    case up:
        vector.y = 0.5F;
        break;
    case down:
        vector.y = -0.5F;
        break;
    }
    return vector;
}

void calc_colisions(main_t *main)
{
    for (int i = 0; i < 8; i++) {
        while (is_colision(PLAYER->spots[i], main)) {
            move_player(PLAYER, get_vector(PLAYER->spots[i]->direction), 0);
            if (PLAYER->spots[i]->direction >= 2)
                PLAYER->vector.y = 0;
            if (PLAYER->spots[i]->direction < 2)
                PLAYER->vector.x = 0;
        }
        for (mobs_l *tmp = main->map->mobs; tmp != NULL; tmp = tmp->next) {
            if (sfFloatRect_contains(&tmp->data->hitbox,
                PLAYER->spots[i]->pos.x, PLAYER->spots[i]->pos.y))
                hurt_player(main);
        }
    }
}
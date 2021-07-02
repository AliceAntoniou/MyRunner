/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** physics fonctions
*/

#include "../include/game.h"

void calc_colisions(main_t *main);

void move_totem(main_t *main)
{
    sfVector2f player = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f totem = sfSprite_getPosition(SPRITES->totem);
    sfVector2f totem_move = {0, 0};

    totem_move.x += INTS->map_move.x;
    if ((player.x - 64) - totem.x > 0)
        totem_move.x += 12;
    if ((player.x + 64) - totem.x < 0)
        totem_move.x += -12;
    if ((player.y - 100) - totem.y > 0)
        totem_move.y += 12;
    if ((player.y - 20) - totem.y < 0)
        totem_move.y += -12;
    sfSprite_move(SPRITES->totem, totem_move);
}

void hurt_player(main_t *main)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(PLAYER->invincibility)) > 1) {
        PLAYER->pv--;
        sfSound_play(main->sounds->hurt);
        sfSprite_setColor(PLAYER->sprite, sfRed);
        sfSprite_setColor(PLAYER->arm_1->sprite, sfRed);
        sfSprite_setColor(PLAYER->arm_2->sprite, sfRed);
        sfSprite_setColor(PLAYER->leg_1->sprite, sfRed);
        sfSprite_setColor(PLAYER->leg_2->sprite, sfRed);
        sfClock_restart(PLAYER->invincibility);
    }
}

void keyboard_move(main_t *main)
{
    if (sfKeyboard_isKeyPressed(sfKeyD) == 0 &&
                    sfKeyboard_isKeyPressed(sfKeyQ) == 0)
        PLAYER->vector.x = INTS->map_move.x;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        PLAYER->vector.x = INTS->map_move.x - 14;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        PLAYER->vector.x = INTS->map_move.x + 14;
    if (PLAYER->vector.y > 30)
        PLAYER->vector.y = 30;
    if (PLAYER->pos.y < 1) {
        move_player(PLAYER, PLAYER->vector, INTS->map_move.x);
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) && (ABS(LOWER_TILE->type) > 9
                    || ABS(LOWER_TILE->type) == INTS->state))
        PLAYER->vector.y -= 15;
    if (PLAYER->vector.y < -30)
        PLAYER->vector.y = -30;
}

void attack(main_t *main, sfRenderWindow *window)
{
    sfVector2f player = sfSprite_getPosition(PLAYER->sprite);
    sfFloatRect attack = {player.x, player.y - 60, 100, 100};
    int c = 0;

    if (PLAYER->side == right)
        attack.left += 16;
    if (PLAYER->side == left)
        attack.left -= 116;
    for (mobs_l *tmp = main->map->mobs; tmp != NULL; tmp = tmp->next) {
        if (sfFloatRect_intersects(&attack, &tmp->data->hitbox, NULL)) {
            delete_mob(&main->map->mobs, c);
            return;
        }
        c++;
    }
}

void player_moves(main_t *main, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(PLAYER->sprite);
    sfVector2f a = sfSprite_getPosition(MAP[0][PLAYER->pos.x]->sprite);

    PLAYER->pos.y = ((int)pos.y) / 64;
    if (a.x < pos.x - 64.00) {
        PLAYER->pos.x++;
        INTS->score++;
    }
    if (a.x > pos.x) {
        PLAYER->pos.x--;
        INTS->score--;
    }
    PLAYER->vector.y += 1.5;
    keyboard_move(main);
    move_player(PLAYER, PLAYER->vector, INTS->map_move.x);
    if (PLAYER->pos.y > 10 || PLAYER->pos.x < 1 || pos.x < 0)
        reset(main);
    calc_colisions(main);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        attack(main, window);
}
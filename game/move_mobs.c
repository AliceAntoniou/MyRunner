/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** move mobs
*/

#include "../include/game.h"
#include <math.h>

static void move_member(ennemy_t *mob, int move)
{
    sfVector2f pos = sfSprite_getPosition(mob->sprite);

    pos.y -= 26;
    sfSprite_setPosition(mob->arm_1->sprite, pos);
    sfSprite_setPosition(mob->arm_2->sprite, pos);
    pos.y += 50;
    sfSprite_setPosition(mob->leg_1->sprite, pos);
    sfSprite_setPosition(mob->leg_2->sprite, pos);
    mob->arm_1->rotation += 0.01 * move;
    mob->arm_2->rotation += 0.01 * move;
    mob->leg_1->rotation += 0.02 * move;
    mob->leg_2->rotation += 0.02 * move;
    sfSprite_setRotation(mob->arm_1->sprite,
                    sinf(mob->arm_1->rotation) * 50);
    sfSprite_setRotation(mob->arm_2->sprite,
                    sinf(mob->arm_2->rotation) * -50);
    sfSprite_setRotation(mob->leg_1->sprite,
                    sinf(mob->leg_1->rotation) * 30);
    sfSprite_setRotation(mob->leg_2->sprite,
                    sinf(mob->leg_2->rotation) * -30);
}

void set_mob_rotation(ennemy_t *mob, sfVector2f vector, int map)
{
    if (vector.x - map > 1) {
        sfSprite_setTexture(mob->arm_1->sprite, mob->arm_1->texture_right, 1);
        sfSprite_setTexture(mob->arm_2->sprite, mob->arm_2->texture_right, 1);
        sfSprite_setTexture(mob->leg_1->sprite, mob->leg_1->texture_right, 1);
        sfSprite_setTexture(mob->leg_2->sprite, mob->leg_2->texture_right, 1);
        sfSprite_setTexture(mob->sprite, mob->texture_right, 1);
    }
    if (vector.x - map < -1) {
        sfSprite_setTexture(mob->arm_1->sprite, mob->arm_1->texture_left, 1);
        sfSprite_setTexture(mob->arm_2->sprite, mob->arm_2->texture_left, 1);
        sfSprite_setTexture(mob->leg_1->sprite, mob->leg_1->texture_left, 1);
        sfSprite_setTexture(mob->leg_2->sprite, mob->leg_2->texture_left, 1);
        sfSprite_setTexture(mob->sprite, mob->texture_left, 1);
    }
}

void move_mob(ennemy_t *mob, main_t *main)
{
    sfVector2f pos = sfSprite_getPosition(mob->sprite);
    sfVector2f a = sfSprite_getPosition(MAP[10][mob->pos.x]->sprite);

    mob->pos.y = ((int)pos.y) / 64;
    if (a.x < pos.x - 64.00)
        mob->pos.x++;
    if (a.x > pos.x)
        mob->pos.x--;
    if (MAP[mob->pos.y + 1][mob->pos.x - 1]->type != 10 \
        || MOB_LEFT->type > 3 || MOB_LEFT->type < -3)
        mob->speed = 2;
    if (MAP[mob->pos.y + 1][mob->pos.x + 1]->type != 10 \
        || MOB_RIGHT->type > 3 || MOB_RIGHT->type < -3)
        mob->speed = -2;
    mob->vector.x = INTS->map_move.x + mob->speed;
    sfSprite_move(mob->sprite, mob->vector);
    move_member(mob, mob->vector.x - INTS->map_move.x);
    set_mob_rotation(mob, mob->vector, INTS->map_move.x);
    mob->hitbox.left = pos.x + mob->vector.x - 16;
    mob->hitbox.top = pos.y - 64;
}

void display_mobs(sfRenderWindow *window, mobs_l *tmp, main_t *main)
{
    while (tmp != NULL) {
        move_mob(tmp->data, main);
        sfRenderWindow_drawSprite(window, tmp->data->arm_2->sprite, NULL);
        sfRenderWindow_drawSprite(window, tmp->data->leg_2->sprite, NULL);
        sfRenderWindow_drawSprite(window, tmp->data->sprite, NULL);
        sfRenderWindow_drawSprite(window, tmp->data->leg_1->sprite, NULL);
        sfRenderWindow_drawSprite(window, tmp->data->arm_1->sprite, NULL);
        tmp = tmp->next;
    }
}
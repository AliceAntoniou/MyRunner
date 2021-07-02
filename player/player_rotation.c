/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** do player members rotation
*/

#include "../include/game.h"
#include "math.h"

void move_member(player_t *player, int move)
{
    sfVector2f pos = sfSprite_getPosition(player->sprite);

    pos.y -= 26;
    sfSprite_setPosition(f_ARM->sprite, pos);
    sfSprite_setPosition(SWORD->sprite, pos);
    sfSprite_setPosition(b_ARM->sprite, pos);
    pos.y += 50;
    sfSprite_setPosition(f_LEG->sprite, pos);
    sfSprite_setPosition(b_LEG->sprite, pos);
    f_ARM->rotation += 0.01 * move;
    b_ARM->rotation += 0.01 * move;
    f_LEG->rotation += 0.02 * move;
    b_LEG->rotation += 0.02 * move;
    sfSprite_setRotation(f_ARM->sprite, sinf(f_ARM->rotation) * 50);
    sfSprite_setRotation(b_ARM->sprite, sinf(b_ARM->rotation) * -50);
    sfSprite_setRotation(f_LEG->sprite, sinf(f_LEG->rotation) * 30);
    sfSprite_setRotation(b_LEG->sprite, sinf(b_LEG->rotation) * -30);
    sfSprite_setRotation(SWORD->sprite, sfSprite_getRotation(f_ARM->sprite));
}

static void right_rotation(player_t *player)
{
    sfVector2f origin = {12, 10};

    sfSprite_setTexture(f_ARM->sprite, f_ARM->texture_right, 1);
    sfSprite_setTexture(b_ARM->sprite, b_ARM->texture_right, 1);
    sfSprite_setTexture(f_LEG->sprite, f_LEG->texture_right, 1);
    sfSprite_setTexture(b_LEG->sprite, b_LEG->texture_right, 1);
    sfSprite_setTexture(SWORD->sprite, SWORD->texture_right, 1);
    sfSprite_setOrigin(SWORD->sprite, origin);
    sfSprite_setTexture(player->sprite, player->texture_right, 1);
    player->side = right;
}

void set_player_rotation(player_t *player, sfVector2f vector, int map)
{
    sfVector2f origin = {52, 10};

    if (vector.x - map > 1)
        right_rotation(player);
    if (vector.x - map < -1) {
        sfSprite_setTexture(f_ARM->sprite, f_ARM->texture_left, 1);
        sfSprite_setTexture(b_ARM->sprite, b_ARM->texture_left, 1);
        sfSprite_setTexture(f_LEG->sprite, f_LEG->texture_left, 1);
        sfSprite_setTexture(b_LEG->sprite, b_LEG->texture_left, 1);
        sfSprite_setTexture(SWORD->sprite, SWORD->texture_left, 1);
        sfSprite_setOrigin(SWORD->sprite, origin);
        sfSprite_setTexture(player->sprite, player->texture_left, 1);
        player->side = left;
    }
}
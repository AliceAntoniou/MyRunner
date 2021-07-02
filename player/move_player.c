/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** fonction which move the player
*/

#include "../include/game.h"

void set_player_rotation(player_t *player, sfVector2f vector, int map);

void move_member(player_t *player, int move);

static void set_spots_2(player_t *player, sfVector2f pos)
{
    player->spots[4]->pos.x = pos.x + 14;
    player->spots[4]->pos.y = pos.y + 65;
    player->spots[4]->direction = down;
    player->spots[5]->pos.x = pos.x - 14;
    player->spots[5]->pos.y = pos.y + 65;
    player->spots[5]->direction = down;
    player->spots[6]->pos.x = pos.x + 14;
    player->spots[6]->pos.y = pos.y - 65;
    player->spots[6]->direction = up;
    player->spots[7]->pos.x = pos.x - 14;
    player->spots[7]->pos.y = pos.y - 65;
    player->spots[7]->direction = up;
}

void set_spots(player_t *player)
{
    sfVector2f pos = sfSprite_getPosition(player->sprite);

    set_spots_2(player, pos);
    player->spots[0]->pos.x = pos.x + 16;
    player->spots[0]->pos.y = pos.y - 30;
    player->spots[0]->direction = right;
    player->spots[1]->pos.x = pos.x + 16;
    player->spots[1]->pos.y = pos.y + 30;
    player->spots[1]->direction = right;
    player->spots[2]->pos.x = pos.x - 16;
    player->spots[2]->pos.y = pos.y - 30;
    player->spots[2]->direction = left;
    player->spots[3]->pos.x = pos.x - 16;
    player->spots[3]->pos.y = pos.y + 30;
    player->spots[3]->direction = left;
}

void move_player(player_t *player, sfVector2f vector, int map)
{
    set_player_rotation(player, vector, map);
    sfSprite_move(player->sprite, vector);
    move_member(player, vector.x - map);
    set_spots(player);
}
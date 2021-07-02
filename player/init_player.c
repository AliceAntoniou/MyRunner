/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** init player
*/

#include "../include/game.h"

member_t *init_member(int x, int y)
{
    member_t *member = malloc(sizeof(member_t));
    sfIntRect rec1 = {x, y, 4, 12};
    sfIntRect rec2 = {x, y, 4, 12};
    sfVector2f scale = {4, 4};
    sfVector2f origin = {2, 2};

    if (member == NULL)
        return NULL;
    member->sprite = sfSprite_create();
    member->texture_right = sfTexture_createFromFile(
                    "textures/player.png", &rec1);
    member->texture_left = sfTexture_createFromFile(
                    "textures/player.png", &rec2);
    member->rotation = 0;
    sfSprite_setTexture(member->sprite, member->texture_right, 1);
    sfSprite_setScale(member->sprite, scale);
    sfSprite_setOrigin(member->sprite, origin);
    return member;
}

member_t *init_sword(void)
{
    member_t *sword = malloc(sizeof(member_t));
    sfIntRect rec = {0, 0, 64, 64};
    sfVector2f scale = {1, 1};
    sfVector2f origin = {128, 0};

    if (sword == NULL)
        return NULL;
    sword->sprite = sfSprite_create();
    sword->texture_right = sfTexture_createFromFile(
                    "textures/sword2.png", &rec);
    sword->texture_left = sfTexture_createFromFile(
                    "textures/sword.png", &rec);
    sword->rotation = right;
    sfSprite_setTexture(sword->sprite, sword->texture_right, 1);
    sfSprite_setScale(sword->sprite, scale);
    sfSprite_setOrigin(sword->sprite, origin);
    return sword;
}

static int set_up(player_t *player)
{
    sfIntRect rec1 = {0, 56, 8, 20};
    sfIntRect rec2 = {0, 88, 8, 20};

    player->arm_1 = init_member(8, 56);
    player->arm_2 = init_member(12, 56);
    player->leg_1 = init_member(8, 68);
    player->leg_2 = init_member(12, 68);
    player->sword = init_sword();
    player->texture_right = sfTexture_createFromFile(
                    "textures/player.png", &rec1);
    player->texture_left = sfTexture_createFromFile(
                    "textures/player.png", &rec2);
    player->invincibility = sfClock_create();
    player->sprite = sfSprite_create();
    for (size_t i = 0; i < 8; i++)
        player->spots[i] = malloc(sizeof(spot_t *));
    return 0;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfVector2f pos = {128, 128};
    sfVector2f scale = {4, 4};
    sfVector2f origin = {4, 16};

    if (player == NULL || set_up(player) == 84)
        return NULL;
    player->pos.x = 3;
    player->pos.y = 2;
    player->vector.x = 0;
    player->vector.y = 0;
    player->pv = 2;
    sfSprite_setTexture(player->sprite, player->texture_right, 1);
    sfSprite_setPosition(player->sprite, pos);
    sfSprite_setScale(player->sprite, scale);
    sfSprite_setOrigin(player->sprite, origin);
    return player;
}
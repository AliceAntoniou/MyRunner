/*
** EPITECH PROJECT, 2021
** my runner
** File description:
** create mob
*/

#include "../include/game.h"

member_t *init_member(int x, int y);

void add_mob(mobs_l **head, ennemy_t *data)
{
    mobs_l *node = malloc(sizeof(mobs_l));

    if (*head == NULL) {
        node->data = data;
        node->next = NULL;
        (*head) = node;
        return;
    }
    node->data = data;
    node->next = (*head);
    (*head) = node;
    return;
}

int delete_mob(mobs_l **start, int branch)
{
    mobs_l *actual = *start;
    mobs_l *to_link = *start;

    if (branch == 0) {
        *start = (*start)->next;
        free(actual->data);
        free(actual);
        return (0);
    }
    if ((to_link = to_link->next) != NULL)
        to_link = to_link->next;
    while (branch > 1 && to_link != NULL) {
        to_link = to_link->next;
        actual = actual->next;
        branch--;
    }
    free(actual->next->data);
    free(actual->next);
    actual->next = to_link;
    return (0);
}

void free_mobs(mobs_l **head)
{
    mobs_l *tmp;

    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp->data);
        free(tmp);
    }
}

static void not_spider(e_type type, int x, int y, ennemy_t *ennemy)
{
    sfIntRect rec1 = {type * 16, 0, 8, 20};
    sfIntRect rec2 = {type * 16, 32, 8, 20};
    sfFloatRect hitbox = {x * 64, (y - 1) * 64, 32, 128};

    ennemy->texture_right = sfTexture_createFromFile(
                    "textures/player.png", &rec1);
    ennemy->texture_left = sfTexture_createFromFile(
                    "textures/player.png", &rec2);
    ennemy->speed = -2;
    if (type != creeper) {
        ennemy->arm_2 = init_member(12, 0);
        ennemy->arm_1 = init_member(8, 0);
    }
    ennemy->leg_1 = init_member(8, 12);
    ennemy->leg_2 = init_member(12, 12);
    ennemy->hitbox = hitbox;
}

ennemy_t *init_ennemy(e_type type, int x, int y)
{
    ennemy_t *ennemy = malloc(sizeof(ennemy_t));
    sfVector2f startpos = {x * 64, y * 64};
    sfVector2f pos = {x, y};
    sfVector2f scale = {4, 4};
    sfVector2f origin = {4, 16};

    ennemy->type = type;
    ennemy->vector.x = 0;
    ennemy->vector.y = 0;
    ennemy->pos.x = x;
    ennemy->pos.y = y;
    ennemy->sprite = sfSprite_create();
    if (type < spider) {
        not_spider(type, x, y, ennemy);
    }
    sfSprite_setTexture(ennemy->sprite, ennemy->texture_right, 1);
    sfSprite_setPosition(ennemy->sprite, startpos);
    sfSprite_setScale(ennemy->sprite, scale);
    sfSprite_setOrigin(ennemy->sprite, origin);
    return ennemy;
}
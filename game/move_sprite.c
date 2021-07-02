/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** move sprites
*/

#include "../include/game.h"

void move_rect(sfSprite *sprite, int offset, int max_value)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.left += offset;
    if (rect.left > max_value) {
        rect.left = 0;
    }
    sfSprite_setTextureRect(sprite, rect);
}
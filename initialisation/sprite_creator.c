/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** sprites creator fonctions
*/

#include "../include/game.h"

sfSprite *create_background(void)
{
    sfIntRect cam_background = {0, 0, 1200, 900};
    sfTexture *background_t = sfTexture_createFromFile(
                    "textures/background.png", &cam_background);
    sfSprite *background_s = sfSprite_create();

    sfSprite_setTexture(background_s, background_t, 1);
    return (background_s);
}

sfSprite *create_scroling(void)
{
    sfIntRect cam_background = {0, 0, 1200, 540};
    sfVector2f pos = {3628, 190};
    sfTexture *background_t = sfTexture_createFromFile(
                    "textures/fond grotte.png", &cam_background);
    sfSprite *background_s = sfSprite_create();

    sfSprite_setTexture(background_s, background_t, 1);
    sfSprite_setPosition(background_s, pos);
    return (background_s);
}

sfSprite *create_totem(void)
{
    sfIntRect cam = {0, 0, 32, 32};
    sfVector2f origin = {16, 16};
    sfTexture *texture = sfTexture_createFromFile(
                    "textures/totem.png", &cam);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setOrigin(sprite, origin);
    sfSprite_setTexture(sprite, texture, 1);
    return (sprite);
}

sfSound *create_sound(char *soundfile)
{
    sfSoundBuffer *coin = sfSoundBuffer_createFromFile(soundfile);
    sfSound *coin_s = sfSound_create();

    sfSound_setBuffer(coin_s, coin);
    return (coin_s);
}

sfText *create_score(void)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("textures/minecraft.ttf");

    if (txt == NULL || font == NULL)
        return NULL;
    sfText_setFont(txt, font);
    sfText_setFillColor(txt, sfBlack);
    sfText_setColor(txt, sfWhite);
    sfText_setCharacterSize(txt, 30);
    return txt;
}
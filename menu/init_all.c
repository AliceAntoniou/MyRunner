/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** init sftexts
*/

#include "../include/menu.h"

sfText *create_title(void)
{
    sfText *title = sfText_create();
    sfFont *font = sfFont_createFromFile("textures/minecraft.ttf");
    sfVector2f pos = {240, 100};

    if (title == NULL || font == NULL)
        return NULL;
    sfText_setFont(title, font);
    sfText_setString(title, "MY RUNNER");
    sfText_setCharacterSize(title, 100);
    sfText_setColor(title, sfBlack);
    sfText_setPosition(title, pos);
    return title;
}

sfSprite *create_menu_background(char *filename)
{
    sfIntRect cam_background = {0, 0, 1200, 900};
    sfTexture *background_t = sfTexture_createFromFile(
                    filename, &cam_background);
    sfSprite *background_s = sfSprite_create();

    if (background_s == NULL || background_t == NULL)
        return NULL;
    sfSprite_setTexture(background_s, background_t, 1);
    return (background_s);
}

sfSprite *create_main_menu_buttons(void)
{
    sfIntRect cam_background = {0, 0, 128, 256};
    sfTexture *background_t = sfTexture_createFromFile(
                    "textures/main_menu.png", &cam_background);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {523.2, 370};
    sfVector2f size = {1.2, 1.2};

    if (sprite == NULL || background_t == NULL)
        return NULL;
    sfSprite_setTexture(sprite, background_t, 1);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, size);
    return (sprite);
}

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {1200, 769, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
                    "Runner", sfClose, NULL);
    sfVector2i mpos = {1440, 10};

    if (window == NULL)
        return NULL;
    sfRenderWindow_setPosition(window, mpos);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}

error init_menu(menu_t *menu)
{
    menu->background = create_menu_background("textures/fond_menu.png");
    menu->buttons = create_main_menu_buttons();
    menu->title = create_title();
    if (menu->background == NULL || menu->buttons == NULL ||
        menu->title == NULL)
        return menu_sprite_create;
    return no_error;
}
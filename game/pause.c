/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** create pauses sprites
*/

#include "../include/game.h"
#include "../include/menu.h"

static sfSprite *create_menu(void)
{
    sfIntRect cam_background = {0, 0, 128, 256};
    sfTexture *background_t = sfTexture_createFromFile(
                    "textures/pause_menu.png", &cam_background);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {523.2, 370};
    sfVector2f size = {1.2, 1.2};

    sfSprite_setTexture(sprite, background_t, 1);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, size);
    return (sprite);
}

sfSprite *create_pause_button(void)
{
    sfIntRect cam_pause = {0, 0, 64, 64};
    sfVector2f pos = {1136, 0};
    sfTexture *pause_t = sfTexture_createFromFile(
                    "textures/pause_button.png", &cam_pause);
    sfSprite *pause_s = sfSprite_create();

    sfSprite_setPosition(pause_s, pos);
    sfSprite_setTexture(pause_s, pause_t, 1);
    return (pause_s);
}

static int pause(sfRenderWindow *window, main_t *main)
{
    sfVector2i ipos = sfMouse_getPositionRenderWindow(window);
    sfRenderWindow_display(window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && UP_BUTTON)
        return (0);
    if (is_having_to_close(window, 1))
        return (0);
    if (sfMouse_isButtonPressed(sfMouseLeft) && MIDDLE_BUTTON) {
        main->win = 2;
        return (0);
    }
    return (1);
}

int is_having_to_pause(sfRenderWindow *window, main_t *main)
{
    sfVector2i ipos = sfMouse_getPositionRenderWindow(window);
    sfSprite *menu;

    if ((sfMouse_isButtonPressed(sfMouseLeft) && PAUSE_BUTTON)
                    || sfKeyboard_isKeyPressed(sfKeyP)) {
        menu = create_menu();
        sfRenderWindow_drawSprite(window, menu, NULL);
        sfRenderWindow_display(window);
        while (pause(window, main)) {}
        sfSprite_destroy(menu);
        my_wait(100000000);
    }
}
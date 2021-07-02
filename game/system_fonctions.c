/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** system fonctions
*/

#include "../include/menu.h"

int is_having_to_close(sfRenderWindow *window, int bool)
{
    sfEvent event;
    sfVector2i ipos = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
        if (bool == 1 && sfMouse_isButtonPressed(sfMouseLeft) && DOWN_BUTTON) {
            sfRenderWindow_close(window);
            return (1);
        }
    }
    return (0);
}
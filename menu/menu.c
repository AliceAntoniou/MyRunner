/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** menu
*/

#include "../include/menu.h"

int menu(void)
{
    menu_t menu;
    sfRenderWindow *window = create_window();
    sfVector2i ipos;

    if (window == NULL || init_menu(&menu) != no_error || \
        init_main_struct(&menu.main) != no_error)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        ipos = sfMouse_getPositionRenderWindow(window);
        is_having_to_close(window, 1);
        sfRenderWindow_drawSprite(window, menu.background, NULL);
        sfRenderWindow_drawText(window, menu.title, NULL);
        sfRenderWindow_drawSprite(window, menu.buttons, NULL);
        sfRenderWindow_display(window);
        if (sfMouse_isButtonPressed(sfMouseLeft) && UP_BUTTON)
            levels_selection(&menu, window);
        if (sfMouse_isButtonPressed(sfMouseLeft) && MIDDLE_BUTTON) {}
    }
    stop(&menu.main);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("------------------------------------------");
        my_putstr("\nMy Runner\n\n");
        my_putstr("Run on differents maps and don't die ;).\n");
        my_putstr("Controls are editable in options.\n");
        my_putstr("------------------------------------------\n");
        return 0;
    }
    if (ac != 1)
        return 84;
    return (menu());
}
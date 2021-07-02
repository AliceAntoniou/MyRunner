/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** choose levels
*/

#include "../include/menu.h"

int game(main_t *main, sfRenderWindow *window);

void column_1(menu_t *menu, sfVector2i ipos)
{
    sfIntRect rec = {0, 0, 64, 64};

    if (COMLUMN_1 && ipos.y > 171 && ipos.y < 252)
        load_2d_arr_from_file("levels/level_1.txt", m_MAP->textures, m_MAP);
    if (COMLUMN_1 && ipos.y > 326 && ipos.y < 406)
        load_2d_arr_from_file("levels/level_2.txt", m_MAP->textures, m_MAP);
    if (COMLUMN_1 && ipos.y > 497 && ipos.y < 577)
        load_2d_arr_from_file("levels/level_3.txt", m_MAP->textures, m_MAP);
    if (COMLUMN_1 && ipos.y > 668 && ipos.y < 742) {
        m_MAP->textures->block_1 = sfTexture_createFromFile(
                "textures/sandstone.png", &rec);
        m_MAP->textures->block_1_font = sfTexture_createFromFile(
                "textures/sandstone_font.png", &rec);
        m_MAP->textures->block_2 = sfTexture_createFromFile(
                "textures/sandstone_smooth_.png", &rec);
        load_2d_arr_from_file("levels/level_4.txt", m_MAP->textures, m_MAP);
    }
}

int get_level(menu_t *menu, sfRenderWindow *window, sfVector2i ipos)
{
    column_1(menu, ipos);
    if (m_MAP->map != NULL) {
        game(&menu->main, window);
        m_MAP = NULL;
        return 1;
    }
    return 0;
}

void levels_selection(menu_t *menu, sfRenderWindow *window)
{
    sfVector2i ipos;
    sfSprite *levels = create_menu_background("textures/levels.png");

    while (sfRenderWindow_isOpen(window)) {
        ipos = sfMouse_getPositionRenderWindow(window);
        is_having_to_close(window, 0);
        sfRenderWindow_drawSprite(window, menu->background, NULL);
        sfRenderWindow_drawSprite(window, levels, NULL);
        sfRenderWindow_display(window);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            if (get_level(menu, window, ipos))
                return;
    }
}
/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** menu
*/

#ifndef MENU
#define MENU

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include "globales_structures.h"

#define MENU_BUTTON_X       ipos.x > 523 && ipos.x < 677
#define UP_BUTTON           ipos.y > 372 && ipos.y < 449 && MENU_BUTTON_X
#define MIDDLE_BUTTON       ipos.y > 487 && ipos.y < 564 && MENU_BUTTON_X
#define DOWN_BUTTON         ipos.y > 602 && ipos.y < 679 && MENU_BUTTON_X
#define COMLUMN_1           ipos.x > 205 && ipos.x < 348
#define m_MAP               menu->main.map

typedef struct strucutr_master
{
    main_t main;
    sfSprite *background;
    sfSprite *buttons;
    sfText *title;
} menu_t;

error init_main_struct(main_t *main);
int stop(main_t *main);
sfSprite *create_background(void);
sfSprite *create_scroling(void);
int load_2d_arr_from_file(const char *filepath, \
const texture_t *textures, map_t *map);
map_t *init_map(void);
int is_having_to_close(sfRenderWindow *window, int bool);
sfText *create_title(void);
sfRenderWindow *create_window(void);
sfSprite *create_main_menu_buttons(void);
sfSprite *create_menu_background(char *filename);
void levels_selection(menu_t *menu, sfRenderWindow *window);
error init_menu(menu_t *menu);

#endif /* !menu */

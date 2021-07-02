/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** reset
*/

#include "../include/game.h"

player_t *init_player(void);

sprites_t *init_sprites(void);

void free_mobs(mobs_l **head);

void add_mob(mobs_l **head, ennemy_t *data);

void reset(main_t *main)
{
    sfVector2f pos = {-2, 0};
    free_mobs(&main->map->mobs);

    PLAYER = init_player();
    INTS->map_move = pos;
    INTS->score = 0;
    main->win = 0;
    main->sprites = init_sprites();
    for (int i = 0; i < main->map->size.y; i++) {
        for (int j = 0; j <= main->map->size.x; j++)
            if (MAP[i][j]->sprite != NULL) {
                pos.y = i * 64;
                pos.x = (j - 1) * 64;
                if (MAP[i][j]->type == -1)
                    add_mob(&main->map->mobs, init_ennemy(zombie, j, i));
                sfSprite_setPosition(MAP[i][j]->sprite, pos);
            }
    }
}
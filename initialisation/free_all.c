/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** free all structures
*/

#include "../include/game.h"

void clear_map(map_t *map)
{
    for (int i = 0; i < map->size.y; i++) {
        for (int j = 0; j < map->size.x; j++){
            if (map->map[i][j]->sprite != NULL)
                sfSprite_destroy(map->map[i][j]->sprite);
            free(map->map[i][j]);
        }
        free(map->map[i]);
    }
    map = NULL;
}

static void destroy_sounds(sound_t *sounds)
{
    sfMusic_stop(sounds->music);
    sfMusic_destroy(sounds->music);
    sfSound_stop(sounds->hurt);
    sfSound_destroy(sounds->hurt);
    sfSound_stop(sounds->piston);
    sfSound_destroy(sounds->piston);
    free(sounds);
}

static void destroy_sprites(sprites_t *sprites)
{
    sfSprite_destroy(sprites->scroling);
    sfSprite_destroy(sprites->background);
    free(sprites);
}

static void destroy_texts(txt_t *texts)
{
    free(texts);
}

int stop(main_t *main)
{
    main->ints->shift = 0;
    main->ints->state = 0;
    main->player->pos.x = 2;
    main->player->pos.y = 8;
    sfClock_destroy(main->ints->AB_clock);
    destroy_sounds(main->sounds);
    destroy_sprites(main->sprites);
    destroy_texts(main->texts);
    free(INTS);
}
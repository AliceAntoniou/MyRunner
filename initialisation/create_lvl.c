/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** lvl creation
*/

#include "../include/game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

tile_t *get_tile(char c, sfVector2f pos, \
    const texture_t *textures, mobs_l **mobs);

static tile_t ***malloc_array(char *str, \
const texture_t *textures, mobs_l **mobs)
{
    int x = count_x(str);
    int y = count_y(str);
    int k = 0;
    int i = 0;
    int j = 0;
    tile_t ***map =  malloc(sizeof(tile_t *) * (y + 2));

    while (i < y) {
        map[i] = malloc(sizeof(tile_t) * (x + 2));
        for (j = 0; j < x + 1; j++) {
            map[i][j] = get_tile(str[k], (sfVector2f) {j, i}, textures, mobs);
            k++;
        }
        map[i][j] = NULL;
        i++;
    }
    map[i] = NULL;
    return map;
}

int load_2d_arr_from_file(const char *filepath, \
        const texture_t *textures, map_t *map)
{
    int fd = open(filepath, O_RDONLY);
    char *str = 0;
    struct stat buf;

    stat(filepath, &buf);
    str = malloc(sizeof(char) * (buf.st_size + 1));
    while (read(fd, str, buf.st_size) < buf.st_size) {}
    str[buf.st_size] = '\0';
    close(fd);
    map->map = malloc_array(str, textures, &map->mobs);
    if (map->map == NULL)
        return 84;
    return 0;
}

texture_t *get_textures(void)
{
    texture_t *texture = malloc(sizeof(texture_t));
    sfIntRect rec = {0, 0, 64, 64};

    texture->block_1 = sfTexture_createFromFile("textures/stone.png", &rec);
    texture->block_1_font = sfTexture_createFromFile(
                "textures/stone_back.png", &rec);
    texture->block_2 = sfTexture_createFromFile("textures/plank.png", &rec);
    texture->end = sfTexture_createFromFile("textures/lvl_end.png", &rec);
    texture->hurting_block = sfTexture_createFromFile(
                "textures/cactus.png", &rec);
    texture->hurting_block_font = sfTexture_createFromFile(
                "textures/cactus_back.png", &rec);
    texture->lava = sfTexture_createFromFile("textures/lava.png", &rec);
    texture->slime = sfTexture_createFromFile("textures/slime.png", &rec);
    return texture;
}

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->textures = get_textures();
    map->map = NULL;
    map->mobs = NULL;
    map->size.x = 162;
    map->size.y = 13;
    return map;
}
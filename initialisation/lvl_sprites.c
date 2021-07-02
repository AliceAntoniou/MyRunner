/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** sprites for levels
*/

#include "../include/game.h"

void add_mob(mobs_l **head, ennemy_t *data);

static tile_t *create_tile(int x, int y, sfTexture *textures, int type)
{
    tile_t *tile = malloc(sizeof(tile_t));
    sfVector2f pos = {(x - 1) * 64, y * 64};
    sfIntRect rec = {0, 0, 64, 64};

    tile->sprite = sfSprite_create();
    if (textures != NULL) {
        tile->t_base = textures;
        tile->t_second = sfTexture_createFromFile(
                        "textures/stone_back.png", &rec);
        sfSprite_setTexture(tile->sprite, tile->t_base, 1);
    }
    sfSprite_setPosition(tile->sprite, pos);
    tile->type = type;
    if (type == 3 || type == 4 || type == -3 || type == -4) {
        tile->sound = create_sound("Sounds/piston.wav");
    }
    if (type == -3 || type == -4)
        tile->t_second = sfTexture_createFromFile(
                        "textures/cactus_back.png", &rec);
    return tile;
}

tile_t *get_tile_2(char c, sfVector2f pos, const texture_t *textures)
{
    switch (c) {
    case 'w':
        return create_tile(pos.x, pos.y, textures->lava, -7);
    case 'C':
        return create_tile(pos.x, pos.y, textures->hurting_block, -3);
    case 'D':
        return create_tile(pos.x, pos.y, textures->hurting_block, -4);
    case 'W':
        return create_tile(pos.x, pos.y, textures->end, 20);
    case 'P':
        return create_tile(pos.x, pos.y, textures->block_2, 10);
    default:
        return create_tile(pos.x, pos.y, NULL, 0);
    }
}

tile_t *get_tile(char c, sfVector2f pos,
    const texture_t *textures, mobs_l **mobs)
{
    switch (c) {
    case 'X':
        return create_tile(pos.x, pos.y, textures->block_1, 10);
    case 'x':
        return create_tile(pos.x, pos.y, textures->hurting_block, -10);
    case 'A':
        return create_tile(pos.x, pos.y, textures->block_1, 3);
    case 'B':
        return create_tile(pos.x, pos.y, textures->block_1, 4);
    case 'S':
        return create_tile(pos.x, pos.y, textures->slime, 11);
    case '.':
        return create_tile(pos.x, pos.y, textures->block_1_font, 0);
    case 'Z':
        add_mob(mobs, init_ennemy(zombie, pos.x, pos.y));
        return create_tile(pos.x, pos.y, textures->block_1_font, -1);
    default:
        return get_tile_2(c, pos, textures);
    }
}
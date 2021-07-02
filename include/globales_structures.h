/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** structures
*/

#ifndef GLOBALES_STRUCTURES
#define GLOBALES_STRUCTURES

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#define INTS        main->ints
#define PLAYER      main->player
#define MAP         main->map->map
#define SPRITES     main->sprites
#define SOUNDS      main->sounds

typedef enum errors_type
{
    no_error,
    player_malloc,
    sounds_malloc,
    sprites_malloc,
    texts_malloc,
    ints_malloc,
    menu_sprite_create,
    clock_create
} error;

typedef enum enemy_type
{
    zombie,
    creeper,
    skeleton,
    spider,
    silver_fish
} e_type;

typedef enum spot_directions
{
    left,
    right,
    down,
    up
} directions;

typedef struct spots_structure
{
    directions direction;
    sfVector2f pos;
} spot_t;

typedef struct map_tile_struct
{
    sfSprite *sprite;
    sfTexture *t_base;
    sfTexture *t_second;
    sfSound *sound;
    int type;
} tile_t;

typedef struct player_member
{
    sfSprite *sprite;
    sfTexture *texture_left;
    sfTexture *texture_right;
    float rotation;
} member_t;

typedef struct player_struct
{
    sfSprite *sprite;
    member_t *arm_1;
    member_t *arm_2;
    member_t *leg_1;
    member_t *leg_2;
    member_t *sword;
    sfTexture *texture_right;
    sfTexture *texture_left;
    sfVector2i pos;
    sfVector2f vector;
    spot_t *spots[8];
    directions side;
    int pv;
    sfClock *invincibility;
} player_t;

typedef struct enemy_struct
{
    e_type type;
    sfSound *sound;
    sfSprite *sprite;
    member_t *arm_1;
    member_t *arm_2;
    member_t *leg_1;
    member_t *leg_2;
    sfTexture *texture_right;
    sfTexture *texture_left;
    sfVector2i pos;
    sfVector2f vector;
    int speed;
    sfFloatRect hitbox;
    int pv;
} ennemy_t;

typedef struct textures_struct
{
    sfTexture *block_1;
    sfTexture *block_1_font;
    sfTexture *lava;
    sfTexture *block_2;
    sfTexture *slime;
    sfTexture *hurting_block;
    sfTexture *hurting_block_font;
    sfTexture *end;
} texture_t;

typedef struct list_all_mobs
{
    ennemy_t *data;
    struct list_all_mobs *next;
} mobs_l;

typedef struct map_struct
{
    texture_t *textures;
    tile_t ***map;
    mobs_l *mobs;
    sfVector2i size;
} map_t;

typedef struct all_sprites
{
    sfSprite *background;
    sfSprite *scroling;
    sfSprite *totem;
    sfSprite *pause;
} sprites_t;

typedef struct all_sound
{
    sfMusic *music;
    sfSound *hurt;
    sfSound *piston;
    sfSound *win;
    sfSound *earn_totem;
    sfSound *boss_die;
} sound_t;

typedef struct all_texts
{
    sfText *score;
} txt_t;

typedef struct ints_var_structures
{
    int state;
    int shift;
    int score;
    sfClock *AB_clock;
    sfVector2f map_move;
} ints_t;

typedef struct struc_structures
{
    player_t *player;
    map_t *map;
    sprites_t *sprites;
    txt_t *texts;
    sound_t *sounds;
    ints_t *ints;
    int win;
    sfClock *tick;
} main_t;

#endif /* !GLOBALES_STRUCTURES */

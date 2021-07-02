/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** init structs
*/

#include "../include/game.h"

sfText *create_score(void);

player_t *init_player(void);

sfSprite *create_totem(void);

sfSound *create_sound(char *soundfile);

map_t *init_map(void);

ints_t *init_ints(void)
{
    ints_t *ints = malloc(sizeof(ints_t));
    sfVector2f move = {-2, 0};

    if (ints == NULL)
        return NULL;
    ints->state = 3;
    ints->shift = 0;
    ints->score = 0;
    ints->map_move = move;
    ints->AB_clock = sfClock_create();
    if ((ints->AB_clock) == NULL)
        return NULL;
    return (ints);
}

static sound_t *init_sound(void)
{
    sound_t *sound = malloc(sizeof(sound_t));

    if (sound == NULL)
        return NULL;
    sound->music = sfMusic_createFromFile("Sounds/music.wav");
    sound->hurt = create_sound("Sounds/hurt.wav");
    sound->piston = create_sound("Sounds/piston.wav");
    sound->boss_die = create_sound("Sounds/dragon death.wav");
    sound->win = create_sound("Sounds/achivement.wav");
    sound->earn_totem = create_sound("Sounds/xp sound.wav");
    return (sound);
}

sprites_t *init_sprites(void)
{
    sprites_t *sprites = malloc(sizeof(sprites_t));

    if (sprites == NULL)
        return NULL;
    sprites->background = create_background();
    sprites->scroling = create_scroling();
    sprites->totem = create_totem();
    sprites->pause = create_pause_button();
    if (sprites->background == NULL || sprites->scroling == NULL || \
        sprites->totem == NULL || sprites->pause == NULL)
        return NULL;
    return (sprites);
}

static txt_t *init_txt(void)
{
    txt_t *txt = malloc(sizeof(txt_t));

    if (txt == NULL)
        return NULL;
    txt->score = create_score();
    if (txt->score == NULL)
        return NULL;
    return (txt);
}

error init_main_struct(main_t *main)
{
    main->map = init_map();
    main->player = init_player();
    main->ints = init_ints();
    main->sounds = init_sound();
    main->sprites = init_sprites();
    main->texts = init_txt();
    main->win = 0;
    if (main->player == NULL)
        return player_malloc;
    if (main->ints == NULL)
        return ints_malloc;
    if (main->sounds == NULL)
        return sounds_malloc;
    if (main->sprites == NULL)
        return sprites_malloc;
    if (main->texts == NULL)
        return texts_malloc;
    return no_error;
}
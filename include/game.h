/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** game
*/

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include "globales_structures.h"

#define MOB_LEFT            MAP[mob->pos.y][mob->pos.x - 1]
#define MOB_RIGHT           MAP[mob->pos.y][mob->pos.x + 1]
#define RIGHT_TILE          MAP[PLAYER->pos.y][PLAYER->pos.x + 1]
#define UPPER_RIGHT_TILE    MAP[PLAYER->pos.y - 2][PLAYER->pos.x + 1]
#define UPPER_TILE          MAP[PLAYER->pos.y - 2][PLAYER->pos.x]
#define ACTUAL_TILE         MAP[PLAYER->pos.y][PLAYER->pos.x]
#define ACTUAL_DOWN_TILE    MAP[PLAYER->pos.y][PLAYER->pos.x]
#define LOWER_TILE          MAP[PLAYER->pos.y + 1][PLAYER->pos.x]
#define LOWER_RIGHT_TILE    MAP[PLAYER->pos.y + 1][PLAYER->pos.x + 1]
#define TYPE                MAP[y][x]->type
#define f_ARM               player->arm_1
#define b_ARM               player->arm_2
#define f_LEG               player->leg_1
#define b_LEG               player->leg_2
#define SWORD               player->sword
#define HIT_BLOCK_X     tmp->pos.x > hitbox.x + 1 && tmp->pos.x < hitbox.x + 63
#define HIT_BLOCK_Y     tmp->pos.y > hitbox.y + 1 && tmp->pos.y < hitbox.y + 63
#define HIT_DH_BLOCK_Y  tmp->pos.y > hitbox.y + 20 && tmp->pos.y < hitbox.y + 63
#define HIT_UH_BLOCK_Y  tmp->pos.y > hitbox.y + 1 && tmp->pos.y < hitbox.y + 31
#define ABS(value) ((value < 0) ? (value * (-1)) : (value))
#define PAUSE_BUTTON    ipos.x > 1136 && ipos.x < 1200 && \
                        ipos.y < 64 && ipos.y > 0

error init_main_struct(main_t *main);
int is_having_to_close(sfRenderWindow *window, int bool);
sfSprite *create_background(void);
sfSprite *create_scroling(void);
sfSprite *create_pause_button(void);
void move_rect(sfSprite *, int offset, int max_value);
void map_display(main_t *main, sfRenderWindow *window);
void set_player_moves(main_t *main, map_t *map);
int stop(main_t *main);
void clear_map(map_t *map);
void reset(main_t *main);
void set_spots(player_t *player);
void player_moves(main_t *main, sfRenderWindow *window);
void move_player(player_t *player, sfVector2f vector, int map);
void hurt_player(main_t *main);
sfSound *create_sound(char *soundfile);
void AB_switch(main_t *main);
int is_having_to_pause(sfRenderWindow *window, main_t *main);
ennemy_t *init_ennemy(e_type type, int x, int y);
int delete_mob(mobs_l **start, int branch);

#endif /* !GAME_H_ */
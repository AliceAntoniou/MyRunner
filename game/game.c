/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** main fonctions
*/

#include "../include/game.h"

void display_mobs(sfRenderWindow *window, mobs_l *tmp, main_t *main);

void move_totem(main_t *main);

static void set_all_to_date(sfRenderWindow *window, main_t *main)
{
    sfVector2f move = {main->ints->map_move.x / 2, 0};
    sfVector2f score_pos = {600 - my_getlen(INTS->score) * 15, 0};

    sfText_setPosition(main->texts->score, score_pos);
    sfText_setString(main->texts->score, my_getstr(INTS->score));
    move_totem(main);
    if (sfTime_asSeconds(sfClock_getElapsedTime(PLAYER->invincibility)) > 0.5) {
        sfSprite_setColor(PLAYER->sprite, sfWhite);
        sfSprite_setColor(PLAYER->arm_1->sprite, sfWhite);
        sfSprite_setColor(PLAYER->arm_2->sprite, sfWhite);
        sfSprite_setColor(PLAYER->leg_1->sprite, sfWhite);
        sfSprite_setColor(PLAYER->leg_2->sprite, sfWhite);
    }
    sfSprite_move(SPRITES->scroling, move);
    player_moves(main, window);
}

static void display_all(sfRenderWindow *window, main_t *main)
{
    sfRenderWindow_drawSprite(window, SPRITES->background, NULL);
    sfRenderWindow_drawSprite(window, SPRITES->scroling, NULL);
    map_display(main, window);
    AB_switch(main);
    if (PLAYER->pv > 1)
        sfRenderWindow_drawSprite(window, SPRITES->totem, NULL);
    display_mobs(window, main->map->mobs, main);
    sfRenderWindow_drawSprite(window, main->player->arm_2->sprite, NULL);
    sfRenderWindow_drawSprite(window, main->player->leg_2->sprite, NULL);
    sfRenderWindow_drawSprite(window, main->player->sprite, NULL);
    sfRenderWindow_drawSprite(window, main->player->leg_1->sprite, NULL);
    sfRenderWindow_drawSprite(window, main->player->sword->sprite, NULL);
    sfRenderWindow_drawSprite(window, main->player->arm_1->sprite, NULL);
    sfRenderWindow_drawText(window, main->texts->score, NULL);
    sfRenderWindow_drawSprite(window, SPRITES->pause, NULL);
}

void setup_sounds(main_t *main)
{
    sfMusic_play(SOUNDS->music);
    sfMusic_setVolume(SOUNDS->music, 30);
    sfSound_setVolume(SOUNDS->hurt, 60);
    sfSound_setVolume(SOUNDS->piston, 30);
    sfSound_setVolume(SOUNDS->win, 20);
    sfMusic_setLoop(SOUNDS->music, 1);
}

void clocked_game(main_t *main, sfRenderWindow *window)
{
    sfInt32 ticks = sfTime_asMilliseconds(sfClock_getElapsedTime(main->tick));

    while (ticks > 17) {
        set_all_to_date(window, main);
        display_all(window, main);
        ticks -= 17;
        sfClock_restart(main->tick);
    }
}

int game(main_t *main, sfRenderWindow *window)
{
    main->tick = sfClock_create();
    setup_sounds(main);
    while (sfRenderWindow_isOpen(window) && main->win == 0) {
        clocked_game(main, window);
        is_having_to_close(window, 0);
        is_having_to_pause(window, main);
        sfRenderWindow_display(window);
        if (PLAYER->pv < 1)
            reset(main);
    }
    sfMusic_stop(SOUNDS->music);
    if (main->win == 1)
        sfSound_play(SOUNDS->win);
    reset(main);
    clear_map(main->map);
    return 1;
}
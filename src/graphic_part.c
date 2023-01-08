/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** graphic_part
*/

#include "../include/my_radar.h"

void update_value_sprite(list_pl *planes, list_to *towers)
{
    plane *planess = planes->first;
    tower *towerss = towers->first;
    int changed = 0;
    while (planess) {
        changed = 0;
        if (planess->hitbox_option == 1)
            changed = 1, planess->hitbox_option = 0;
        if (planess->hitbox_option == 0 && changed == 0)
            planess->hitbox_option = 1;
        planess = planess->next;
    }
    while (towerss) {
        changed = 0;
        if (towerss->hitbox_option == 1)
            changed = 1, towerss->hitbox_option = 0;
        if (towerss->hitbox_option == 0 && changed == 0)
            towerss->hitbox_option = 1;
        towerss = towerss->next;
    }
}

void update_value_hitbox(list_pl *planes, list_to *towers)
{
    plane *planess = planes->first;
    tower *towerss = towers->first;
    int changed = 0;
    while (planess) {
        changed = 0;
        if (planess->sprite_option == 1)
            changed = 1, planess->sprite_option = 0;
        if (planess->sprite_option == 0 && changed == 0)
            planess->sprite_option = 1;
        planess = planess->next;
    }
    while (towerss) {
        changed = 0;
        if (towerss->sprite_option == 1)
            changed = 1, towerss->sprite_option = 0;
        if (towerss->sprite_option == 0 && changed == 0)
            towerss->sprite_option = 1;
        towerss = towerss->next;
    }
}

int close_event(sfEvent event, sfRenderWindow *window,
list_pl *planes, list_to *towers)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
        update_value_sprite(planes, towers);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
        update_value_hitbox(planes, towers);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        return 1;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        return -1;
    return 0;
}

sfRenderWindow *window_init(void)
{
    int width = 1920, height = 1080;
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, "My Radar", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    return window;
}

void graphic_part(list_pl *plane_list, list_to *tower_list)
{
    sfRenderWindow *window = window_init();
    int *values = malloc(2 * sizeof(int));
    float secs, volume = 50;
    sfSprite *wall = wallpaper_init();
    sfEvent event;
    plane_sprites_init(plane_list), tower_sprites_init(tower_list);
    sfClock *clock = sfClock_create();
    sfText *timer = set_text(0);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            volume += close_event(event, window, plane_list, tower_list);
        sfTime time_elapsed = sfClock_getElapsedTime(clock);
        secs = sfTime_asSeconds(time_elapsed);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, wall, NULL);
        change_text(window, timer, secs);
        draw_planes(plane_list, window, tower_list, volume);
        values = key_display(window, tower_list, values);
        sfRenderWindow_display(window);
    }
}

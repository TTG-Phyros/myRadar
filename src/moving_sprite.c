/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** moving_sprite
*/

#include "../include/my_radar.h"

void check_if_finished(plane *ac_pl)
{
    sfVector2f pos = sfSprite_getPosition(ac_pl->pl_sp);
    int visible = 1;
    if (ac_pl->x_fin - ac_pl->x_dep >= 0 && (pos.x + 1) >= ac_pl->x_fin) {
        if (ac_pl->y_fin - ac_pl->y_dep >= 0 && (pos.y + 1) >= ac_pl->y_fin)
            visible = 0;
        if (ac_pl->y_fin - ac_pl->y_dep < 0 && (pos.y - 1) < ac_pl->y_fin)
            visible = 0;
    }
    if (ac_pl->x_fin - ac_pl->x_dep < 0 && (pos.x - 1) < ac_pl->x_fin) {
        if (ac_pl->y_fin - ac_pl->y_dep >= 0 && (pos.y + 1) >= ac_pl->y_fin)
            visible = 0;
        if (ac_pl->y_fin - ac_pl->y_dep < 0 && (pos.y - 1) < ac_pl->y_fin)
            visible = 0;
    }
    if (visible == 0) {
        ac_pl->sprite_option = -1;
        ac_pl->hitbox_option = -1;
    }
}

float *percentage_calc(plane *planes)
{
    float *percents = malloc(3 * sizeof(float));
    if (planes->rotation > 0 && planes->rotation < 90) {
        percents[0] = (planes->rotation * 100) / 90;
        percents[1] = 100 - percents[0];
    }
    if (planes->rotation <= 0 && planes->rotation >= -90) {
        percents[1] = (planes->rotation * 100) / 90;
        percents[0] = 100 + percents[1];
    }
    if (planes->rotation >= 90 && planes->rotation <= 180) {
        percents[0] = (((planes->rotation * 100) / 90) - 100) * -1;
        percents[1] = 100 + percents[0];
    }
    if (planes->rotation < -90 && planes->rotation > -180) {
        percents[0] = ((planes->rotation * 100) / 90) + 100;
        percents[1] = -100 - percents[0];
    }
    return percents;
}

void coords_change(plane *ac_pl)
{
    sfVector2f pos = sfSprite_getPosition(ac_pl->pl_sp);
    if (ac_pl->already_moved[0] >= 1) {
        pos.x += 1;
        ac_pl->already_moved[0] -= 1;
    }
    if (ac_pl->already_moved[1] >= 1) {
        pos.y += 1;
        ac_pl->already_moved[1] -= 1;
    }
    if (ac_pl->already_moved[0] <= -1) {
        pos.x -= 1;
        ac_pl->already_moved[0] += 1;
    }
    if (ac_pl->already_moved[1] <= 1) {
        pos.y -= 1;
        ac_pl->already_moved[1] += 1;
    }
    sfSprite_setPosition(ac_pl->pl_sp, pos);
}

void move_planes(plane *ac_pl, float sec)
{
    if (!ac_pl->ratio && ac_pl->rotation < 370) {
        ac_pl->ratio = percentage_calc(ac_pl);
        ac_pl->ratio[0] = (ac_pl->speed * (ac_pl->ratio[0] / 1000)) / 10;
        ac_pl->ratio[1] = (ac_pl->speed * (ac_pl->ratio[1] / 1000)) / 10;
        ac_pl->already_moved = malloc(3 * sizeof(float));
        ac_pl->already_moved[0] = ac_pl->ratio[0];
        ac_pl->already_moved[1] = ac_pl->ratio[1];
    } else if (ac_pl->rotation < 370 && sec >= ac_pl->delay) {
        ac_pl->already_moved[0] += ac_pl->ratio[0];
        ac_pl->already_moved[1] += ac_pl->ratio[1];
        coords_change(ac_pl);
    }
}

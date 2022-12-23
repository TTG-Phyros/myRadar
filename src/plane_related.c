/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** plane_list
*/

#include "../include/my_radar.h"

void plane_hitbox(plane *ac_plane)
{
    sfVector2f pos = sfSprite_getPosition(ac_plane->pl_sp);
    sfVector2f size;
    sfColor back_color = sfColor_fromRGBA(0, 255, 0, 75);
    size.x = 20;
    size.y = 20;
    float rota = sfSprite_getRotation(ac_plane->pl_sp);
    sfRectangleShape_setPosition(ac_plane->hitbox, pos);
    sfRectangleShape_setSize(ac_plane->hitbox, size);
    sfRectangleShape_setOutlineColor(ac_plane->hitbox, sfGreen);
    sfRectangleShape_setOutlineThickness(ac_plane->hitbox, 2);
    sfRectangleShape_setFillColor(ac_plane->hitbox, back_color);
    sfRectangleShape_setRotation(ac_plane->hitbox, rota);
}

void plane_orientation(plane *plane)
{
    float opposite = plane->y_fin - plane->y_dep;
    float adjacent = plane->x_fin - plane->x_dep;
    float hypotenuse = (adjacent * adjacent) + (opposite * opposite);
    hypotenuse = sqrt(hypotenuse);
    float angle = acos(adjacent / hypotenuse);
    angle *= (180 / M_PI);
    if (opposite < 0)
        angle *= -1;
    plane->rotation = angle;
    sfSprite_setRotation(plane->pl_sp, angle);
}

void draw_planes(list_pl *plane_list, sfRenderWindow *window)
{
    plane *f_plane = plane_list->first;
    while (f_plane) {
        plane_hitbox(f_plane);
        if (f_plane->rotation == 370)
            plane_orientation(f_plane);
        move_planes(f_plane);
        check_if_finished(f_plane);
        if (f_plane->sprite_option == 1) {
            sfRenderWindow_drawSprite(window, f_plane->pl_sp, NULL);
        }
        if (f_plane->hitbox_option == 1)
            sfRenderWindow_drawRectangleShape(window, f_plane->hitbox, NULL);
        f_plane = f_plane->next;
    }
}

list_pl *initialisation_plane(list_pl *list_plane)
{
    plane *planes = malloc(sizeof(*planes));
    planes->pl_sp = NULL;
    planes->hitbox = sfRectangleShape_create();
    planes->hitbox_option = -1;
    planes->sprite_option = -1;
    planes->rotation = 390;
    planes->ratio = NULL;
    planes->already_moved = NULL;
    planes->x_dep = -1;
    planes->y_dep = -1;
    planes->x_fin = -1;
    planes->y_fin = -1;
    planes->speed = -1;
    planes->delay = -1;
    planes->next = NULL;
    list_plane->first = planes;
    return list_plane;
}

void insertion_plane(list_pl *list_plane, char *line)
{
    plane *new = malloc(sizeof(*new));
    int *data = get_data_int(line);
    new->pl_sp = NULL;
    new->hitbox = sfRectangleShape_create();
    new->hitbox_option = 0;
    new->sprite_option = 1;
    new->rotation = 370;
    new->ratio = NULL;
    new->already_moved = NULL;
    new->x_dep = data[0];
    new->y_dep = data[1];
    new->x_fin = data[2];
    new->y_fin = data[3];
    new->speed = data[4];
    new->delay = data[5];
    new->next = list_plane->first;
    list_plane->first = new;
}

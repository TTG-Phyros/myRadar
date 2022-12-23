/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** tower_list
*/

#include "../include/my_radar.h"

void draw_radius(tower *ac_tower, sfRenderWindow *window)
{
    sfVector2u win_size = sfRenderWindow_getSize(window);
    if (win_size.y > win_size.x)
        win_size.x = win_size.y;
    float ac_radius = ac_tower->radius;
    float radius_to = (win_size.x * (ac_radius / 100)) / 2;
    int centre_x = ac_tower->x_dep + (77 / 2) - radius_to;
    int centre_y = ac_tower->y_dep + (103 / 2) - radius_to;
    sfVector2f pos;
    pos.x = centre_x, pos.y = centre_y;
    sfColor back_color = sfColor_fromRGBA(255, 0, 0, 75);
    sfCircleShape_setRadius(ac_tower->hitbox, radius_to);
    sfCircleShape_setOutlineColor(ac_tower->hitbox, sfRed);
    sfCircleShape_setOutlineThickness(ac_tower->hitbox, 5);
    sfCircleShape_setFillColor(ac_tower->hitbox, back_color);
    sfCircleShape_setPosition(ac_tower->hitbox, pos);
}

void draw_towers(list_to *tower_list, sfRenderWindow *window)
{
    tower *first_tower = tower_list->first;
    while (first_tower->x_dep != -1) {
        draw_radius(first_tower, window);
        if (first_tower->sprite_option == 1)
        sfRenderWindow_drawSprite(window, first_tower->to_sp, NULL);
        if (first_tower->hitbox_option == 1)
        sfRenderWindow_drawCircleShape(window, first_tower->hitbox, NULL);
        first_tower = first_tower->next;
    }
}

list_to *initialisation_tower(list_to *list_tower)
{
    tower *towers = malloc(sizeof(*towers));
    towers->to_sp = NULL;
    towers->hitbox = sfCircleShape_create();
    towers->hitbox_option = -1;
    towers->sprite_option = -1;
    towers->x_dep = -1;
    towers->y_dep = -1;
    towers->radius = -1;
    towers->next = NULL;
    list_tower->first = towers;
    return list_tower;
}

void insertion_tower(list_to *list_tower, char *line)
{
    tower *new = malloc(sizeof(*new));
    int *data = get_data_int(line);
    new->to_sp = NULL;
    new->hitbox = sfCircleShape_create();
    new->hitbox_option = 0;
    new->sprite_option = 1;
    new->x_dep = data[0];
    new->y_dep = data[1];
    new->radius = data[2];
    new->next = list_tower->first;
    list_tower->first = new;
    free(data);
}

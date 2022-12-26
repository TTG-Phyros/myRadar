/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** collision
*/

#include "../include/my_radar.h"

int check_tower(sfVector2f p_one, list_to *list_tower, int dim)
{
    float opposite, adjacent, hypotenuse, radius;
    tower *ac_tower = list_tower->first;
    while (ac_tower && ac_tower->radius != -1) {
        sfVector2f p_two = sfCircleShape_getPosition(ac_tower->hitbox);
        radius = ((dim / 2) * ac_tower->radius) / 100;
        opposite = (p_one.x + 20) - (p_two.x + radius);
        adjacent = (p_one.y + 20) - (p_two.y + radius);
        hypotenuse = (adjacent * adjacent) + (opposite * opposite);
        hypotenuse = sqrt(hypotenuse);
        if (hypotenuse <= radius)
            return 1;
        ac_tower = ac_tower->next;
    }
    return 0;
}

void check_collision_sec(sfVector2f p_one, plane *sec_plane, plane *f_plane)
{
    if (f_plane->sprite_option == -1 || sec_plane->sprite_option == -1)
        return;
    sfVector2f p_two = sfSprite_getPosition(sec_plane->pl_sp);
    int changed = 0;
    if (p_two.x >= p_one.x && p_two.x <= (p_one.x + 20)) {
        if (p_two.y >= p_one.y && p_two.y <= (p_one.y + 20))
            changed = 1;
        if ((p_two.y + 20) >= p_one.y && (p_two.y + 20) <= (p_one.y + 20))
            changed = 1;
    }
    if ((p_two.x + 20) >= p_one.x && (p_two.x + 20) <= (p_one.x + 20)) {
        if (p_two.y >= p_one.y && p_two.y <= (p_one.y + 20))
            changed = 1;
        if ((p_two.y + 20) >= p_one.y && (p_two.y + 20) <= (p_one.y + 20))
            changed = 1;
    }
    if (changed == 1) {
        sec_plane->hitbox_option = -1, sec_plane->sprite_option = -1;
        f_plane->hitbox_option = -1, f_plane->sprite_option = -1;
    }
}

void check_collision(list_pl *pl_l, list_to *li_to, sfRenderWindow *window)
{
    plane *first_plane = pl_l->first;
    int finished = 0;
    sfVector2u dim = sfRenderWindow_getSize(window);
    if (dim.x < dim.y)
        dim.x = dim.y;
    while (first_plane) {
        finished = 0;
        sfVector2f pos_one = sfSprite_getPosition(first_plane->pl_sp);
        plane *second_plane = first_plane->next;
        finished = check_tower(pos_one, li_to, dim.x);
        while (second_plane && finished == 0) {
            check_collision_sec(pos_one, second_plane, first_plane);
            second_plane = second_plane->next;
        }
        first_plane = first_plane->next;
    }
}

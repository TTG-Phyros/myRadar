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

sfVector2f check_rota(plane *ac_plane)
{
    sfVector2f pos = sfSprite_getPosition(ac_plane->pl_sp);
    if (ac_plane->rotation <= 0 && ac_plane->rotation >= -90)
        pos.y -= sqrt(800);
    if (ac_plane->rotation >= 90 && ac_plane->rotation <= 180)
        pos.x -= sqrt(800);
    if (ac_plane->rotation < -90 && ac_plane->rotation > -180) {
        pos.x -= sqrt(800);
        pos.y -= sqrt(800);
    }
    return pos;
}

int plz_not_f4(sfVector2f p_two)
{
    int corner = 1;
    if (p_two.y >= (1080 / 2))
        corner += 2;
    if (p_two.x >= (1920 / 2))
        corner += 1;
    return corner;
}

void check_collision_sec(plane *sec_plane, plane *f_plane,
                        int corner_o, float volume)
{
    if (f_plane->sprite_option == -1 || sec_plane->sprite_option == -1) return;
    sfVector2f p_two = check_rota(sec_plane), p_one = check_rota(f_plane);
    int chg = 0, la = sqrt(800), corner;
    corner = plz_not_f4(p_two);
    if (corner_o != corner) return;
    if (p_two.x >= p_one.x && p_two.x <= (p_one.x + la)) {
        if (p_two.y >= p_one.y && p_two.y <= (p_one.y + la)) chg = 1;
        if ((p_two.y + la) >= p_one.y && (p_two.y + la) <= (p_one.y + la))
            chg = 1;
    }
    if ((p_two.x + la) >= p_one.x && (p_two.x + la) <= (p_one.x + la)) {
        if (p_two.y >= p_one.y && p_two.y <= (p_one.y + la)) chg = 1;
        if ((p_two.y + la) >= p_one.y && (p_two.y + la) <= (p_one.y + la))
            chg = 1;
    }
    if (chg == 1) {
        music_play("./content/sound/explosion.ogg", volume);
        sec_plane->hitbox_option = -1, sec_plane->sprite_option = -1;
        f_plane->hitbox_option = -1, f_plane->sprite_option = -1;
    }
}

void check_collision(list_pl *pl_l, list_to *li_to,
                    sfRenderWindow *window, float volume)
{
    plane *first_plane = pl_l->first;
    int finished = 0, corner = 1;
    sfVector2u dim = sfRenderWindow_getSize(window);
    if (dim.x < dim.y)
        dim.x = dim.y;
    while (first_plane) {
        finished = 0, corner = 1;
        sfVector2f pos_one = sfSprite_getPosition(first_plane->pl_sp);
        if (pos_one.y > (1080 / 2))
            corner += 2;
        if (pos_one.x >= (1920 / 2))
            corner += 1;
        plane *second_plane = first_plane->next;
        finished = check_tower(pos_one, li_to, dim.x);
        while (second_plane && finished == 0) {
            check_collision_sec(second_plane, first_plane, corner, volume);
            second_plane = second_plane->next;
        }
        first_plane = first_plane->next;
    }
}

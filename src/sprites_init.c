/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** sprites_init
*/

#include "../include/my_radar.h"

sfSprite *set_ss(char *fp, int *pos_sp, int *dim_sp, float *scale_sp)
{
    sfTexture *texture_sprite;
    sfVector2f pos_sprite = {pos_sp[0], pos_sp[1]};
    sfVector2f pm_scale = {scale_sp[0], scale_sp[1]};
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    rect->left = dim_sp[0];
    rect->top = dim_sp[1];
    rect->width = dim_sp[2];
    rect->height = dim_sp[3];
    texture_sprite = sfTexture_createFromFile(fp, rect);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture_sprite, sfTrue);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_scale(sprite, pm_scale);
    return sprite;
}

void plane_sprites_init(list_pl *list_plane)
{
    plane *ac_plane = list_plane->first;
    while (ac_plane) {
        char *filepath = "./content/sprite_sheet_radar.png";
        int *pos_sp = malloc(3 * sizeof(int));
        int *dim_sp = malloc(5 * sizeof(int));
        float *scale_sp = malloc(3 * sizeof(float));
        pos_sp[0] = ac_plane->x_dep, pos_sp[1] = ac_plane->y_dep;
        scale_sp[0] = 0.07, scale_sp[1] = 0.07;
        dim_sp[0] = 385, dim_sp[1] = 0, dim_sp[2] = 290, dim_sp[3] = 275;
        sfSprite *my_plane = set_ss(filepath, pos_sp, dim_sp, scale_sp);
        ac_plane->pl_sp = my_plane;
        ac_plane = ac_plane->next;
    }
}

void tower_sprites_init(list_to *tower_list)
{
    tower *ac_tower = tower_list->first;
    while (ac_tower) {
        char *filepath = "./content/sprite_sheet_radar.png";
        int *pos_sp = malloc(2 * sizeof(int));
        int *dim_sp = malloc(4 * sizeof(int));
        float *scale_sp = malloc(2 * sizeof(float));
        pos_sp[0] = ac_tower->x_dep, pos_sp[1] = ac_tower->y_dep;
        scale_sp[0] = 0.2, scale_sp[1] = 0.2;
        dim_sp[0] = 0, dim_sp[1] = 0, dim_sp[2] = 385, dim_sp[3] = 515;
        sfSprite *my_tower = set_ss(filepath, pos_sp, dim_sp, scale_sp);
        ac_tower->to_sp = my_tower;
        ac_tower = ac_tower->next;
    }
}

sfSprite *wallpaper_init(void)
{
    sfTexture *wall_texture = sfTexture_createFromFile(wallpaper, NULL);
    sfSprite *wall = sfSprite_create();
    sfSprite_setTexture(wall, wall_texture, sfTrue);
    return wall;
}

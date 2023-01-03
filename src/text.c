/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** text
*/

#include "../include/my_radar.h"

sfText *set_text(float secs)
{
    int sec = secs;
    char *str = int_to_str(sec);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./content/upheavtt.ttf");
    sfVector2f pos, scale;
    pos.x = 1820;
    pos.y = 0;
    scale.x = 2;
    scale.y = 2;
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setScale(text, scale);
    return text;
}

sfText *text_set(int x, int y, int scal, sfColor color)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./content/upheavtt.ttf");
    sfVector2f pos, scale;
    pos.x = x;
    pos.y = y;
    scale.x = scal;
    scale.y = scal;
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setScale(text, scale);
    sfText_setColor(text, color);
    return text;
}

void change_text(sfRenderWindow *window, sfText *timer, float secs)
{
    int sec = secs;
    char *str = int_to_str(sec);
    sfText_setString(timer, str);
    sfRenderWindow_drawText(window, timer, NULL);
}

void key_on_off(char *state, list_to *tower_list, int hit_or_spr)
{
    if (state[0] == 'O' && state[1] == 'N' && !state[2]) {
        if (hit_or_spr == 0) {
            sfText_setString(tower_list->sec_of, "ON");
            sfText_setColor(tower_list->sec_of, sfGreen);
        }
        if (hit_or_spr == 1) {
            sfText_setString(tower_list->first_of, "ON");
            sfText_setColor(tower_list->first_of, sfGreen);
        }
    }
    if (state[0] == 'O' && state[1] == 'F' && state[2] == 'F' && !state[3]) {
        if (hit_or_spr == 0) {
            sfText_setString(tower_list->sec_of, "OFF");
            sfText_setColor(tower_list->sec_of, sfRed);
        }
        if (hit_or_spr == 1) {
            sfText_setString(tower_list->first_of, "OFF");
            sfText_setColor(tower_list->first_of, sfRed);
        }
    }
}

int *key_display(sfRenderWindow *window, list_to *tower_list, int *value)
{
    if (tower_list->first != NULL) {
        if (tower_list->first->hitbox_option == 1 && value[0] != 1)
            key_on_off("ON", tower_list, 0);
        if (tower_list->first->hitbox_option == 0 && value[0] != 0)
            key_on_off("OFF", tower_list, 0);
        if (tower_list->first->sprite_option == 1 && value[1] != 1)
            key_on_off("ON", tower_list, 1);
        if (tower_list->first->sprite_option == 0 && value[1] != 0)
            key_on_off("OFF", tower_list, 1);
    }
    value[0] = tower_list->first->hitbox_option;
    value[1] = tower_list->first->sprite_option;
    draw_towers(tower_list, window);
    sfRenderWindow_drawText(window, tower_list->base_text, NULL);
    sfRenderWindow_drawText(window, tower_list->first_of, NULL);
    sfRenderWindow_drawText(window, tower_list->sec_of, NULL);
    return value;
}

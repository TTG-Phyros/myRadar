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

sfText *change_text(sfText *text, float secs)
{
    int sec = secs;
    char *str = int_to_str(sec);
    sfText_setString(text, str);
    return text;
}

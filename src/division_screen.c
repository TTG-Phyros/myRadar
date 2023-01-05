/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** division_screen
*/

#include "../include/my_radar.h"

void screen_init(division *screen)
{
    screen->top_left = sfRectangleShape_create();
    screen->top_right = sfRectangleShape_create();
    screen->bottom_left = sfRectangleShape_create();
    screen->bottom_right = sfRectangleShape_create();
    int largeur = (1920 / 2), hauteur = (1080 / 2);
    sfVector2f size, pos;
    size.x = largeur, size.y = hauteur;
    sfRectangleShape_setSize(screen->top_left, size);
    sfRectangleShape_setSize(screen->top_right, size);
    sfRectangleShape_setSize(screen->bottom_left, size);
    sfRectangleShape_setSize(screen->bottom_right, size);
    pos.x = 0, pos.y = 0;
    sfRectangleShape_setPosition(screen->top_left, pos);
    pos.x = (1920 / 2), pos.y = 0;
    sfRectangleShape_setPosition(screen->top_right, pos);
    pos.x = 0, pos.y = (1080 / 2);
    sfRectangleShape_setPosition(screen->bottom_left, pos);
    pos.x = (1920 / 2), pos.y = (1080 / 2);
    sfRectangleShape_setPosition(screen->bottom_right, pos);
}

void draw_rect(sfRenderWindow *window)
{
    division *screen = malloc(sizeof(*screen));
    screen_init(screen);
    sfRectangleShape_setFillColor(screen->top_left, sfRed);
    sfRectangleShape_setFillColor(screen->top_right, sfBlue);
    sfRectangleShape_setFillColor(screen->bottom_left, sfGreen);
    sfRectangleShape_setFillColor(screen->bottom_right, sfYellow);
    sfRenderWindow_drawRectangleShape(window, screen->top_left, NULL);
    sfRenderWindow_drawRectangleShape(window, screen->top_right, NULL);
    sfRenderWindow_drawRectangleShape(window, screen->bottom_left, NULL);
    sfRenderWindow_drawRectangleShape(window, screen->bottom_right, NULL);
}

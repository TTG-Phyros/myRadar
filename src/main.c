/*
** EPITECH PROJECT, 2022
** my radar
** File description:
** main
*/

#include "../include/my_radar.h"

int my_radar(char **argv, list_pl *list_plane, list_to *list_tower)
{
    int nb_lines = data_grab(argv, list_plane, list_tower);
    return nb_lines;
}

int check_argc(int argc)
{
    if (argc > 2) {
        write(2, "This program only accept one argument", 38);
        return 84;
    }
    if (argc == 1) {
        write(2, "You must provide an argument (file path) to the program", 56);
        return 84;
    }
    return 0;
}

void free_node(list_pl *list_plane, list_to *list_tower)
{
    while (list_plane->first) {
        plane *ac_plane = list_plane->first;
        sfSprite_destroy(ac_plane->pl_sp);
        sfRectangleShape_destroy(ac_plane->hitbox);
        list_plane->first = ac_plane->next;
        free(ac_plane);
    }
    free(list_plane);
    while (list_tower->first) {
        tower *ac_tower = list_tower->first;
        sfSprite_destroy(ac_tower->to_sp);
        sfCircleShape_destroy(ac_tower->hitbox);
        list_tower->first = ac_tower->next;
        free(ac_tower);
    }
    free(list_tower);
}

int main(int argc, char **argv)
{
    list_pl *list_plane = malloc(sizeof(*list_plane));
    list_to *list_tower = malloc(sizeof(*list_tower));
    if (check_argc(argc) == 84)
        return 84;
    if (my_radar(argv, list_plane, list_tower) == -1) {
        write(2, "Error with file opening", 24);
        return 84;
    }
    graphic_part(list_plane, list_tower);
    free_node(list_plane, list_tower);
    return 0;
}

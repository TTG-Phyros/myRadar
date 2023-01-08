/*
** EPITECH PROJECT, 2022
** my radar
** File description:
** main
*/

#include "../include/my_radar.h"

int check_argc(int argc, char **av)
{
    if (argc == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 'g')
        return graphic_h_flag();
    if (argc == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        h_flag();
        return 1;
    }
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
    sfText_destroy(list_tower->base_text);
    sfText_destroy(list_tower->first_of);
    sfText_destroy(list_tower->sec_of);
    free(list_tower);
}

int main(int argc, char **argv)
{
    list_pl *list_plane = malloc(sizeof(*list_plane));
    list_to *list_tower = malloc(sizeof(*list_tower));
    list_tower->base_text = text_set(20, 20, 2, sfWhite);
    sfText_setString(list_tower->base_text, "Hitbox ('L') :\nSprite ('S') :");
    list_tower->sec_of = text_set(440, 20, 2, sfWhite);
    list_tower->first_of = text_set(440, 75, 2, sfWhite);
    int c_argc = check_argc(argc, argv);
    if (c_argc == 1)
        return 0;
    if (c_argc == 84)
        return 84;
    if (data_grab(argv, list_plane, list_tower) == -1 || c_argc == 85) {
        write(2, "Error with file opening", 24);
        return 84;
    }
    graphic_part(list_plane, list_tower);
    free_node(list_plane, list_tower);
    return 0;
}

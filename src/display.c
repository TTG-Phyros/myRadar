/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** display
*/

#include "../include/my_radar.h"

void display_plane(list_pl *list_plane)
{
    plane *actual = list_plane->first;
    printf("\nPlanes : \n");
    while (actual) {
        printf("%d | ", actual->x_dep);
        printf("%d | ", actual->y_dep);
        printf("%d | ", actual->x_fin);
        printf("%d | ", actual->y_fin);
        printf("%d | ", actual->speed);
        printf("%d -> ", actual->delay);
        actual = actual->next;
    }
    printf("NULL\n");
}

void display_tower(list_to *list_tower)
{
    tower *actual = list_tower->first;
    printf("\nTowers : \n");
    while (actual) {
        printf("%d | ", actual->x_dep);
        printf("%d | ", actual->y_dep);
        printf("%d -> ", actual->radius);
        actual = actual->next;
    }
    printf("NULL\n");
}

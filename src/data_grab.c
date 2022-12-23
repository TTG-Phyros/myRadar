/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** data_grab
*/

#include "../include/my_radar.h"

int compt_nb_lines(char **av)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int compt = 0;
    fp = fopen(av[1], "r");
    if (!fp)
        return -1;
    while ((read = getline(&line, &len, fp)) != -1)
        compt++;
    return compt;
}

void my_strcat(char *dest, char *src)
{
    int i = 0;
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

int file_to_array(int nb_lines, char **av, char **map)
{
    if (nb_lines == -1)
        return -1;
    char *line = NULL;
    FILE *fp = fopen(av[1], "r");
    size_t len = 0;
    ssize_t read;
    for (int point = 0; (read = getline(&line, &len, fp)) != -1; point++) {
        map[point] = malloc((read + 1) * sizeof(char));
        my_strcat(map[point], line);
    }
    return nb_lines;
}

int data_grab(char **argv, list_pl *list_plane, list_to *list_tower)
{
    int nb_lines = compt_nb_lines(argv);
    if (nb_lines == -1)
        return -1;
    char **map = malloc((nb_lines + 1) * sizeof(char *));
    file_to_array(nb_lines, argv, map);
    initialisation_plane(list_plane);
    initialisation_tower(list_tower);
    for (int i = 0; i < nb_lines; i++) {
        if (map[i][0] == 'A')
            insertion_plane(list_plane, map[i]);
        if (map[i][0] == 'T')
            insertion_tower(list_tower, map[i]);
    }
    free(map);
    return nb_lines;
}

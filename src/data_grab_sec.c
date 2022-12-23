/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** data_grab_sec
*/

#include "../include/my_radar.h"

int my_int_array_len(int *array)
{
    int i = 0;
    while (array[i] != '\0') {
        i++;
    }
    return i + 1;
}

int c_one_is_my_loved_one(int ac_num)
{
    int buff = 1;
    for (int j = 0; j < my_intlen(ac_num) - 1; j++)
        buff *= 10;
    return buff;
}

int *get_data_int(char *line)
{
    int space = 1, buffer;
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == ' ') space++;
    int ac_num = 0, *liste_nb = malloc(space * sizeof(int)), k = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] >= '0' && line[i] <= '9' && ac_num == 0)
            ac_num = line[i] - '0';
        if (line[i] >= '0' && line[i] <= '9' && ac_num != 0) {
            ac_num *= 10;
            ac_num += line[i] - '0';
        }
        if ((line[i] < '0' || line[i] > '9') && ac_num != 0) {
            buffer = ac_num % c_one_is_my_loved_one(ac_num);
            liste_nb[k] = buffer;
            k++, ac_num = 0;
        }
    }
    buffer = ac_num % c_one_is_my_loved_one(ac_num);
    liste_nb[k] = buffer;
    return liste_nb;
}

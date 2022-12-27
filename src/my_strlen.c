/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_strlen
*/

#include "../include/my_radar.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int my_intlen(int nb)
{
    int i = 0;
    while (nb > 0) {
        nb /= 10;
        i++;
    }
    return i;
}

int my_strcmp(char *str_o, char *str_t)
{
    int i = 0;
    for (; str_o[i] && str_t[i] && str_o[i] == str_t[i]; i++);
    if (i == my_strlen(str_o) && my_strlen(str_o) == my_strlen(str_t))
        return 0;
    return 1;
}

char *int_to_str(int nb)
{
    int len = my_intlen(nb);
    char *str = malloc((len + 1) * sizeof(char));
    int i = len - 1;
    while (nb > 0) {
        str[i] = (nb % 10) + '0';
        i--;
        nb /= 10;
    }
    str[len] = '\0';
    return str;
}

/*
** EPITECH PROJECT, 2020
** mini_fonction 
** File description:
** print map
*/

#include "match.h"

void get_arg_to_int(int *number, int *max, char **av)
{
    srand(time(NULL));
    *number = my_getnbr(av[1]);
    *max = my_getnbr(av[2]);
}

char **gen_map_fonc(int number)
{
    char **map = map_gen(number);
    stick(map, number);
    return (map);
}

void disp_map(char **map)
{
    for (int i = 0; map && map[i] != NULL; i++)
    {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

int check_char(char *str)
{
    int i;
    for ( i = 0; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\n')
            return (1);
    if (i == 0)
        return (1);
    return (0);
}
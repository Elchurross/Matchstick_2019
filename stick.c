/*
** EPITECH PROJECT, 2019
** match
** File description:
** stick
*/

#include "match.h"

int stick_count(char **map, int nb, int nbis)
{
    int count = 0;

    for (int x = 0; map[nb][x] != '\0'; x++)
        if (map[nb][x] == '|')
            count++;

    if (count >= nbis)
        return (0);
    else
        return (1);
}

int stick_counter(char **map)
{
    int count = 0;
    for(int nb = 0; map[nb] != NULL; nb++)
    for (int x = 0; map[nb][x] != '\0'; x++)
        if (map[nb][x] == '|')
            count++;

    return (count);
}
/*
** EPITECH PROJECT, 2019
** win or lose 
** File description:
** match
*/

#include "match.h"

int win_or_lose(char **map)
{
    int count = 0;
    for (int i = 0; map && map[i] != NULL; i++)
    {
        for (int x = 0; map[i][x] != '\0'; x++)
            if (map[i][x] == '|')
                count++;
    }
    if (count == 0)
        return (1);
    else
        return (0);
}

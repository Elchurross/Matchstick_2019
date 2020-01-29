/*
** EPITECH PROJECT, 2019
** match
** File description:
** map creator
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "match.h"

char **create_map(int size)
{
    char **map;
    int i;

    if (size && (map = malloc(sizeof(char *) * (size + 3))) == NULL)
        return (NULL);

    for (i = 0; i < (size + 2); i++)
    {
        if ((map[i] = malloc(sizeof(char) * (size * 2) + 3)) == NULL)
            return (NULL);
    }
    map[i] = NULL;
    return (map);
}

char **map_gen(int sz)
{
    char **map;
    int i = 0;

    map = create_map(sz);
    map[0] = star(map[0], (sz * 2) + 1);
    map[sz + 1] = star(map[sz + 1], (sz * 2) + 1);

    i = 1;
    while (i < (sz + 1))
    {
        map[i] = space(map[i], (sz * 2) + 1);
        map[i][0] = '*';
        map[i][(sz * 2)] = '*';
        i++;
    }
    return (map);
}
char **stick(char **map, int size)
{
    int x = 1;
    int i = 0;

    if (map[x] != NULL)
        while (x < (size + 1))
        {
            for (int y = (size - i); y <= (size + i); y++)
                map[x][y] = '|';
            i++;
            x++;
        }
    return (map);
}

my_t *file_struct(int number, my_t *my, char **map)
{
    my->val = 0;
    my->nb = 0;
    my->d = number * 2 - 1;
    my->nbis = 0;
    my->win = 0;
    my->playerturn = 0;
    my->map = map;
    return(my);
}

int main(int ac, char **av)
{
    int number;
    int max;
    ARRAY map = NULL;
    my_t my;

    if (ac != 3)
        return (84);
    get_arg_to_int(&number, &max, av);
    if (number <= 1 || number > 99 || number == 0 || max == 0)
        return (84);
    map = gen_map_fonc(number);
    disp_map(map);
    my_putchar('\n');
    file_struct(number, &my, map);
    return (printing_map(number, max, my));
}
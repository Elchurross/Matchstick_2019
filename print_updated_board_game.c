/*
** EPITECH PROJECT, 2020
** yolo
** File description:
** yolo
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <grp.h>
#include <dirent.h>
#include <errno.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}

char **create_map(int size)
{
    char **map;
    int i;

    if (size && (map = malloc(sizeof(char *) * (size + 3))) == NULL)
        return (NULL);

    for (i = 0; i < (size + 2); i++) {
        if ((map[i] = malloc(sizeof(char) * (size * 2) + 3)) == NULL)
            return (NULL);
    }
    map[i] = NULL;
    return (map);
}

char *star(char *tab, int size)
{
    int i;
    char star = '*';
    i = 0;
    while (size && star && tab && i < size) {
        tab[i] = star;
        i++;
    }
    tab[i] = '\0';
    return (tab);
}

char *space(char *tab, int size)
{
    int i;
    char star = ' ';
    i = 0;
    while (size && star && tab && i < size) {
        tab[i] = star;
        i++;
    }
    tab[i] = '\0';
    return (tab);
}

char **map_gen(int sz)
{
    char **map;
    int i;

    i = 0;
    map = create_map(sz);
    map[0] = star(map[0], (sz * 2) + 1);
    map[sz + 1] = star(map[sz + 1], (sz * 2) + 1);

    i = 1;
    while (i < (sz + 1)) {
        map[i] = space(map[i], (sz * 2) + 2);
        map[i][0] = '*';
        map[i][(sz * 2)] = '*';
        i++;
    }
    return (map);
}

char **stick(char **map, int size)
{
    int x;
    int i;

    x = 1;
    i = 0;
    if (map[x] != NULL) {
        while (x < (size + 1)) {
            for (int y = (size - i); y <= (size + i); y++)
                map[x][y] = '|';
            i++;
            x++;
        }
    }
    return (map);
}

char **print_updated_board_game(int line, int nb_matches)
{
    char **map;

    map = map_gen(4);
    map = stick(map,4);
    
    for(int i = 7; nb_matches != 0;  i--)
    {
        if(map[line][i] == '|') {
            map[line][i] = ' ';
            nb_matches--;
            }
    } 
    for (int i = 0; map && map[i] != NULL; i++)
    {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return(map);
}

int main(int ac, char **av)
{
    int line = atoi(av[1]);
    int nb_matches = atoi(av[2]);
    print_updated_board_game(line, nb_matches);
    return (0);
}

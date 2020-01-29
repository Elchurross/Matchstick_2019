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

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != '\0')
    {
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

    for (i = 0; i < (size + 2); i++)
    {
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
    while (size && star && tab && i < size)
    {
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
    while (size && star && tab && i < size)
    {
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
    while (i < (sz + 1))
    {
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
    if (map[x] != NULL)
    {
        while (x < (size + 1))
        {
            for (int y = (size - i); y <= (size + i); y++)
                map[x][y] = '|';
            i++;
            x++;
        }
    }
    return (map);
}

int line(void)
{
    char *cline;
    int line_nb;
    int bol = 1;
    cline = malloc(sizeof(char *) * 10);
    while (bol == 0)
    {
        bol = 1;
        my_putstr("Line: ");
        read(0, cline, 100);
        line_nb = atoi(cline);
        if (line_nb < 1 || line_nb > 4)
        {
            my_putstr("Error: this line is out of range");
            bol = 0;
        }
    }
    return (line_nb);
}

int matches(char **map, int nb_line)
{
    char *cmatches;
    int line_nb;
    int bol = 1;
    int nb = 0;
    cmatches = malloc(sizeof(char *) * 100000);
    while (bol == 0)
    {
        bol = 1;
        my_putstr("Matches: ");
        read(0, cmatches, 100);
        line_nb = atoi(cmatches);
        for (int lol = 0; map[nb_line][lol] != '\0'; lol++)
            if (map[nb_line][lol] == '|')
                nb++;
        if (line_nb <= 0)
        {
            my_putstr("Error: you have to remove at least one match");
            bol = 0;
        }
        else if (line_nb > nb)
        {
            my_putstr("Error: not enough matches on this line");
            bol = 0;
        }
    }
    return (line_nb);
}

void read_player_move_and_print_updated_board_game(void)
{
    char **map;
    map = map_gen(4);
    map = stick(map, 4);
    int nb_line = 0;
    int nb_matches = 0;
    int nb = 0;

    char *line = malloc(sizeof(char) * 10);
    char *match = malloc(sizeof(char) * 10);
    while (1)
    {
        my_putstr("Line: ");
        read(0, line, 100);
        nb_line = atoi(line);
        if (nb_line < 1 || nb_line > 4)
        {
            my_putstr("Error: this line is out of range\n");
            continue;
        }
        my_putstr("Matches: ");
        read(0, match, 100);
        nb_matches = atoi(match);
        for (int lol = 0; map[nb_line][lol] != '\0'; lol++)
            if (map[nb_line][lol] == '|')
                nb++;
        if (nb_matches <= 0)
        {
            my_putstr("Error: you have to remove at least one match\n");
            continue;
        }
        else if (nb_matches > nb)
        {
            my_putstr("Error: not enough matches on this line\n");
            continue;
        }
        printf("Player removed %d  match(es) from line %d\n", nb_matches, nb_line);
        for (int i = 7; nb_matches != 0; i--)
        {
            if (map[nb_line][i] == '|')
            {
                map[nb_line][i] = ' ';
                nb_matches--;
            }
        }
        for (int i = 0; map && map[i] != NULL; i++)
        {
            my_putstr(map[i]);
            my_putchar('\n');
        }
        nb = 0;
    }
}

int main(int ac, char **av)
{
    read_player_move_and_print_updated_board_game();
    return (0);
}

/*
** EPITECH PROJECT, 2019
** ia
** File description:
** match
*/

#include "match.h"

void disp_ia_print(int nbis, int nb)
{
    my_putstr("AI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(nbis);
    my_putstr(" match(es) from line ");
    my_put_nbr(nb);
    my_putchar('\n');

}

int ia(char **map, int number, int max, int id)
{
    int nb = (rand() % (number)) + 1;
    int nbis = (rand() % (max)) + 1;
    int d = number * 2 - 1;
    int val = stick_count(map, nb, nbis);

    while (val == 1) {
        nb = (rand() % (number)) + 1;
        nbis = (rand() % (max)) + 1;
        val = stick_count(map, nb, nbis);
    }
    for (; map[nb][d] == ' '; d--);
    for (; nbis != 0; d--, nbis--)
        map[nb][d] = ' ';
    d = number * 2 - 1;
    return (0);
}
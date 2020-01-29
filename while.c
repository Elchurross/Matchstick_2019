/*
** EPITECH PROJECT, 2019
** match
** File description:
** map
*/

#include "match.h"

int take_stick(int max)
{
    int ret_getline = 0;
    int verif = 0;
    size_t len = 0;
    STR match = malloc(sizeof(char *) * 100000);
    int nbis = 0;

    my_putstr("Matches: ");
    ret_getline = getline(&match, &len, stdin);
    verif = check_char(match);
    if (verif == 1 || ret_getline == -1) {
        if (ret_getline == -1)
            return (0);
        else {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (-1);
        }
    }
    nbis = my_getnbr(match);
    if (nbis > max || nbis == 0) {
        if (nbis == 0)
            my_putstr("Error: you have to remove at least one match\n");
        else {
            my_putstr("Error: you cannot remove more than ");
            my_put_nbr(max);
            my_putstr(" matches per turn\n");
        }
        return (-1);
    }
    return (nbis);
}

int take_line(int number)
{
    int ret_getline = 0;
    int verif = 0;
    size_t len = 0;
    int nb = 0;
    STR line = malloc(sizeof(char *) * 100000);

    my_putstr("Line: ");
    ret_getline = getline(&line, &len, stdin);
    verif = check_char(line);
    if (verif == 1 || ret_getline == -1) {
        if (ret_getline == -1)
            return (0);
        else {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (-1);
        }
    }
    nb = my_getnbr(line);
    if (nb > number || nb == 0) {
        my_putstr("Error: this line is out of range\n");
        return (-1);
    }
    return (nb);
}

void print_player_move(int nb, int nbis)
{
    my_putstr("Player removed ");
    my_put_nbr(nbis);
    my_putstr(" match(es) from line ");
    my_put_nbr(nb);
    my_putchar('\n');
}

int you_lost()
{
    my_putstr("You lost, too bad...\n");
    return (2);
}

int ia_lost()
{
    my_putstr("I lost... snif... but I'll get you next time!!\n");
    return (1);
}

int printing_map(int number, int max, my_t my)
{
    while (1)
    {
        (my.playerturn == 0) ? my_putstr("Your turn:\n"), my.playerturn++ : 0;
        my.nb = take_line(number);
        if (my.nb == -1)
            continue;
        if (my.nb == 0)
            return (0);
        my.nbis = take_stick(max);
        if (my.nbis == -1)
            continue;
        if (my.nbis == 0)
            return (0);
        my.val = stick_count(my.map, my.nb, my.nbis);
        if (my.val == 1) {
            my_putstr("Error: not enough matches on this line\n");
            continue;
        }
        print_player_move(my.nb, my.nbis);
        for (; (my.map[my.nb][my.d] == ' '); my.d--);
        for (; my.nbis != 0; --my.d, --my.nbis)
            my.map[my.nb][my.d] = ' ';
        my.d = number * 2 - 1;
        disp_map(my.map);
        my.win = win_or_lose(my.map);
        if (my.win == 1)
            return (you_lost());
        my_putchar('\n');
        if(stick_counter(my.map) < 25)
            my.map = monte_carlo(my.map, number, max);
        else 
            lost_move(my.map, number, max);
        my.playerturn = 0;
        my.win = win_or_lose(my.map);
        if (my.win == 1)
            return (ia_lost());
        my_putchar('\n');
    }
}
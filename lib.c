/*
** EPITECH PROJECT, 2019
** match
** File description:
** lib
*/

#include "match.h"

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

int my_getnbr(char *str)
{
    int nb;
    int isneg;
    int i;

    isneg = 1;
    nb = 0;
    i = 0;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            isneg = isneg * -1;
        i = i + 1;
    }
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i = i + 1;
        }
        else
            return (nb * isneg);
    }
    return (nb * isneg);
}

int my_put_nbr(int nb)
{
    int a;
    if (nb < 0)
    {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0)
    {
        if (nb >= 10)
        {
            a = (nb % 10);
            nb = (nb - a) / 10;
            my_put_nbr(nb);
            my_putchar(48 + a);
        }
        else
            my_putchar(48 + nb % 10);
    }
    return (0);
}

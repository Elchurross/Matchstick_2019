/*
** EPITECH PROJECT, 2019
** strdup
** File description:
** plain one string
*/

#include "match.h"

char *my_strdup(char *src)
{
    char *dest;
    int length;

    length = my_strlen(src);
    dest = malloc(length + 1);
    length = 0;
    while (src[length] != '\0') {
        dest[length] = src[length];
        length = length + 1;
    }
    dest[length] = '\0';
    return (dest);
}

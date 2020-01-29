/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** tick and space into char**
*/

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

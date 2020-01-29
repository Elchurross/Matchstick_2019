/*
** EPITECH PROJECT, 2020
** monte carlo test for ia
** File description:
** monte_carlo
*/

#include "match.h"

int **my_malloc_fonc(int **arg, int number)
{
    arg = malloc(sizeof(int *) * (number + 1));
    arg[number] = NULL;
    for (int ind = 0; ind < number; ind++)
        arg[ind] = malloc(sizeof(int) * 3);
    for (int j = 0; j < 2; j++)
            arg[0][j] = 0;
    return (arg);
}

int *ia_player(char **map, int number, int max)
{
    int nb = (rand() % (number)) + 1;
    int nbis = (rand() % (max)) + 1;
    int d = number * 2 - 1;
    int val = stick_count(map, nb, nbis);
    int *res = malloc(sizeof(int) * 2);

    while (val == 1) {
        nb = (rand() % (number)) + 1;
        nbis = (rand() % (max)) + 1;
        val = stick_count(map, nb, nbis);
    }
    res[1] = nbis;
    for (; map[nb][d] == ' '; d--);
    for (; nbis != 0; d--, nbis--)
        map[nb][d] = ' ';
    d = number * 2 - 1;
    res[0] = nb; 
    return (res);
}

int continue_game(char **map, int number, int max)
{
    if (win_or_lose(map) == 1)
        return (2);
    while (1)
    {
        ia(map, number, max, 1);
        if (win_or_lose(map) == 1)
            return (2);
        ia(map, number, max, 2);
        if (win_or_lose(map) == 1)
            return (1);
    }
    return (0);
}

int fill_parameter(int *mem, int bool, int bolor)
{
    static int ress[100][2];
    int final = 0;
    int comp = 0;
    if(bolor == 0)
        for(int z = 0; z < 100; z++) {
            ress[z][0] = 0;
            ress[z][1] = 0;
            }
    if(bool == 0) {
    ress[mem[0]][0] += 1;
    ress[mem[1]][1] += 1;
    }
    if(bool == 1){
        for(int i = 0; i != 100; i++)
            if(comp < ress[i][0]) {
                comp = ress[i][0];
                final = i;
                }
        return(final);
        }
    if(bool == 2){
        for(int i = 0; i != 100; i++)
            if(comp < ress[i][1]) {
                comp = ress[i][1];
                final =i;
                }
        return(final);
        }
    return(0);
}

char **function_cp(char **map, char**dup)
{
    for (int i = 0; map[i] != NULL; i++){
    free(dup[i]);
    dup[i] = my_strdup(map[i]);
    }
    return(dup);
}

char **ia_final_move(char **map,int number)
{
    int nb = fill_parameter( 0, 1, 1);
    int nbis = fill_parameter(0, 2, 1);
    int d = number * 2 - 1;
    disp_ia_print(nbis, nb);
    for (;map[nb][d] == ' '; d--);
    for (;nbis != 0; d--, nbis--)
        map[nb][d] = ' ';
    d = number * 2 - 1;
    for (int i = 0; map && map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return (0);
}
char **lost_move(char **map,int  number, int max)
{
    int nb;
    int nbis;
    int d = number * 2 - 1;
    int val = 0;

    nb = (rand() % (number)) + 1;
    nbis = (rand() % (max)) + 1;
    val = stick_count(map, nb, nbis);
    while (val == 1) {
        nb = (rand() % (number)) + 1;
        nbis = (rand() % (max)) + 1;
        val = stick_count(map, nb, nbis);
    }
    disp_ia_print(nbis, nb);
    for (;map[nb][d] == ' '; d--);
    for (;nbis != 0; d--, nbis--)
        map[nb][d] = ' ';
    d = number * 2 - 1;
    for (int i = 0; map && map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    return(map);
}
char** monte_carlo(char **map, int number, int max)
{
    int *mem;
    int bol = 0;
    ARRAY cp_map = NULL;
    int res_game = 0;
    int bolor = 0;
    cp_map = create_map(number);
    for (int nb_ite = 0; nb_ite != 50000; nb_ite++) {
        cp_map = function_cp(map, cp_map);
        mem = ia_player(cp_map, number, max);
        res_game = continue_game(cp_map, number, max);
        (res_game == 2) ? fill_parameter(mem, 0, bolor): 0;
        if(res_game == 2)
            bol++;
        bolor++;
    }
    if(bol == 0)
        lost_move(map, number, max);
    else 
        ia_final_move(map, number);
    return (map);
}
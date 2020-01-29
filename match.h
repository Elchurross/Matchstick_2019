/*
** EPITECH PROJECT, 2019
** match
** File description:
** .h
*/

/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** matchstick
*/
#ifndef MY_H_
# define MY_H_

# include <stdarg.h>
# include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define UNUSED __attribute__((unused))
#define CONST __attribute__((const))
#define VOID __attribute__((noreturn))
#define STR char *__attribute__((__cleanup__(destroy_str)))
#define ARRAY char **__attribute__((__cleanup__(destroy_array)))
#define INTAB int **__attribute__((__cleanup__(destroy_intab)))

typedef struct my_struc_s
{
    int val;
    int nb;
    int d;
    char **map;
    int nbis;
    int win;
    int playerturn;
} my_t;

void disp_map(char **map);
char *star(char *tab, int size);
char **stick(char **map, int size);
char *space(char *tab, int size);
void disp_ia_print(int nbis, int nb);
char **create_map(int size);
void my_putchar(char c);
char **monte_carlo(char **map, int number, int max);
void destroy_array(char ***array);
char **map_gen(int sz);
void destroy_intab(int ***int_array);
int my_getnbr(char *str);
int my_putstr(char const *str);
int printing_map(int number,int max, my_t my);
void destroy_str(char **str);
char *my_strdup(char *src);
int my_put_nbr(int nb);
int win_or_lose(char **map);
char **lost_move(char **map,int  number, int max);
int ia(char **map,int number, int max, int id);
int stick_count(char **map, int nb, int nbis);
int stick_counter(char **map);
int check_char(char *str);
char **gen_map_fonc(int number);
void get_arg_to_int(int *number, int *max, char **av);
int my_strlen(char const *str);


#endif 
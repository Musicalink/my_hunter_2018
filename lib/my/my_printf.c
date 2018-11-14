/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

flag_t *generate_flag(char flag, int (*func)(va_list ap))
{
    flag_t *flags = malloc(sizeof(flag_t));
    flags->flag = flag;
    flags->func = func;
    return (flags);
}

flag_t **generate_flag_list(void)
{
    flag_t **flags = malloc(sizeof(flag_t) * 12);
    flags[0] = generate_flag('c', &my_putchar_printf);
    flags[1] = generate_flag('s', &my_putstr_printf);
    flags[2] = generate_flag('i', &my_put_nbr);
    flags[3] = generate_flag('d', &my_put_nbr);
    flags[4] = generate_flag('S', &my_putspecstr);
    flags[5] = generate_flag('o', &my_putoctal);
    flags[6] = generate_flag('b', &my_putbinaryunsigned);
    flags[7] = generate_flag('%', &putpercent);
    flags[8] = generate_flag('u', &my_put_unbr);
    flags[9] = generate_flag('x', &my_put_min_hexa);
    flags[10] = generate_flag('X', &my_put_maj_hexa);
    flags[11] = generate_flag('p', &my_put_adress);
    flags[12] = NULL;
    return (flags);
}

void loop_hi(char *s, va_list ap, int i, flag_t **flags)
{
    int j = 0;

    for (int j = 0; flags[j] != NULL; j++) {
        if (s[i] == flags[j]->flag) {
            flags[j]->func(ap);
            break;
        }
    }
}

void my_printf(char *s, ...)
{
    va_list ap;
    flag_t **flags = generate_flag_list();

    va_start(ap, s);
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == '%') {
            i++;
            for (; s[i] == ' '; i++);
            loop_hi(s, ap, i, flags);
        } else
            my_putchar(s[i]);
    va_end(ap);
    for (int i = 0; flags[i] != NULL; i++)
        free(flags[i]);
    free(flags);
}
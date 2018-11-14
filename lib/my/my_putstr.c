/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    write(1, str, (size_t)(my_strlen(str)));
    return (0);
}

int my_putstr_printf(va_list ap)
{
    char *str = va_arg(ap, char *);

    write(1, str, (size_t)(my_strlen(str)));
    return (0);
}
/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

int my_putchar_printf(va_list ap)
{
    char c = (char)va_arg(ap, int);

    write(1, &c, 1);
    return (0);
}
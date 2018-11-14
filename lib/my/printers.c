/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include <stdlib.h>

int my_put_min_hexa(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *str = convert_unsigned_to_base(nb, 16);

    my_putstr(str);
    free(str);
    return (0);
}

int my_put_maj_hexa(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);
    char *str = convert_unsigned_to_base(nb, 16);

    my_putstr(my_strcapitalize(str));
    free(str);
    return (0);
}

int my_put_adress(va_list ap)
{
    char *str = va_arg(ap, char *);
    char *test = convert_unsigned_to_base((unsigned long)(str), 16);

    my_putstr("0x");
    my_putstr(test);
    free(test);
    return (0);
}
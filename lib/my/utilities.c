
/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"
#include "printf.h"

int my_putspecstr(va_list ap)
{
    char *str = va_arg(ap, char *);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_putstr(convert_to_base(str[i], 8));
        } else
            my_putchar(str[i]);
    }
    return (0);
}

int my_putbinaryunsigned(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);

    my_putstr(convert_unsigned_to_base(nb, 2));
}

int my_putoctal(va_list ap)
{
    int nb = va_arg(ap, int);

    my_putstr(convert_to_base(nb, 8));
    return (0);
}

int putpercent(va_list ap)
{
    my_putchar('%');
    return (0);
}
/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"

int my_put_nbr_loop(int nb)
{
    if (nb >= 0) {
        if (nb >= 10)
            my_put_nbr_loop(nb / 10);
        my_putchar((char)(nb % 10 + '0'));
    } else if (nb < 0) {
        if (nb == -2147483648) {
            my_put_nbr_loop(-2147);
            my_put_nbr_loop(483648);
            return (0);
        }
        my_putchar('-');
        my_put_nbr_loop(nb * -1);
    }
}

int my_put_nbr(va_list ap)
{
    int nb = va_arg(ap, int);
    my_put_nbr_loop(nb);
    return (0);
}

unsigned long my_put_unbr_loop(unsigned long nb)
{
    if (nb >= 0) {
        if (nb >= 10)
            my_put_unbr_loop(nb / 10);
        my_putchar((char)(nb % 10 + '0'));
    } else if (nb < 0) {
        if (nb == -2147483648) {
            my_put_unbr_loop(-2147);
            my_put_unbr_loop(483648);
            return (0);
        }
        my_putchar('-');
        my_put_unbr_loop(nb * -1);
    }
}

int my_put_unbr(va_list ap)
{
    unsigned long nb = va_arg(ap, unsigned long);
    my_put_unbr_loop(nb);
    return (0);
}

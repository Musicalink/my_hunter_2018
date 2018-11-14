/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include <stdio.h>
#include "my.h"
#include <stdlib.h>

char *convert_to_base(int i, int base)
{
    char *result = malloc(sizeof(char) * (my_intlen(i) * base));
    int count = 0;

    while (i != 0) {
        if (i % base < 10) {
            result[count] = (char)('0' + i % base);
        } else
            result[count] = (char)('a' + i % base - 10);
        i /= base;
        count++;
    }
    result[count] = '\0';
    return (my_revstr(result));
}

char *convert_unsigned_to_base(unsigned long i, int base)
{
    char *result = malloc(sizeof(char) * (my_intlen(i) * base));
    unsigned long count = 0;

    while (i != 0) {
        if (i % base < 10) {
            result[count] = (char)('0' + i % base);
        } else
            result[count] = (char)('a' + i % base - 10);
        i /= base;
        count++;
    }
    result[count] = '\0';
    return (my_revstr(result));
}
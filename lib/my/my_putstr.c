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
    return (write(1, str, my_strlen(str)));
}
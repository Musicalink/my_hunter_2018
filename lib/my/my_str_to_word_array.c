/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"
#include <stdlib.h>

char *duplicate_str(char *dest, char *src, int begin_value, int end_value)
{
    int i = 0;

    while (begin_value <= end_value && src[i] != '\0') {
        dest[i] = src[begin_value];
        begin_value++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int is_alphanumeric(char c)
{
    if (c == '.' || c == 'o')
        return (1);
    else if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int delimiter_counter(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (is_alphanumeric(str[i]) == 0)
            counter++;
    return (counter + 1);
}

char **my_str_to_word_array(char *str)
{
    int counter = delimiter_counter(str);
    char **tab = malloc(sizeof(char *) * (counter + 1));
    int i = 0;
    int begin_value = 0;
    int current = 0;

    for (current; current < counter && str[i] != '\0'; current++) {
        for (i; is_alphanumeric(str[i]) == 0 && str[i] != '\0'; i++);
        begin_value = i;
        for (i; is_alphanumeric(str[i]) == 1 && str[i] != '\0'; i++);
        tab[current] = malloc(sizeof(char) * (i + 1));
        tab[current] = duplicate_str(tab[current], str, begin_value, i - 1);
        if (str[i] != '\0')
            i++;
    }
    tab[current] = NULL;
    return (tab);
}
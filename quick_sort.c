/**
*
* Quick sort
* C file
*
* by Cherepanov Aleksei (PI-171)
*
* mrneumann888@gmail.com
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quick_sort.h"

int comparator(const void *a, const void *b)
{
    char *ta = *(char**)a;
    char *tb = *(char**)b;
    return strcmp(ta, tb);
}

void quick_sort(char **array, int number_of_strings)
{
    qsort(array, number_of_strings, sizeof(char*), comparator);
}

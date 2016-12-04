/**
*
* qsort by Cherepanov Aleksei (PI-171)
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quick_sort.h"

void quick_sort(char **array,int number_of_strings);
int comparator(const void *a, const void *b);

void quick_sort(char **array,int number_of_strings)
{
    qsort(array, number_of_strings, sizeof(char*), comparator); //вызываем сортировку
}

int comparator(const void *a, const void *b)   // функция сравнения элементов массива
{
    char *ta = *(char**)a;
    char *tb = *(char**)b;
    return strcmp(ta,tb);
}

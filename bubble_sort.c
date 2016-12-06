/**
*
* Bubble sort
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

#include "bubble_sort.h"

void bubble_sort(char **array, int length)
{
    int i;
    int j;

    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (strcmp(array[j], array[j + 1]) > 0)
            {
                char* swap_char = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap_char;
            }
        }
    }
}

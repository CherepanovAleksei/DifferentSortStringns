/**
*
* Insert sort
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

#include "insert_sort.h"

void insert_sort(char **array, int length)

{
    int i;
    int j = 0;

    for (i = 1; i < length; i++)
    {
        char*buff = array[i];
        j = i;

        while (j > 0 && strcmp(array[j - 1], buff) > 0)
        {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = buff;
    }

}

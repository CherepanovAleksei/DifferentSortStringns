/**
*
* insert_sort by Cherepanov Aleksei (PI-171)
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insert_sort.h"

void insert_sort(char **array, int length)

{
    int i;
    int j=0;

    for (i = 1; i < length; i++) //проходим по массиву
    {
        char*buff = array[i]; //выбираем строку
        j = i;
        while (j > 0 && strcmp(array[j-1],buff)>0) //сравниваем и сдвигаем
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = buff;  //ставим на нужное место
    }

}

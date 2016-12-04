#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bubble_sort.h"

void bubble_sort(char **array, int length)
{
    int i; //счётчик №1
    int j; //счетчик №2
    for (i = 0; i < length-1; i++)
    {
        for (j = 0; j < length-i-1; j++)
        {
            if (strcmp(array[j],array[j+1])>0)  //сравниваем
            {
                char* swap_char=array[j];  //меняем местами
                array[j]=array[j+1];
                array[j+1]=swap_char;
            }
        }
    }
}

/**
*
* merge_sort by Cherepanov Aleksei (PI-171)
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge_sort.h"

void merge_sort(char **array,int left, int right)
{
    if(left!=right) //проверяем, что работаем не с одной строкой
    {
        int middle = (left + right)/2;  //определяем серединный элемент

        merge_sort(array, left, middle);       //разделяем и сортируем левую часть
        merge_sort(array, middle + 1, right); //правую

        char **buffarray=malloc(sizeof(char*)*(right+1));  //память для массива-буфера
        int first_of_left=left; //начало левой части
        int first_of_right=middle+1;
        int counter;
        for(counter=left; counter<=right; counter++) //проходим от начала до конца
        {
            if (first_of_left <= middle && (first_of_right > right || strcmp(array[first_of_left],array[first_of_right]) < 0))
            {
                buffarray[counter]=array[first_of_left]; //кладем в буферный массив элемент из левой части, сдвигаем
                first_of_left++;
            }
            else
            {
                buffarray[counter]=array[first_of_right];  //кладем в буферный массив элемент из правой части, сдвигаем
                first_of_right++;
            }
        }
        for(counter=left; counter<=right; counter++)  //возвращаем из буферного масива в рабочий
        {
            array[counter]=buffarray[counter];
        }


        free(buffarray);
    }
}

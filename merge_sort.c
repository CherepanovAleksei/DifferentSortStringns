/**
*
* Merge sort
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

#include "merge_sort.h"

void merge_sort(char **array, int left, int right)
{
    if(left != right)
    {
        int middle = (left + right) / 2;
		
		//sort left and right half of input array
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
		
        char **buffarray = malloc(sizeof(char*) * (right + 1));
        int first_of_left = left;
        int first_of_right = middle + 1;
        int counter;
		
		//merge sort
        for(counter = left; counter <= right; counter++)
        {
            if (first_of_left <= middle && (first_of_right > right || strcmp(array[first_of_left], array[first_of_right]) < 0))
            {
                buffarray[counter] = array[first_of_left];
                first_of_left++;
            }

            else
            {
                buffarray[counter] = array[first_of_right];
                first_of_right++;
            }
        }

        for(counter = left; counter <= right; counter++)
        {
            array[counter] = buffarray[counter];
        }
		
        free(buffarray);
    }
}

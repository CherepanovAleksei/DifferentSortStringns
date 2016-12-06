/**
*
* Sort a very big number of very big strings with different algorithms
*
* by Cherepanov Aleksei (PI-171)
*
* mrneumann888@gmail.com
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "bubble_sort.h"
#include "insert_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("You should input \"Execucatable_file Number_of_strings Input_file.txt\"\n");
        exit(1);
    }

	//open file
    FILE *myfile;
    myfile = fopen (argv[2], "r");

    if (myfile == NULL)
    {
        printf("Cannot open file.\n");
        exit(1);
    }

	//check real number of strings in file
    int number_of_strings = atoi(argv[1]);
    int col = 0;
    char symbol = 'o';

    while (symbol != EOF)
    {
        symbol = fgetc(myfile);

        if (symbol == '\n')
        {
            col++;
        }
    }

    if (col  < number_of_strings)
    {
        number_of_strings = col;
    }

    rewind(myfile);
	
	//array of number of symbols in each string
    int *string_length = malloc(sizeof(int) * number_of_strings);
    int i = 0;
    int counter_of_char = 0;
    int counter = 0;

    while (counter < number_of_strings)
    {
        symbol = fgetc(myfile);
        counter_of_char++;

        if(symbol == '\n')
        {
            string_length[i] = counter_of_char;
            i++;
            counter_of_char = 0;
            counter++;
        }
    }

    rewind(myfile);
	
	//fill array of strings
    char **array = malloc(sizeof(char*)*number_of_strings);
    int number = 0;
    int k;

    while(number < number_of_strings)
    {
        array[number] = malloc(sizeof(char) * (string_length[number]));

        for(k = 0; k < string_length[number] - 1; k++)
        {
            array[number][k] = fgetc(myfile);
        }

        symbol = fgetc(myfile);
        array[number][k] = '\0';
        number++;
    }

    printf("Choose method of sort:\n1:bubble_sort\n2:insert_sort\n3:merge_sort\n4:quick_sort\n");
    scanf("%d", &k);

    switch( k )
    {
        case 1:
            bubble_sort(array, number_of_strings);
            break;

        case 2 :
            insert_sort(array, number_of_strings);
            break;

        case 3 :
            merge_sort(array, 0, number_of_strings - 1);
            break;

        case 4 :
            quick_sort(array, number_of_strings);
            break;
    }

	//output
    for(k = 0; k < number_of_strings; k++)
    {
        printf("%s\n", array[k]);
    }

	//free
    for(k = 0; k < number_of_strings; k++)
    {
        free(array[k]);
    }

    free(array);
    free(string_length);

    fclose(myfile);

    return 0;
}

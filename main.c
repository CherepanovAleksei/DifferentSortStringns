/**
*
* sort by Cherepanov Aleksei (PI-171)
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

    FILE *myfile;
    myfile = fopen (argv[2], "r");  //открываем файл
    if (myfile == NULL)
    {
        printf("Cannot open file.\n");  //проверяем наличие
        exit(1);
    }

    int number_of_strings=atoi(argv[1]);
    int col=0;  //реальное количество строк в файле
    char symbol='o';  //переменная для посимвольного считывания
    while (symbol!=EOF)
    {
        symbol=fgetc(myfile);
        if (symbol == '\n')  //считаем реальное количество строк в файле
        {
            col++;  //реальное количество строк в файле
        }
    }
    if (col  < number_of_strings)
    {
        number_of_strings = col;  //сравнение числа строк, которое получено в файле и которое есть на самом деле
    }

    rewind(myfile);  //"ставим курсор" в начало файла

    int *string_length=malloc(sizeof(int)*number_of_strings); // массив для длины каждый строки
    int i=0; //счетчик для строки
    int counter_of_char=0; //количество символов в строке
    int counter=0;
    while (counter < number_of_strings)
    {
        symbol=fgetc(myfile); //посимвольно считываем
        counter_of_char++; //считаем кол-во символов
        if(symbol == '\n')
        {
            string_length[i]=counter_of_char;  //заполняем массив количеством символов в строке
            i++;
            counter_of_char=0; //обнуляем счетчик символов
            counter++;
        }
    }

    rewind(myfile);  //"ставим курсор" в начало файла

    char **array=malloc(sizeof(char*)*number_of_strings);  //выделяем память для хранения строк
    int number=0;
    int k;
    while(number < number_of_strings)
    {
        array[number] = malloc(sizeof(char)*(string_length[number])); // индивидуально выделяем память для каждой строки
        for(k=0; k<string_length[number]-1; k++)
        {
            array[number][k]=fgetc(myfile); //посимвольно заполняем массив
        }
        symbol = fgetc(myfile); //считываем \n
        array[number][k]='\0'; //добавляем нулевой символ в конце
        number++;
    }

    printf("Choose method of sort:\n1:bubble_sort\n2:insert_sort\n3:merge_sort\n4:quick_sort\n");
    scanf("%d",&k);
    switch( k )
    {
        case 1:
            bubble_sort(array, number_of_strings);
            break;
        case 2 :
            insert_sort(array, number_of_strings);
            break;
        case 3 :
            merge_sort(array, 0, number_of_strings-1);
            break;
        case 4 :
            quick_sort(array, number_of_strings); //вызываем сортировку
            break;
    }


    for(k=0; k<number_of_strings; k++) //выводим отсортированный массив
    {
        printf("%s\n",array[k]);
    }


    for(k=0; k<number_of_strings; k++) //очищаем память
    {
        free(array[k]);
    }
    free(array);
    free(string_length);


    fclose(myfile);
    return 0;
}

/**
*
* merge_sort by Cherepanov Aleksei (PI-171)
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
        for(counter=left; counter<=right;counter++) //проходим от начала до конца
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
    }
}

int main()
{
    FILE *myfile;
    myfile = fopen ("input.txt", "r");  //открываем файл
    if (myfile == NULL)
    {
        printf("Cannot open file.\n");  //проверяем наличие
    }
    else  //основная программа
    {
        int number_of_strings;
        fscanf(myfile, "%d", &number_of_strings);  //объявляем и считываем количество строк
        rewind(myfile);  //"ставим курсор" в начало файла

        int col=0;  //реальное количество строк в файле
        char symbol;  //переменная для посимвольного считывания
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
            number_of_strings = col-1;  //сравнение числа строк, которое получено в файле и которое есть на самом деле
        }

        rewind(myfile);  //"ставим курсор" в начало файла

        while((symbol=fgetc(myfile))!='\n'); //пропускаем строку с колтчеством строк

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
        while((symbol=fgetc(myfile))!='\n'); //пропускаем строку с колтчеством строк

        char **array=malloc(sizeof(char*)*(number_of_strings));  //выделяем память для хранения строк
        int number=0;
        int k;
        while(number < number_of_strings)
        {
        	array[number] = malloc(sizeof(char)*(string_length[number])); // индивидуально выделяем память для каждой строки
         	for(k=0;k<string_length[number]-1;k++)
        	{
        		array[number][k]=fgetc(myfile); //посимвольно заполняем массив
        	}
        	symbol = fgetc(myfile); //считываем \n
        	array[number][k]='\0'; //добавляем нулевой символ в конце
       		number++;
        }

        merge_sort(array, 0, number_of_strings-1);
		
		for(k=0;k<number_of_strings;k++) //выводим отсортированный массив
		{
			printf("%s\n",array[k]); 
		}


		for(k=0;k<number_of_strings;k++) //очищаем память
		{
			free(array[k]);
		}
	
		free(string_length);
		free(array);
    }
    fclose(myfile);
    return 0;
}

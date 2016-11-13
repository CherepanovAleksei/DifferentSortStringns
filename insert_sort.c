/**
*
* insert_sort by Cherepanov Aleksei (PI-171)
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_sort(char **array, int length)

{
    int i;
    int j=0;

    for (i = 0;i < length-1; i++)  //проходим по массиву
    {
        char*buff = array[i]; //выбираем строку
        j = i;
        while (j > 0 && strcmp(array[j-1],buff)>0) //сравниваем и сдвигаем
        {
            array[j] = array[j-1];
            j = j - 1;
        }
        array[j] = buff;  //ставим на нужное место
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

        insert_sort(array, number_of_strings);

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

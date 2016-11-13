 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void bubble_sort(char **array, int length)

{
    int i;
    int j;
    for (i = 0; i < length-1; i++)
    {

        for (j = 0; j < length-i-1; j++)
        {
            if (strcmp(array[j],array[j+1])>0)
            {
                char* swap_char=array[j];
                array[j]=array[j+1];
                array[j+1]=swap_char;
            }
        }
     }
 }

void insert_sort(char **array, int length)

{
    int i;
    int j;

    for (i = 0;i < length-1; i++)
    {
        char*x = array[i];
        j = i;
        while (j > 0 && strcmp(array[j-1],x)>0)
        {
            array[j] = array[j-1];
            j = j - 1;
        }
        array[j] = x;
    }

}


int main()
{
    FILE *myfile;
    myfile = fopen ("input.txt", "r");
    if (myfile == NULL)
    {
        printf("Cannot open file.\n");
    }
    else
    {
        int number_of_strings;
        fscanf(myfile, "%d", &number_of_strings);
        rewind(myfile);

        int col=0;
        char symbol;
        while (symbol!=EOF)
        {
            symbol=fgetc(myfile);
            if (symbol == '\n')
            {
                col++;
            }

        }

        if (col  < number_of_strings)
        {
            number_of_strings = col-1;
        }

        rewind(myfile);

        while((symbol=fgetc(myfile))!='\n'); //пропускаем строку

        int *string_length=malloc(sizeof(int)*number_of_strings); // массив для длины каждый строки
        int i=0; //счетчик для строки
        int counter_of_char=0;
        int counter=0;
        while (counter < number_of_strings)
        {
            symbol=fgetc(myfile);
            counter_of_char++;
            if(symbol == '\n')
            {
                string_length[i]=counter_of_char;
                i++;
                counter_of_char=0;
                counter++;
            }
        }

        rewind(myfile);
        while((symbol=fgetc(myfile))!='\n'); // this is to skip the first line

        char **array=malloc(sizeof(char*)*(number_of_strings));
        int number=0;
        int k;
        while(number < number_of_strings)
        {

         array[number] = malloc(sizeof(char)*(string_length[number])); // allocating memory for a string
         for(k=0;k<string_length[number]-1;k++)
         { // filling the array (char by char)
          array[number][k]=fgetc(myfile);
         }
         symbol = fgetc(myfile); //считываем \n
         array[number][k]='\0';
         number++;
        }

        insert_sort(array, number_of_strings);

for(k=0;k<number_of_strings;k++)
{
    printf("%s\n",array[k]);
}


                for(k=0;k<number_of_strings;k++)
        {
        free(array[k]);
        }
    free(string_length);
    free(array);
    }
    fclose(myfile);
    return 0;
}

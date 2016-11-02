#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* merge_sort(char *up, char *down, unsigned int left, unsigned int right)
{
    if (left == right)
    {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = (unsigned int)((left + right) * 0.5);

    // разделяй и сортируй
    int *l_buff = merge_sort(up, down, left, middle);
    int *r_buff = merge_sort(up, down, middle + 1, right);

    // слияние двух отсортированных половин
    char *target = l_buff == up ? down : up;

    unsigned int width = right - left, l_cur = left, r_cur = middle + 1;
    unsigned int i;
    for (i = left; i <= right; i++)
    {
        if (l_cur <= middle && r_cur <= right)
        {
            if (sort(l_buff[l_cur],r_buff[r_cur])<0)
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= middle)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}





void swap(char *a,char *b)
{

    char* c="";
    printf("%s\n%s",*a,*b);
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
}



int sort(char*st1,char*st2)
{
    if (strcmp(st1,st2)>0)
    {
        return 1;
    }

   if (strcmp(st1,st2)<0)
    {
        return -1;
    }

    if (strcmp(st1,st2)==0)
    {
        return 0;
    }
}

int main()
{
    int j,num;
    char n[100][100]; //[элементов][строк]
    char m[100][100];
    char* up = n;
    char* down = m;
    FILE *myfile;
    myfile = fopen ("input.txt", "r");
    if (myfile == NULL)
    {
        printf("Cannot open file.\n");
    }
    else
    {
        fscanf(myfile, "%d", &num);
        for(j=1;j<=num;j++)
        {
            fscanf(myfile, "%s", &n[j]);
        }

        int*out=merge_sort(up, down,0 , num);

        for(j=0;j<num;j++)
        {
            printf("%s ",out[j]);
        }

    }
    fclose(myfile);

    return 0;
}

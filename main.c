#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a,char *b)
{

    char* c="";
    printf("%s\n%s",*a,*b);
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
}

void sort()
{
    
}

int main()
{
    int n,i;
    scanf("%d",&n);
    char string[1000][n];
    for(i=1;i<=n;i++)
    {
        scanf("%s",&string[i]);
    }
    swap(string[1], string[2]);
    //printf("%s\n%s",string[1],string[2]);



    printf("\n");
    system("pause");
    return 0;
}

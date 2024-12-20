#include <stdio.h>

int main()
{
    for(int i=0;i<=9;i++)
    {
        for(int k=0;k<0+i;k++)
        {
            printf(" ");
        }
        for(int j=0;j<=9-i;j++)
        {
            printf("*"); 
        }
        printf("\n");
    }


    return 0;
}
#include <stdio.h>

int main()
{
    for(int i=0;i<=4;i++)
    {
        for(int k=0;k<4-i;k++)
        {
            printf(" ");
        }
        for(int j=0;j<=2*i;j++)
        {
            printf("*"); 
        }
        printf("\n");
    }
    for(int i=0;i<=3;i++)
    {
        for(int k=0;k<1+i;k++)
        {
            printf(" ");
        }
        for(int j=0;j<=6-2*i;j++)
        {
            printf("*"); 
        }
        printf("\n");
    }


    return 0;
}
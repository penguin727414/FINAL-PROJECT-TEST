/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    for(int i=0;i<=9;i++)
    {
        for(int k=0;k<9-i;k++)
        {
            printf(" ");
        }
        for(int j=0;j<=0+i;j++)
        {
            printf("*"); 
        }
        printf("\n");
    }


    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fptr;
    char ch;
    int count = 0;

    // 正確使用 fopen_s，傳入 &fptr 作為第一個參數
    errno_t err = fopen_s(&fptr, "welcome.txt", "r");
    if (err == 0 && fptr != NULL)
    {
        while ((ch = getc(fptr)) != EOF)
        {
            printf("%c", ch);
            count++;
        }
        fclose(fptr);
        printf("\n\u7e3d\u5171\u6709%d\u500b\u5b57\u5143\n", count);
    }
    else
    {
        printf("\u6a94\u6848\u958b\u555f\u5931\u6557!!\n");
    }

    system("pause");
    return 0;
}

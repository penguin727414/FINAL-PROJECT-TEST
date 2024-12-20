#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fptr1 = NULL;
    FILE* fptr2 = NULL;
    char ch;
    errno_t err1, err2;

    // 開啟 welcome.txt 以讀取模式
    err1 = fopen_s(&fptr1, "welcome.txt", "r");
    // 開啟 output.txt 以寫入模式
    err2 = fopen_s(&fptr2, "output.txt", "w");

    if (err1 == 0 && err2 == 0 && fptr1 != NULL && fptr2 != NULL)
    {
        while ((ch = getc(fptr1)) != EOF)
            putc(ch, fptr2);
        fclose(fptr1);
        fclose(fptr2);
        printf("檔案轉換完成!!\n");
    }
    else
    {
        printf("檔案開啟失敗!!\n");
        if (err1 != 0)
            printf("無法開啟 welcome.txt，錯誤碼: %d\n", err1);
        if (err2 != 0)
            printf("無法開啟 output.txt，錯誤碼: %d\n", err2);
        perror("詳細錯誤資訊");
    }

    system("pause");
    return 0;
}

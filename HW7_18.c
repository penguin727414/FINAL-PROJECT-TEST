#include <stdio.h>
#include <stdlib.h>
#define MAX 80

int main(void)
{
    FILE* in = NULL, * out = NULL;
    int cnt;
    char str[100];

    // 修正 fopen_s 的用法
    if (fopen_s(&in, "welcome.txt", "r") != 0) {
        printf("無法開啟 welcome.txt！\n");
        return 1;
    }

    if (fopen_s(&out, "output.txt", "w") != 0) {
        printf("無法開啟 output.txt！\n");
        fclose(in); // 如果輸入檔案已經打開，先關閉它
        return 1;
    }

    // 讀取檔案並寫入
    while (fscanf_s(in, "%s", str, (unsigned)_countof(str)) != EOF) {
        fprintf(out, "%s\n", str);
    }

    fclose(in); // 關閉檔案
    fclose(out); // 關閉檔案
    system("pause");
    return 0;
}

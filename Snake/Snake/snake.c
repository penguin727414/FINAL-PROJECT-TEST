#include <stdio.h>
#include <conio.h> // 用於即時鍵盤輸入
#include <windows.h> // 用於清屏與延遲

#define WIDTH 20
#define HEIGHT 10

char grid[HEIGHT][WIDTH];
int snakeX = 5, snakeY = 5; // 蛇的初始位置
int foodX = 3, foodY = 10; // 食物的位置
char direction = 'w'; // 初始方向：w=上, s=下, a=左, d=右

// 初始化遊戲區域
void initializeGrid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                grid[i][j] = '#'; // 邊界
            }
            else {
                grid[i][j] = ' '; // 空白區域
            }
        }
    }
    grid[snakeY][snakeX] = 'O'; // 蛇頭
    grid[foodY][foodX] = '@';   // 食物
}

// 更新遊戲畫面
void updateGrid() {
    // 清空畫面，重新繪製蛇和食物
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            grid[i][j] = ' ';
        }
    }
    grid[snakeY][snakeX] = 'O'; // 蛇頭
    grid[foodY][foodX] = '@';   // 食物
}

// 繪製遊戲畫面
void drawGrid() {
    system("cls"); // 清屏
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// 處理玩家輸入
void handleInput() {
    if (_kbhit()) { // 檢查是否有按鍵輸入
        char key = _getch();
        if (key == 'w' || key == 's' || key == 'a' || key == 'd') {
            direction = key; // 更新方向
        }
    }
}

// 更新蛇的位置
void moveSnake() {
    switch (direction) {
    case 'w': snakeY--; break; // 向上
    case 's': snakeY++; break; // 向下
    case 'a': snakeX--; break; // 向左
    case 'd': snakeX++; break; // 向右
    }

    // 檢查碰到邊界（結束遊戲）
    if (snakeX <= 0 || snakeX >= WIDTH - 1 || snakeY <= 0 || snakeY >= HEIGHT - 1) {
        printf("Game Over! You hit the wall.\n");
        exit(0);
    }

    // 檢查是否吃到食物
    if (snakeX == foodX && snakeY == foodY) {
        printf("You ate the food!\n");
        // 隨機生成新的食物（暫時固定位置）
        foodX = (foodX + 5) % (WIDTH - 2) + 1;
        foodY = (foodY + 3) % (HEIGHT - 2) + 1;
    }
}

int main() {
    initializeGrid();
    while (1) {
        handleInput(); // 處理輸入
        moveSnake();   // 更新蛇的位置
        updateGrid();  // 更新畫面
        drawGrid();    // 繪製畫面
        Sleep(1000);    // 控制遊戲速度
    }
    return 0;
}

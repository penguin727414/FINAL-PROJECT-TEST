#include <stdio.h>
#include <conio.h> // �Ω�Y����L��J
#include <windows.h> // �Ω�M�̻P����

#define WIDTH 20
#define HEIGHT 10

char grid[HEIGHT][WIDTH];
int snakeX = 5, snakeY = 5; // �D����l��m
int foodX = 3, foodY = 10; // ��������m
char direction = 'w'; // ��l��V�Gw=�W, s=�U, a=��, d=�k

// ��l�ƹC���ϰ�
void initializeGrid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                grid[i][j] = '#'; // ���
            }
            else {
                grid[i][j] = ' '; // �ťհϰ�
            }
        }
    }
    grid[snakeY][snakeX] = 'O'; // �D�Y
    grid[foodY][foodX] = '@';   // ����
}

// ��s�C���e��
void updateGrid() {
    // �M�ŵe���A���sø�s�D�M����
    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            grid[i][j] = ' ';
        }
    }
    grid[snakeY][snakeX] = 'O'; // �D�Y
    grid[foodY][foodX] = '@';   // ����
}

// ø�s�C���e��
void drawGrid() {
    system("cls"); // �M��
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// �B�z���a��J
void handleInput() {
    if (_kbhit()) { // �ˬd�O�_�������J
        char key = _getch();
        if (key == 'w' || key == 's' || key == 'a' || key == 'd') {
            direction = key; // ��s��V
        }
    }
}

// ��s�D����m
void moveSnake() {
    switch (direction) {
    case 'w': snakeY--; break; // �V�W
    case 's': snakeY++; break; // �V�U
    case 'a': snakeX--; break; // �V��
    case 'd': snakeX++; break; // �V�k
    }

    // �ˬd�I����ɡ]�����C���^
    if (snakeX <= 0 || snakeX >= WIDTH - 1 || snakeY <= 0 || snakeY >= HEIGHT - 1) {
        printf("Game Over! You hit the wall.\n");
        exit(0);
    }

    // �ˬd�O�_�Y�쭹��
    if (snakeX == foodX && snakeY == foodY) {
        printf("You ate the food!\n");
        // �H���ͦ��s�������]�ȮɩT�w��m�^
        foodX = (foodX + 5) % (WIDTH - 2) + 1;
        foodY = (foodY + 3) % (HEIGHT - 2) + 1;
    }
}

int main() {
    initializeGrid();
    while (1) {
        handleInput(); // �B�z��J
        moveSnake();   // ��s�D����m
        updateGrid();  // ��s�e��
        drawGrid();    // ø�s�e��
        Sleep(1000);    // ����C���t��
    }
    return 0;
}

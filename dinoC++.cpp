#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 10
#define JUMP_HEIGHT 5

int gameOver;
int score;
int dinoX, dinoY;
int cactusX, cactusY;

void setup() {
    gameOver = 0;
    score = 0;
    dinoX = 6;
    dinoY = HEIGHT - 2;
    cactusX = WIDTH - 4;
    cactusY = HEIGHT - 2;
}

void draw() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == dinoY -1  && j == dinoX + 1)
                std::cout <<"R";
            else if (i == cactusY && j == cactusX)
                std::cout <<"+";
            else if (i == HEIGHT - 1) // Draw continuous ground line
                std::cout <<"_";
            else
                std::cout <<" ";
        }
        std::cout <<"\n";
    }
    std::cout << "\nScore: " << score << "\n";
}
void jump();

void input() {
    if (GetAsyncKeyState(VK_SPACE)) // Check space bar input
        jump();
}

void jump() {
    if (dinoY >= HEIGHT - JUMP_HEIGHT)
        dinoY -= JUMP_HEIGHT;
}

void update() {
    if (dinoY < HEIGHT - 1)
        dinoY++;
    cactusX--;
    if (cactusX <= 0) {
        cactusX = WIDTH - 5;
        score++;
    }
    if ((cactusX == dinoX + 1) && (cactusY == dinoY - 1))
        gameOver = 1;
}

int main() {
    setup();
    while (!gameOver) {
        draw();
        input();
        update();
        Sleep(100);
    }
    std::cout << "\nGame Over! Final Score: " << score << "\n";
    return 0;
}

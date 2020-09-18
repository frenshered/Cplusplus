﻿#include <iostream>
#include <conio.h>

bool gameOver;
const int width = 40;
const int height = 20;
int tailX[100], tailY[100];
int nTail;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, RIGHT, LEFT, UP, DOWN };
eDirection dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw() {
    system("cls");

    for (int i = 0; i < width + 1; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                std::cout << "#";
            }
            if (i == y && j == x) {
                std::cout << "0";
            }
            else if (i == fruitY && j == fruitX) {
                std::cout << "F";
            }
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        print = true;
                        std::cout << "o";
                    }
                }
                if (print == false) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 1; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    std::cout << "Score: " << score << std::endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case RIGHT:
        x++;
        break;
    case LEFT:
        x--;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    if (x >= width - 1) {
        x = 0;
    }
    else if (x < 0){
        x = width - 2;
    }

    if (y >= height) {
        y = 0;
    }
    else if (y < 0) {
        y = height- 1;
    }

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
        }
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}


int main() {
    Setup();
    while (gameOver == false) {
        Draw();
        Input();
        Logic();
    }
}

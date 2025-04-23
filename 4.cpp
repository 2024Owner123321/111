#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 10
#define HEIGHT 20

int board[HEIGHT][WIDTH] = { 0 };


int shapes[7][4][4] = {
    // I
    {
        {0,0,0,0},
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0}
    },
   
    {
        {1,0,0,0},
        {1,1,1,0},
        {0,0,0,0},
        {0,0,0,0}
    },
   
};


int checkCollision(int x, int y, int shape) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
           
            if (shapes[shape][i][j] && board[y + i][x + j]) {
                return 1;
            }
        }
    }
    return 0;
}


void rotate(int* shape) {
    int temp[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          
            temp[i][j] = shape[j][i];
        }
    }
    memcpy(shape, temp, sizeof(temp));
}


void clearLines() {
    for (int i = HEIGHT - 1; i >= 0; i--) {
        int lineFull = 1;
        for (int j = 0; j < WIDTH; j++) {
            if (!board[i][j]) {
                lineFull = 0;
                break;
            }
        }
        if (lineFull) {
            
            for (int k = i; k > 0; k--) {
                board[k] = board[k - 1];
            }
            i++; 
        }
    }
}

int main() {
   
    while (1) {
       
        Sleep(100);
    }
    return 0;
}
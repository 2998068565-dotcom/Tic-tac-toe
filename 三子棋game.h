#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//初始化棋盘
void initboard(char board[ROW][COL], int row, int col);

//展示棋盘
void displayboard(char board[ROW][COL], int row, int col);

//玩家下棋
void playermove(char board[ROW][COL], int row, int col);

//电脑下棋
void computermove(char board[ROW][COL], int row, int col);

//判断输赢
char win(char board[ROW][COL], int row, int col);


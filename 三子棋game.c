#define _CRT_SECURE_NO_WARNINGS
#include "三子棋game.h"


//初始化棋盘
void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


//展示棋盘
void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
			{
				printf(" %c |", board[i][j]);
			}
			else
				printf(" %c \n", board[i][j]);
		}
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}



//玩家下棋
void playermove(char board[ROW][COL], int row, int col)
{
	printf("玩家输入：\n");
	while (1)
	{
		int a = 0;
		int b = 0;
		scanf("%d %d", &a, &b);
		if (a <= 3 && a > 0 && b <= 3 && b > 0 && board[a - 1][b - 1] == ' ')
		{
			board[a - 1][b - 1] = '*';
			break;
		}
		else
		{
			printf("非法输入，重新输入：\n");
		}
	}
}


//电脑下棋
void computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑输入：\n");
	while (1)
	{
		int b = rand() % COL;
		int a = rand() % ROW;
		if (board[a][b] == ' ')
		{
			board[a][b] = '#';
			break;
		}
	}
}



//判断输赢
char win(char board[ROW][COL], int row, int col)
{
	//行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ' && board[i][0] == '*')
		{
			return '*';
		}
		else if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ' && board[i][0] == '#')
		{
			return '#';
		}
	}
	//列
	i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ' && board[0][i] == '*')
		{
			return '*';
		}
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ' && board[0][i] == '#')
		{
			return '#';
		}
	}
	//斜角
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ' && board[0][0] == '*')
	{
		return '*';
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ' && board[0][2] == '*')
	{
		return '*';
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ' && board[0][0] == '#')
	{
		return '#';
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ' && board[0][2] == '#')
	{
		return '#';
	}
	i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				count++;
			}
		}
	}
	if (count == 0)
	{
		return 'f';
	}
	return 'c';
}

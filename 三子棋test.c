#define _CRT_SECURE_NO_WARNINGS
#include "三子棋game.h"





void menu()
{
	printf("****************************************\n");
	printf("****************************************\n");
	printf("****************************************\n");
	printf("*************    1.Play    *************\n");
	printf("*************    2.Exit    *************\n");
	printf("****************************************\n");
	printf("****************************************\n");
}


void game()
{
	char ch = ' ';
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);
	displayboard(board,ROW,COL);
	while (1)
	{
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ch = win(board, ROW, COL);
		if (ch == '*')
		{
			printf("玩家胜利\n");
			break;
		}
		else if (ch == 'f')
		{
			printf("平局\n");
			break;
		}
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ch = win(board, ROW, COL);
		if (ch == '#')
		{
			printf("电脑胜利\n");
			break;
		}
		else if (ch == 'f')
		{
			printf("平局\n");
			break;
		}
	}
}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("是否游玩？(1/2):\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			input = 0;
			break;
		default:
			printf("非法输入\n");
		}
	} while (input);
	return 0;
}
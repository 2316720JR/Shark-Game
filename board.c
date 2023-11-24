#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define BOARDSTATUS_OK		1 
#define BOARDSTATUS_NOK		0

#define N_BOARD				15 //���� ĭ�� 15ĭ���� ���� 
#define N_COINPOS			12//�� 12ĭ�� ���� ��ġ 
#define MAX_COIN			4//�� ĭ�� ���� �� �ִ� �ִ� ���� 

#define MAX_SHARKSTEP		6
#define SHARK_INITPOS		-4

//���������� ���� �ʰ� static����(������������) 
static int board_status[N_BOARD]; //���� ����(�ļտ���) 
static int board_coin[N_BOARD]; //�� ��° ĭ�� ���� ���� ������ �ִ��� ���� 

static int board_sharkPosition; //����� ��ġ 

//�ʱ�ȭ 
int board_initBoard(void)
{
	int i;
	for (i=0;i<N_BOARD;i++)
	{
		int board_status[i] = BOARDSTATUS_OK; //�ļյ��� ���� ���·� �ʱ�ȭ 
		int board_coin[i] = 0; //���� 0�λ��·� �ʱ�ȭ 
	}
	
	board_status = SHARK_INITPOS;
	
	for (i=0;i<N_COINPOS;i++)
	{
		int flag = 0;//��� ������ ���� 
		while(flag == 0) //����� ������ �ִ��� �� 
		{
			int allocPos = rand()%N_BOARD; //0����14������ ���ڰ� ���� ��� 
			if(board_coin[allocPos] == 0)
			{
				board_coin[allocPos] = rand()%MAX_COIN + 1; 
				flag = 1; //����� �鸲 --> while�� ���������� �� 
			}
		}
	}
	
	return 0; 
}


void board_printBoardStatus(void)
{
	int i;
	
	printf("-------------------BOARD STATUS--------------------\n")
	for(i=0;i<N_BOARD,i++)
	{
		printf("|");
		if (board_status[i] == BOARDSTATUS_NOK) //i���� ����ĭ�� BOARDSTATUS_NOK�� ������ �ļ��̵� 
			printf("X");
		else
			printf("O");
	}
	printf("|\n");
	printf("---------------------------------------------------\n")
	
	return 0;
}


int board_getBoardCoin(int pos)
{
	int coin = board_coin[pos];
	board_coin[pos] = 0;
	return coin;
}

int board_stepShark(void)
{
	int step = rand()%MAX_SHARKSTEP + 1;
	int i;
	
	for (i=+1;i<shark_position+step;i++)
	{
		if(i >= 0 && i < N_BOARD) //���������� 
			board_status[i] = BOARDSTATUS_NOK;
	}
	
	shark_position += step;
	
	return Shark_position;
}


int board_getBoardStatus(int pos) //Ư�� ��ġ�� �ļտ��θ� �˾ƾ� �ϹǷ� 
{
	return board_status[pos];
}


int board_getSharkPosition(void);
int board_stepShark(void); //�˾Ƽ� �̵��ϸ� �ǹǷ� �Է��� ���� �ʿ� ����

//���� ĭ ����(�ļ� ����, �÷��̾� ���� ����)
 

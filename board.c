#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define BOARDSTATUS_OK		1 
#define BOARDSTATUS_NOK		0

#define N_BOARD				15 //보드 칸을 15칸으로 정의 
#define N_COINPOS			12//총 12칸에 코인 배치 
#define MAX_COIN			4//한 칸당 놓을 수 있는 최대 코인 

#define MAX_SHARKSTEP		6
#define SHARK_INITPOS		-4

//전역변수가 되지 않게 static설정(나만쓸꺼ㅇㅇ) 
static int board_status[N_BOARD]; //보드 상태(파손여부) 
static int board_coin[N_BOARD]; //몇 번째 칸이 동전 몇을 가지고 있는지 저장 

static int board_sharkPosition; //상어의 위치 

//초기화 
int board_initBoard(void)
{
	int i;
	for (i=0;i<N_BOARD;i++)
	{
		int board_status[i] = BOARDSTATUS_OK; //파손되지 않은 상태로 초기화 
		int board_coin[i] = 0; //코인 0인상태로 초기화 
	}
	
	board_status = SHARK_INITPOS;
	
	for (i=0;i<N_COINPOS;i++)
	{
		int flag = 0;//깃발 내려가 있음 
		while(flag == 0) //깃발이 내려가 있는지 봄 
		{
			int allocPos = rand()%N_BOARD; //0부터14사이의 숫자가 랜덤 출력 
			if(board_coin[allocPos] == 0)
			{
				board_coin[allocPos] = rand()%MAX_COIN + 1; 
				flag = 1; //깃발이 들림 --> while문 빠져나가게 함 
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
		if (board_status[i] == BOARDSTATUS_NOK) //i번쨰 보드칸이 BOARDSTATUS_NOK와 같으면 파손이됨 
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
		if(i >= 0 && i < N_BOARD) //상어범위제한 
			board_status[i] = BOARDSTATUS_NOK;
	}
	
	shark_position += step;
	
	return Shark_position;
}


int board_getBoardStatus(int pos) //특정 위치의 파손여부를 알아야 하므로 
{
	return board_status[pos];
}


int board_getSharkPosition(void);
int board_stepShark(void); //알아서 이동하면 되므로 입력이 따로 필요 없음

//보드 칸 저장(파손 여부, 플레이어 생존 여부)
 

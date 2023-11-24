#define BOARDSTATUS_OK		1 
#define BOARDSTATUS_NOK		0

#define N_BOARD				15 //���� ĭ�� 15ĭ���� ���� 
#define N_COINPOS			12//�� 12ĭ�� ���� ��ġ 
#define MAX_COIN			4//�� ĭ�� ���� �� �ִ� �ִ� ���� 

//�ܺο� ������Ѿ� �� ��Ҵ� ����� 
int board_initBoard(void);
int board_printBoardStatus(void);
int board_getBoardCoin(int pos);
int board_getBoardStatus(int pos);

int board_getSharkPosition(void);
int board_stepShark(void);


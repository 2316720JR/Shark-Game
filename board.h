#define N_BOARD				15 //보드 칸을 15칸으로 정의 

#define BOARDSTATUS_OK		1 
#define BOARDSTATUS_NOK		0



//외부에 노출시켜야 할 요소는 헤더에 
int board_initBoard(void);
int board_printBoardStatus(void);

int board_getBoardCoin(int pos);
int board_getBoardStatus(int pos);

int board_getSharkPosition(void);
int board_stepShark(void);


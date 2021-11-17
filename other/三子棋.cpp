#include<stdio.h>//三子棋
#include<windows.h>
#pragma warning(disable:4996)
#include<time.h>
#define MAX_ROW 3
#define MAX_COL 3
//1.首先打印棋盘(并让棋盘初始化)
//2.玩家落子
//3.判定胜负
//4.电脑落子
//5.判定胜负
void Init(char ChessBoard[MAX_ROW][MAX_COL]){// 把数组中的每个元素都设为 空格
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){ 
			ChessBoard[row][col] = ' ';
		}
	}
	
}
void PrintChessBoard(char ChessBoard[MAX_ROW][MAX_COL]){//打印棋盘
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("|  %c|  %c|  %c|\n", ChessBoard[row][0], ChessBoard[row][1], ChessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}
void playerMove(char ChessBoard[MAX_ROW][MAX_COL]){//玩家落子
	while (1){
		printf("请玩家输入坐标(row,col):");
			int row = 0;
			int col = 0;
		scanf("%d %d", &row, &col);
		if (row<0 || row>=MAX_ROW || col<0 || col>=MAX_COL){
			printf("您的输入有误，请重新输入！\n");
			continue;
		}
		 if (ChessBoard[row][col] != ' '){
			printf("此处已经落子!\n");
			continue;
		}
		ChessBoard[row][col] = 'x';
		break;
	}
}

void computerMove(char ChessBoard[MAX_ROW][MAX_COL]){//电脑落子
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (ChessBoard[row][col] != ' '){
			continue;
		}
		ChessBoard[row][col] = 'o';
		break;
	}
}
int isfull(char ChessBoard[MAX_ROW][MAX_COL]){//判断和棋情况
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			if (ChessBoard[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
char iswin(char ChessBoard[MAX_ROW][MAX_COL]){//判定胜负
	for (int row = 0; row < MAX_ROW; row++){//判定行

		if (ChessBoard[row][0] != ' ' &&ChessBoard[row][0] == ChessBoard[row][1] &&
			ChessBoard[row][0] == ChessBoard[row][2]){
			return ChessBoard[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++){//判定列
		if (ChessBoard[col][0] != ' ' &&ChessBoard[col][0] == ChessBoard[col][1] &&
			ChessBoard[col][0] == ChessBoard[col][2]){
			return ChessBoard[col][0];
		}
	}
	if (ChessBoard[0][0] !=' '  && ChessBoard[0][0] == ChessBoard[1][1] &&
		ChessBoard[0][0] == ChessBoard[2][2]){
		return ChessBoard[0][0];
	}
	if (ChessBoard[2][0] != ' ' && ChessBoard[2][0] == ChessBoard[1][1] &&
		ChessBoard[2][0] == ChessBoard[0][2]){
		return ChessBoard[2][0];
	}
	if (isfull(ChessBoard)){
		return 'q';
	}
	return ' ';
}

void game(){
	char ChessBoard[MAX_ROW][MAX_COL] = { 0 };
	Init(ChessBoard);
	char winner = ' ';
	while (1){
		PrintChessBoard(ChessBoard);//打印棋盘
		playerMove(ChessBoard);//玩家落子
		winner = iswin(ChessBoard);//胜负判定
		if (winner != ' '){
			break;
		}
		computerMove(ChessBoard);
		winner = iswin(ChessBoard);
		if (winner != ' '){
			break;
		}
	}
	PrintChessBoard(ChessBoard);
	if (winner == 'x'){
		printf("恭喜您，战胜了人工智障！\n");
	}
	if (winner == 'o'){
		printf("很遗憾，您连人工智障都不如！\n");
	}
	if (winner == 'q'){
		printf("您和人工智障五五开！\n");
	}
}
int menu(){
	printf("=====================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("=====================\n");
	printf("请输入您的选择：");
		int choice = 0;
		scanf("%d", &choice);
		return choice;
}
int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = menu();//创建一个简单的用户交互菜单
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("Goodbye!\n");
			break;
		}
		else{
			printf("您的输入有误，请重新输入！\n");
		}
}
	system("pause");
	return 0;
}


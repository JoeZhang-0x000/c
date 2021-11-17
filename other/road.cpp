#include"stdio.h"
#include"malloc.h"
#include"math.h"
#include"stdlib.h"
#include <windows.h>
#define max 100000
#define n 25
char vexs[25][15] = { "深圳","广州","南宁","昆明","柳州","贵阳","株洲","南昌","福州","上海","武汉","成都","南京","兰州","西安","郑州","徐州","天津","大连","乌鲁木齐","呼和浩特","北京","沈阳","长春","哈尔滨" };

char vexs1[25][15] = { "" };
char output[1000];
int length = 0;
extern "C"{
void init(int map[n][n]) {
	map[0][1] = 140;
	map[1][0] = 140; map[1][2] = 506; map[1][6] = 675; map[1][7] = 673; map[1][8] = 693;
	map[2][1] = 506; map[2][3] = 629; map[2][4] = 255;
	map[3][2] = 629; map[3][5] = 639; map[3][11] = 1100;
	map[4][2] = 225; map[4][5] = 607; map[4][6] = 672;
	map[5][3] = 639; map[5][4] = 607; map[5][6] = 902; map[5][11] = 976;
	map[6][1] = 675; map[6][4] = 672; map[6][5] = 902; map[6][7] = 367; map[6][11] = 409;
	map[7][1] = 673; map[7][6] = 367; map[7][8] = 622; map[7][9] = 825; map[7][10] = 263;
	map[8][1] = 693; map[8][7] = 622; map[8][9] = 609;
	map[9][7] = 825; map[9][8] = 609; map[9][10] = 688; map[9][15] = 829; map[9][16] = 651;
	map[10][6] = 409; map[10][7] = 263; map[10][9] = 688; map[10][11] = 977; map[10][14] = 650; map[10][15] = 534;
	map[11][3] = 1100; map[11][5] = 967; map[11][10] = 977; map[11][13] = 601; map[11][14] = 842;
	map[12][13] = 216;
	map[13][11] = 601; map[13][12] = 216; map[13][14] = 676; map[13][19] = 1892; map[13][20] = 1145;
	map[14][10] = 650; map[14][11] = 842; map[14][13] = 676; map[14][15] = 511; map[14][20] = 774;
	map[15][9] = 829; map[15][10] = 534; map[15][14] = 511; map[15][16] = 349; map[15][17] = 575; map[15][20] = 694; map[15][21] = 695;
	map[16][9] = 651; map[16][15] = 349; map[16][17] = 674;
	map[17][15] = 575; map[17][16] = 674; map[17][21] = 137; map[17][22] = 704;
	map[18][22] = 397;
	map[19][13] = 1892;
	map[20][13] = 1145; map[20][14] = 774; map[20][15] = 694; map[20][21] = 668;
	map[21][15] = 695; map[21][17] = 137; map[21][20] = 668; map[21][22] = 627;
	map[22][17] = 704; map[22][18] = 397; map[22][21] = 627; map[22][23] = 305;
	map[23][22] = 305; map[23][24] = 242;
	map[24][23] = 242;
}


void menu() {
	printf("    ****************全国主要城市交通查询图****************\n");
	printf("    **********本交通查询系统仅供实验，请勿当真************\n");
	printf("\n城市代号：\n\n");
	printf(" 1、深圳      2、广州     3、南宁     4、昆明      5、柳州\n");
	printf(" 6、贵阳      7、株洲     8、南昌     9、福州     10、上海\n");
	printf("11、武汉     12、成都    13、南京    14、兰州     15、西安\n");
	printf("16、郑州     17、徐州    18、天津    19、大连     20、乌鲁木齐\n");
	printf("21、呼和浩特 22、北京    23、沈阳    24、长春     25、哈尔滨\n");
	printf("\n");
}


int DIJKSTRA(int C[25][25],int a, int b) {//c为有向网路的带权邻接矩阵
	int D[n];             //各顶点的距离值
	int P[n], S[n];
	int i, j, k, vl, pre;
	int min, inf = 10000;
	int start = a, end = b;       //起点、终点
	int v; // 用于暂时存储距离




	//把结果写入一个名为 a.txt的文件
	FILE* fp;
	fp = fopen("a.txt", "w");
	if (fp == NULL) return 0;


   //采用Dijsktra 规划最短路径
	vl = start - 1;
	
	
		for (i = 0; i < n; i++)
		{
			D[i] = C[vl][i];
			if (D[i] != max) P[i] = start;
			else P[i] = 0;
		}
		for (i = 0; i < n; i++) S[i] = 0;
		S[vl] = 1; D[vl] = 0;
		for (i = 0; i < n - 1; i++)
		{
			min = inf;
			for (j = 0; j < n; j++)
				if ((!S[j]) && (D[j] < min))
				{
					min = D[j]; k = j;
				}
			S[k] = 1;
			for (j = 0; j < n; j++)
				if ((!S[j]) && (D[j] > D[k] + C[k][j]))
				{
					D[j] = D[k] + C[k][j];
					P[j] = k + 1;
				}
		}

		v = D[end - 1];

		

		char add[] = { "<--" };
		for (int i = 0; i < 15; i++) { fputc(vexs[end - 1][i], fp); }
		
		

		pre = P[end - 1];
		while (pre != 0)
		{
            for (int i = 0; i < strlen(add); i++)
				fputc(add[i], fp);
			
			for (int i = 0; i < 15; i++) { fputc(vexs[pre - 1][i], fp); }
			
			
			pre = P[pre - 1];
		}

		printf("\n");

	
	
	//
	fclose(fp);
	
	return v;
}



int start(int a, int b)
{
	int i, j;
	int map[n][n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			map[i][j] = max;

	init(map);

	
	
	return DIJKSTRA(map, a, b);
}


//这个主函数是用来测试的
int main() {
    menu();
	int a , b ;
    scanf("%d",&a);
    scanf("%d",&b);
	start(a, b);
	
	return 0;
}
  
}
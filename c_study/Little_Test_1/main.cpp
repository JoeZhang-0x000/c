#include<stdio.h>
#define MAX 100
int main() {
	int apple = 5;//һ��ƻ����Ǯ
	int shaddock = 8;//һ�����Ӽ�Ǯ
	int jujube = 1;//�������Ӽ�Ǯ
	int money;//�ܼ�
	int num;//����
	int count = 0;//��������

	printf("the possible combinations:\n");
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			for (int k = 1; k < MAX; k++) 
			{
				num = i + j + k * 3;
				money = i * apple + j * shaddock + k * jujube;
				if (num>=100&&money<=100)
				{
					printf("apple:%d,shaddock:%d,jujube:%d,NO.%d\n", i, j, k*3,count);
					count++;
				}
			}

		}
	}
	printf("total:%d combinations", count);
	return 1;
}


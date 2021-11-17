#include<stdio.h>
#define MAX 100
int main() {
	int apple = 5;//一个苹果价钱
	int shaddock = 8;//一个柚子价钱
	int jujube = 1;//三个枣子价钱
	int money;//总价
	int num;//数量
	int count = 0;//方案总数

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


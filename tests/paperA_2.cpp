#include <stdio.h>
#include <string.h>
typedef struct tagFRUIT
{
	char szFuitName[20];//水果名称
	double dbPrice;//单价
}FRUIT,*PFRUIT;

FRUIT* GetFruitArry(int *kinds)
{
	static FRUIT fruit[] = {{"apple",8.0},{"pear",5.2},{"grape",7.8},{"banana",12.7},{"orange",4.3}};
	*kinds = sizeof(fruit)/sizeof(FRUIT);
	return fruit;
}
void PrintFruitInformation()
{
	int nFruitKinds = 0;
	FRUIT* pFruitArry = GetFruitArry(&nFruitKinds);
	int i;
	printf("There are %d kinds of fruit here:\n",nFruitKinds);
	for(i = 0;i<nFruitKinds;i++)
	{
		printf("%s  price :%2.1f ($/pounds)\n",pFruitArry[i].szFuitName,pFruitArry[i].dbPrice);
	}
	
}
int ChooseFruit(FRUIT *fruit)
{
	int bChoose = 0;
	int nFruitKinds = 0;
	FRUIT* pFruitArry = GetFruitArry(&nFruitKinds);
	
	int i;
	printf("Please input fruitName:\n");
	scanf("%s",fruit->szFuitName);
	
	FRUIT* pPtrFruit = pFruitArry;
	
	for (i =0 ;i<nFruitKinds;i++, pPtrFruit++)
	{
		if(strcmp(pPtrFruit->szFuitName , fruit->szFuitName) == 0)
		{
			*fruit = *pPtrFruit;
			bChoose = 1;
			break;
		}
	}
	if(!bChoose)
	{
		printf("can't find fruit '%s',please input again\n",fruit->szFuitName);
	}
	return bChoose;
	
}

int main()
{
	FRUIT fruit;
	PrintFruitInformation();
	while( 0 ==  ChooseFruit(&fruit));
	printf("Please enter the purchase quantity (pounds):\n");
	double pounds = 0;
	do 
	{
		fflush(stdin);
		scanf("%lf",&pounds);
	} while (pounds<=0.0000001);
	double dbMoney =pounds*fruit.dbPrice;
	printf("You need pay %3.2lf $ for %3.1lf pounds of %s",
		dbMoney,pounds,fruit.szFuitName);
	return 0;
}

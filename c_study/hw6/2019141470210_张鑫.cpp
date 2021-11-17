/***************************************project6_55  ��ӡ����***********************************************/

#include<stdio.h>;
//�˵�
void menu();
//�ж�����������Ƿ�Ϸ�
bool isLegal(int,int);
//��ӡ����
void printCalendar(int,int);

int main() {
	menu();
	return 0;
}
void menu() {
	int choose, year, month;
	while (true)
	{
		printf("project6_55����ϵͳ����ѡ��---\n");
		printf("1-------continue\n");
		printf("2-------exit\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("������ݣ��·ݣ��磨2001 12)\n");
			scanf("%d %d", &year, &month);
			if (isLegal(year,month))
			{
				printCalendar(year, month);
			}
			else
			{
				printf("�������벻�Ϸ���\n");
			}
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}

bool isLegal(int year, int month) {
	int flag = 1;
	if (year < 0 ||month<0||month>13)
	{
		flag = 0;
	}
	return (flag) ? true : false;
}
void printCalendar(int year, int month) {
	//�ҵ�����ĵ�һ�����ܼ�
	int first_day_this_year = (((year - 1) * 365) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 1) % 7;
	//�Ƿ�Ϊ����
	bool is_leap_year = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? true : false;
	//���µ�һ�����ܼ�
	int first_day_this_month;
	//���µ�һ���Ǹ���ĵڶ�����
	int first_day;
	//������ж�����
	int days;
	//���ڼ�������ʱ���1���������Ϊ0
	int one = (is_leap_year) ? 1 : 0;

	switch (month)
	{
	case 1:
		first_day = 0;
		days = 31;
		break;
	case 2:
		first_day = 31;
		days = 28 + one;
		break;
	case 3:
		first_day = 31 + 28 + one;
		days = 31;
		break;
	case 4:
		first_day = 31 * 2 + 28 + one;
		days = 30;
		break;
	case 5:
		first_day = 31 * 2 + 30 + 28 + one;
		days = 31;
		break;
	case 6:
		first_day = 31 * 3 + 30 + 28 + one;
		days = 30;
		break;
	case 7:
		first_day = 31 * 3 + 30 * 2 + 28 + one;
		days = 31;
		break;
	case 8:
		first_day = 31 * 4 + 30 * 2 + 28 + one;
		days = 31;
		break;
	case 9:
		first_day = 31 * 5 + 30 * 2 + 28 + one;
		days = 30;
		break;
	case 10:
		first_day = 31 * 5 + 30 * 3 + 28 + one;
		days = 31;
		break;
	case 11: 
		first_day = 31 * 6 + 30 * 3 + 28 + one;
		days = 30;
		break;
	case 12:
		first_day = 31 * 6 + 30 * 4 + 28 + one;
		days = 31;
		break;
	default:
		break;
	}

	first_day_this_month = (first_day + first_day_this_year) % 7;
	if (first_day_this_month ==0)
	{
		first_day_this_month = 7;
	}
	if (first_day_this_year == 0)
	{
		first_day_this_year = 7;
	}

	printf("%d���һ������%d\n", year, first_day_this_year);
	printf("%d��%d���ǵ�%d��\n", year, month, first_day);
	printf("%d��%d�µ�һ������%d\n", year, month, first_day_this_month);

	printf("*****************%4d��%2d������*****************\n",year,month);
	printf("MON    TUE    WED    THU    FRI    SAT    SUN\n");

	for (int i = 0; i < first_day_this_month-1; i++)
	{
		printf("       ");
	}
	for (int i = 1; i <= days; i++)
	{
		int d = 7 - first_day_this_month+1;
		printf("%2d     ", i);
		if (i == (d)||((i-d)%7 == 0))
		{
			printf("\n");
		}
	}
	printf("\n");
}

/*******************************************************************************************************/


/**********************************************6.15 �����ظ�********************************************/
/*
#include<stdio.h>
#include<stdlib.h>
void menu();
void duplicate(int*,int);
void createArray(int );
int main() {
	menu();
	return 0;
}

void menu() {
	int choose, year, month;
	while (true)
	{
		printf("6.15 �����ظ�,��ѡ��---\n");
		printf("1-------�Լ��ֶ�����\n");
		printf("2-------�������������\n");
		printf("3-------exit\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			//�ֶ��������
			createArray(1);
			break;
		case 2:
			//�Զ��������
			createArray(2);
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

void createArray(int i) {
	int array[20];
	int n = sizeof(array) / sizeof(int);

	switch (i)
	{
	case 1:
		//�ֶ�����array
		for (int  i = 0; i < n; i++)
		{
			printf("�������%d��Ԫ��:\t", i);
			scanf("%d", array + i);
			printf("\n");
		}
		break;
	case 2:
		//ʹ�����������20�� [10,100��������
		printf("�Ѿ�Ϊ���������20�� [10.100)������\n");
		for (int  i = 0; i < n; i++)
		{
			array[i] = rand() % 90 + 10;
		}
		break;
	default:
		break;
	}
	duplicate(array, n);
}

void duplicate(int* array,int n) {

	//��ӡ��ʼarray
	printf("��ʼarray:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
	//ȥ��
	printf("ȥ�غ�:\n");
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		for (int j = 0; j < i; j++)
		{
			if (array[j]==array[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			printf("%d\t ", array[i]);
		}
	}
	printf("\n**************************END******************************\n");
}
*/
/***************************************************************************************************/


/**********************************************6.21 ����Ԥ��********************************************/
/**
#include<stdio.h>;
#include<stdlib.h>
#include<string.h>
void menu(int*,int*);
//������λ��������룬1Ϊͷ�Ȳգ�2Ϊ���òգ�������λ�ţ���Ϊ-1�����ǰ����λ����,-2����ǰ��������
int assign(int,int*,int*);

//���òյ�����
#define MAX_ECONOMY  5;
//ͷ�Ȳյ�����
#define MAX_FIRSTCLASS  5;

int main() {
	//���ò�ʣ������
	int number_economy = MAX_ECONOMY;
	//ͷ�Ȳ�ʣ������
	int number_firstclass = MAX_FIRSTCLASS;
	menu(&number_economy,&number_firstclass);
	return 0;
}

void menu(int  *n_e,int *n_f) {
	//�û�ѡ��Ĳյ�����
	int type;
	//���������λ��
	int seat;
	int c;

	while (true)
	{
		printf("\n**************************************\n");
		printf("1----------����Ԥ����λ\n");
		printf("2----------����\n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf("��ӭ�������κ��࣬����������Ҫ�Ĳ���\n");
			printf("1-----------------------------------first class\n");
			printf("2-----------------------------------economy\n");
			scanf("%d", &type);

			seat = assign(type,n_e,n_f);
			if (seat>0)
			{
				printf("���������λ��Ϊ%d", seat);
			}else if (seat == -2)
				{
					printf("�ܱ�Ǹ����ǰ�����Ѿ����ˣ���30���Ӻ������һ��\n");
				}else if (seat == -1)
				{
					char *old_class;
					char *new_class;
					char message[100] = "����ǰѡ��Ĳ�Ϊ";
					char *str = message;
					//�û���ѡ���Ƿ��������
					int choose;
					switch (type)
					{
					case 1:
						old_class = (char*)"ͷ�Ȳ�";
						new_class = (char*)"���ò�";
						type = 2;
						break;
					case 2:
						old_class = (char*)"���ò�";
						new_class = (char*)"ͷ�Ȳ�";
						type = 1;
						break;
					default:
						break;
					}
					strcat(str, old_class);
					strcat(str, "���Ƿ�Ϊ������Ϊ");
					strcat(str, new_class);
					printf("\n");
					while (*str !='\0')
					{
						printf("%c", *str++);
					}
					printf("\n");
					printf("1--------------YES\n");
					printf("2--------------NO\n");
					scanf("%d", &choose);
					switch (choose)
					{
					case 1:
						seat = assign(type,n_e,n_f);
						if (seat>0)
						{
							printf("���������λ��Ϊ%d\n", seat);
						}
						else
						{
							printf("�ܱ�Ǹ����ǰ�����Ѿ����ˣ���30���Ӻ������һ��\n");

						}
						break;
					case 2:
						printf("��30���Ӻ������һ�ຽ���\n");
						break;
					default:
						break;
					}

				}

			break;
		case 2:
			return;
		default:
			break;
		}
	}

}

int assign(int type,int *n_e,int *n_f) {
	int num;
	
	printf("��ǰͷ�Ȳ�ʣ��%d\n",*(n_e));
	printf("��ǰ���ò�ʣ��%d\n",*(n_f));

	//���κ�������
	if (((*n_e)+(*n_f)) ==0)
	{
		num = -2;
	}
	switch (type)
	{
	case 1:
		if (*n_e>0)
		{
			num = (*n_e) --;
		}
		else
		{
			num = -1;
		}
		break;
	case 2:
		if (*n_f>0)
		{
			num = (*n_f)--+5;
		}
		else
		{
			num = -1;
		}
		break;
	default:
		break;
	}

	return num;
}
**/
/***************************************************************************************************/
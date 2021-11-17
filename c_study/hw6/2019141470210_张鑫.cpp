/***************************************project6_55  打印月历***********************************************/

#include<stdio.h>;
//菜单
void menu();
//判断输入的年月是否合法
bool isLegal(int,int);
//打印日历
void printCalendar(int,int);

int main() {
	menu();
	return 0;
}
void menu() {
	int choose, year, month;
	while (true)
	{
		printf("project6_55日历系统，请选择---\n");
		printf("1-------continue\n");
		printf("2-------exit\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("输入年份，月份，如（2001 12)\n");
			scanf("%d %d", &year, &month);
			if (isLegal(year,month))
			{
				printCalendar(year, month);
			}
			else
			{
				printf("您的输入不合法！\n");
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
	//找到该年的第一天是周几
	int first_day_this_year = (((year - 1) * 365) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 1) % 7;
	//是否为闰年
	bool is_leap_year = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? true : false;
	//该月第一天是周几
	int first_day_this_month;
	//该月第一天是该年的第多少天
	int first_day;
	//这个月有多少天
	int days;
	//用于计算闰年时候加1，其他年份为0
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

	printf("%d年第一天是周%d\n", year, first_day_this_year);
	printf("%d年%d月是第%d天\n", year, month, first_day);
	printf("%d年%d月第一天是周%d\n", year, month, first_day_this_month);

	printf("*****************%4d年%2d月日历*****************\n",year,month);
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


/**********************************************6.15 消除重复********************************************/
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
		printf("6.15 消除重复,请选择---\n");
		printf("1-------自己手动输入\n");
		printf("2-------懒人随机数测试\n");
		printf("3-------exit\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			//手动输入参数
			createArray(1);
			break;
		case 2:
			//自动输入参数
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
		//手动读入array
		for (int  i = 0; i < n; i++)
		{
			printf("请输入第%d个元素:\t", i);
			scanf("%d", array + i);
			printf("\n");
		}
		break;
	case 2:
		//使用随机数生成20个 [10,100）的数字
		printf("已经为您随机生成20个 [10.100)的数字\n");
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

	//打印初始array
	printf("初始array:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
	//去重
	printf("去重后:\n");
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


/**********************************************6.21 航班预定********************************************/
/**
#include<stdio.h>;
#include<stdlib.h>
#include<string.h>
void menu(int*,int*);
//分配座位，输入代码，1为头等舱，2为经济舱，返回座位号，若为-1则代表当前舱座位已满,-2代表当前航班已满
int assign(int,int*,int*);

//经济舱的数量
#define MAX_ECONOMY  5;
//头等舱的数量
#define MAX_FIRSTCLASS  5;

int main() {
	//经济舱剩余数量
	int number_economy = MAX_ECONOMY;
	//头等舱剩余数量
	int number_firstclass = MAX_FIRSTCLASS;
	menu(&number_economy,&number_firstclass);
	return 0;
}

void menu(int  *n_e,int *n_f) {
	//用户选择的舱的类型
	int type;
	//分配给的座位号
	int seat;
	int c;

	while (true)
	{
		printf("\n**************************************\n");
		printf("1----------继续预定座位\n");
		printf("2----------结束\n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf("欢迎乘坐本次航班，请输入您想要的舱类\n");
			printf("1-----------------------------------first class\n");
			printf("2-----------------------------------economy\n");
			scanf("%d", &type);

			seat = assign(type,n_e,n_f);
			if (seat>0)
			{
				printf("您分配的座位号为%d", seat);
			}else if (seat == -2)
				{
					printf("很抱歉，当前航班已经满了！请30分钟后乘坐下一班\n");
				}else if (seat == -1)
				{
					char *old_class;
					char *new_class;
					char message[100] = "您当前选择的舱为";
					char *str = message;
					//用户的选择，是否更换航班
					int choose;
					switch (type)
					{
					case 1:
						old_class = (char*)"头等舱";
						new_class = (char*)"经济舱";
						type = 2;
						break;
					case 2:
						old_class = (char*)"经济舱";
						new_class = (char*)"头等舱";
						type = 1;
						break;
					default:
						break;
					}
					strcat(str, old_class);
					strcat(str, "，是否为您更换为");
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
							printf("您分配的座位号为%d\n", seat);
						}
						else
						{
							printf("很抱歉，当前航班已经满了！请30分钟后乘坐下一班\n");

						}
						break;
					case 2:
						printf("请30分钟后乘坐下一班航班吧\n");
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
	
	printf("当前头等舱剩余%d\n",*(n_e));
	printf("当前经济舱剩余%d\n",*(n_f));

	//本次航班满了
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
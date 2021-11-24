
//1. 找出以下错误
//find errors in the program
void main()
{
    char str1[11] = {'G','o','o','d', ' ','D','a','y','\0'};
    char str2[11] = "Good Day";
    char str3[4] = {'G','o','o','d'};
    char str4[4] = "Good";
    char str5[4];
    char str6[5];
    char str7[20];
    int i = 0;

    //
	str5[5] = "Hi";
    for(;i<5-1;i++)
        str6[i] = "a"+1;
    str6[5] = "\0";


   //观察错误现象 
    for(i=0;i<20;i++)
        str7[i]='a';
    //str7[19] = '\0';
    
    printf("The following output are printed by for/printf\%c\n");
    for(i=0;i<10;i++)
       printf("%c",str7[i]);
    
    printf("\nThe following output are printed by printf%s\n");
    printf("%s\n",str3);

    printf("The following output are printed by puts\n");
    puts(str7);
    printf("\n");
}


/*
//2.  
#include <stdio.h>
#include <windows.h>

#define SIZE 20

void main()
{
    int str1[SIZE];
    int str2[SIZE];
	int x;
	printf("Input an integer:");
	scanf("%d",&x);
	//fflush(stdin);
    printf("Input str1:\n");
    scanf("%s",str1);
    //fflush(stdin);
    printf("Input str2:\n");
    scanf("%s",str2);

    printf("print str1:\n");
    printf("%s\n",str1);
    printf("print str2:\n");
    printf("%2s\n",str2);

    system("Pause");
}*/



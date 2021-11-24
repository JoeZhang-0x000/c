#include <stdio.h>
#include <string.h>
#define SIZE 100

int main()
{
	char str1[SIZE],str2[SIZE]; 
	int  num1[SIZE],num2[SIZE];
	int  sum[SIZE+1]={0};
	//char strsum[SIZE+1];
	int len1=0,len2=0,maxlen=0;
	int i,temp;
	
	memset(str1,0,sizeof(char)*SIZE);
	memset(str1,0,sizeof(char)*SIZE);
	memset(num1,0,sizeof(int)*SIZE);
	memset(num2,0,sizeof(int)*SIZE);
	
	printf("Please input summand: ");//被加数 
	//fgets(str1,SIZE-1,stdin);
	scanf("%s",str1); 
	printf("Please input addend: ");//加数 
	scanf("%s",str2); 
	//fgets(str2,SIZE-1,stdin);
	
	len1=strlen(str1);
	len2=strlen(str2);
	
	for(i=0;i<len1;i++)
		num1[i]=str1[len1-1-i]-'0';
	
	for(i=0;i<len2;i++)
		num2[i]=str2[len2-1-i]-'0';
		
	maxlen = len1>len2?len1:len2; 
	for(i=0;i<maxlen;i++)
	{
		temp=num1[i]+num2[i]+sum[i];
		sum[i]=temp%10;
		sum[i+1] = temp/10; 
		/*temp=num1[i]+num2[i];
		sum[i]=sum[i]+temp%10;
		sum[i+1] = temp/10; */
	}	

	if(sum[maxlen] != 0)
	{
		printf("%d",sum[maxlen]);
	}
	
	for(i=maxlen-1;i>=0;i--)
		printf("%d",sum[i]);	
	
    printf("\n");
	return 0;
 } 

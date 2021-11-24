/*
//find substring by strstr 
#include <string.h>
#include <stdio.h>
#include <windows.h>

int main()
{
  
char str[] ="lazy";
char string[] = "The quick brown dog jumps over the lazy fox"; 
char *pdest; 
int i;
pdest = strstr( string, str ); 
if( pdest != NULL )
	printf( "%s found \n", str );
else
    printf( "%s not found\n", str ); 
} 
*/


/*
//×Ô¼ºÐ´ 
#include <string.h>
#include <stdio.h>
#include <windows.h>


#define SIZE 20
#define SUBSIZE 5

int searchsubstring(const char *src,const char *tgtstr,int *loc);
void main()
{
	char str[SIZE];
	char substr[SUBSIZE];
	int loc=0;

	//read
	printf("Input a string less than %d£º",SIZE-1);
	scanf("%s",str);//(SIZE-1)
	fflush(stdin);

	printf("Input a substring less than %d£º",SUBSIZE-1);
	scanf("%s",substr);//(SUBSIZE-1)
	fflush(stdin);

	if(searchsubstring(str,substr,&loc))
		printf("Found substring %s in source string %s at %d!\n",substr,str,loc);
	else
		printf("Not found substring %s in source string %s!\n",substr,str);

	system("Pause");
}

int searchsubstring(const char *src,const char *tgtstr,int *loc)
{
	int i=0,j=0;
	int srcstrlen=0;
	int substrlen=0;

	srcstrlen = strlen(src);
	substrlen = strlen(tgtstr);

	//
	for(i=0;i<=srcstrlen-substrlen;i++)
	{
		for(j=0;j<substrlen;j++)
		{
			*loc = i;
			if(src[i+j]!=tgtstr[j])
				break;
		}//found, since not break out of the inner loop
		if(j == substrlen)
		{
			return 1;
		}
	}
	return 0;
}
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <string.h>//
#include <windows.h> 
#define SIZE 100//

int main(){
    char email[SIZE];// 
    char dotarr[8];
    int len=0;
    int atpos=-1;
    int atcount=0;
    int dotcount = 0;
    char *pdest = NULL;

    int i=0;
    printf ("please enter your email address\n");

    scanf("%s", email);

    len=strlen(email);
    if(len==0)
    {
    	printf("Error, not a valid string.");
    	return 0;
	}
	
	for(i=0;i<len;i++)
	{
		if(email[i]=='@')
		{
			atcount++;
			atpos = i;
		}	
		if(email[i]=='.')//not the best solution
		{
			dotarr[dotcount]=i;
			dotcount++;
		}
	}
    //basic rules 
    if(atcount > 1)
    {
	 	printf("Basic rule, more than one '@'.This email address is not right.\n");
        return 0;
	}
	if(atcount == 0)
    {
	 	printf("Basic rule, zero '@'.This email address is not right.\n");
        return 0;
	}	  
	if(dotcount == 0)
    {
	 	printf("Basic rule, none '.'.This email address is not right.\n");
        return 0;
	}	

    //rule 1
    if(email[len-1]=='@' || email[len-1]=='.'||email[0]=='@' || email[0]=='.')
	 {
	 	printf("Rule one: appear in first or last place.This email address is not right.\n");
        return 0;
	 }
	//rule2	
	//if(email[max(0,atpos-1)]=='.'||email[min(len-1,atpos+1)]=='.')//注意溢出不可能出现@不在首尾 
	if(email[atpos-1]=='.'||email[atpos+1]=='.') 
 	{
	 	printf("Rule two: '.' besides '@' on either side.This email address is not right.\n");
        return 0;
	}
     
    //rule3 
    //use strstr to search ".." is a better choice
	pdest = strstr( email, ".." );
	if(pdest){
	
		 printf("Rule three: '.' besides '.' on either side.This email address is not right.\n");
        	return 0;
	}
	// not the best solution
    for(i=0;i<dotcount-1;i++)
    {
    	if(dotarr[i]==dotarr[i+1]+sizeof(char))
    	{
	 		printf("Rule three: '.' besides '.' on either side.This email address is not right.\n");
        	return 0;
		}
	}
	
	printf("%s   -- is a valid email address.\n");
	system("Pause");
	return 1;
    
}


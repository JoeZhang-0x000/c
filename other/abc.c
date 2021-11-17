#include "stdio.h"
#include "string.h"
#include"windows.h"
int main(){

    char a[10]="123456";
    char b[20]="abc";
    char *s;
    s=a;
    s=strcat(s,b);
    puts(s);
    system("pause");
    return 0;

}
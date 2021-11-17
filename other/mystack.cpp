
#include <stack>
#include<stdio.h>
#include <iostream>
using namespace std;
 
int main()
{
	stack<int> mystack;
	char a[10];
    scanf("%s",&a);
    for(int i=0;i<10;i++){
        mystack.push(a[i]);
    }
    for(int i=0;i<10;i++){
    
    cout<<" "<<mystack.top()<<endl;
    mystack.pop();
    }
	system("pause");
	return 0;
}
//size is 11
// 10 9 8 7 6 5 4 3 2 1 0
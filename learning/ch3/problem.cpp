#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int main(){
    int *a=(int *)malloc(sizeof(int)*3*2);
    memset(a,0,24);
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
            cout<<setw(20)<<&a[i*2+j];
    cout<<endl;

    for(int i=0;i<6;i++)
        cout<<setw(20)<<(a+i);
    cout<<endl;
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
            cout<<setw(20)<<*(a+i*2+j);


    return 0;
}
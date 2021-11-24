#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

int findMax(int*a,int len){
    int tem=*(a);
    for(int i=0;i<len;i++)
        tem=(tem>*(a+i))?tem:*(a+i);
    return tem;
}
int findByIndex(int*a,int len,int v){
    for(int i=0;i<len;i++)
        if(*(a+i)==v) 
            return i;  
        
    //没有找到
    return -1;
}

void generate(int *a,int len){
    if(a==NULL)
        return;
    
    for(int i=0;i<len;i++)
        *(a+i)=rand()%9+1;
}
void printArray(int *a,int len){
    if(a==NULL)
        return;

    for(size_t i=0;i<len;i++){
        cout<<setw(2)<<*(a+i)<<" ";
        if((i+1)%5==0)
            cout<<endl;
    }
}
void find(int* a,int len){
    if(a==NULL)
        return;

    int count[len]={0};
    int tem1,tem2,l,r,m;
    int *p;
    l=0,r=1;
    while(r<len){
        if((*(a+l)>*(a+r))){
            count[l]+=1;
            r++;
        }
        else{
            l++;
            r=l+1;
        }
    }
    cout<<"count:";
    for(int i =0;i<len;i++)
        cout<<count[i]<<" ";
    cout<<endl;
    p=count;
    m=findMax(p,len);
    // cout<<m<<endl;
    l=findByIndex(count,len,m);
    r=l+m-1;
    cout<<"找到了第一个最长的相同子链长度为:"<<m<<"起始:"<<l<<"终止:"<<r<<endl;
    
    

        
}
int main(){
    srand(time(0));
    int n=30;
    int *a=(int*)malloc(n*sizeof(int));
    //生成数组
    generate(a,n);
    //打印数组
    printArray(a,n);

    find(a,n);

    free(a);
    return 0;
}
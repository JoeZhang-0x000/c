#include<iostream>
using namespace std;
void swap(void *a,void *b,int size){
    void *tem = (void*)malloc(size);
    memcpy(tem,a,size);
    memcpy(a,b,size);
    memcpy(b,tem,size);
    free(tem);
}
long partition(void *a,int size,int p,int r){
    int i,j;
    void *x = (void*)malloc(size);
    memcpy(x,a+r*size,size);
    i = p-1;
    j = p;
    for(;j<r;j++)
        if(*(int*)(a+j*size)<*((int*)(x))){
            i++;
            swap(a+i*size,a+j*size,size);
        }
    free(x);
    swap(a+(i+1)*size,a+r*size,size);
    return i+1;
}
int main(){
    int a[] = {3,5,1,2,3,4,6,7,3,4},i,j;
    for(int i = 0;i<sizeof(a)/sizeof(int);i++)
        cout<<a[i]<<" ";
    cout<<endl;
    partition(a,sizeof(int),0,sizeof(a)/sizeof(int)-1);
    
    for(int i = 0;i<sizeof(a)/sizeof(int);i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
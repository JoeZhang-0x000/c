#include<iostream>
using namespace std;
void swap(void *x,void *y,int size){
    void *t = (void*)malloc(size);
    memcpy(t,x,size);
    memcpy(x,y,size);
    memcpy(y,t,size);
}
int parent(int i){
    if(i%2==1)
        return (i-1)/2;
    else
        return (i-2)/2;
}
int left(int i){
    return 2*i+1;
}
int right(int i){
    return 2*i+2;
}
int intGreater(void *x,void *y){
    return *((int*)x)-*((int*)y);
}
void heapify(void *a,int size,int i,int heapSize,int(*comp)(void*,void*)){
    int l = left(i),r = right(i),max;
    if(l<heapSize&&comp(a+i*size,a+l*size)<0)
        max = l;
    else
        max = i;
    if(r<heapSize&&comp(a+max*size,a+r*size)<0)
        max = r;
    if(max!=i){
        swap(a+i*size,a+max*size,size);
        heapify(a,size,max,heapSize,comp);
    }
}
void buildHeap(void *a,int size,int length,int(*comp)(void*,void*)){
    int i;
    for(i=length/2;i>=0;i--)
        heapify(a,size,i,length,comp);
}
void heapSort(void *a,int size,int n,int(*comp)(void*,void*)){
    int i,heapSize = n;
    buildHeap(a,size,n,comp);
    for(i = heapSize-1;i>0;i--){
        swap(a+i*size,a,size);
        heapSize--;
        heapify(a,size,0,heapSize,comp);

    }
    
}
int main(){
    int h[] = {3,8,9,5,2,0,7,4,2,5,1,4,6};
    int n = sizeof(h)/sizeof(int);
    heapSort(h,4,n,intGreater);
    for(int i =0;i<n;i++){
        cout<<h[i]<<" ";
    }
    cout<<endl;
    return 0;
}
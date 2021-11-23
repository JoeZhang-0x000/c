#include<iostream>
using namespace std;

int intGreater(void *a,void *b){
    return *((int*)a)-*((int*)b);
}
void swap(void *x,void *y,int size){
    void *t = (void*)malloc(size);
    memcpy(t,x,size);
    memcpy(x,y,size);
    memcpy(y,t,size);
    free(t);
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
struct queue{
    int length;
    int heapSize;
    void *heap;
};
typedef struct queue priorityQueue;
priorityQueue heapAlloc(int size,int n){
    priorityQueue q;
    q.length = n;
    q.heapSize = 0;
    q.heap = (void*)malloc(size*n);
    return q;
}
void enQueue(priorityQueue *q,int size,void *e,int(*comp)(void*,void*)){
    if(q->heapSize==q->length)/*队列满*/
        return;   
    int i =q->heapSize++;
    memcpy(q->heap+i*size,e,size);//将e的值放到堆的末尾
    while(i>0&&comp(q->heap+i*size,q->heap+parent(i)*size)>0)
    swap(q->heap+i*size,q->heap+parent(i)*size,size);
    i = parent(i);
}
int main(){
    return 0;
}
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct Node{
    void *data;
    struct Node* pre;
    struct Node* next;
};
typedef struct Node Node;
Node* builtList(void *array,int n,int size){
    int i;
    Node *p,*t,*l = (Node *)malloc(sizeof(Node));
    l->data = (void*)malloc(size);
    memcpy(l->data,array,size);
    l->pre = l->next =NULL;
    t = l;
    for(i =1;i<n;i++){
        p = (Node*)malloc(sizeof(Node));
        p->data = (void*)malloc(size);
        memcpy(p->data,array+i*size,size);
        t->next = p;
        p->pre = t;
        p->next = NULL;
        t=p;
    }
    return l;
}

void bilistClear(Node *bl){
    if(bl->data!=NULL){
        free((char*)bl->data);
        bl->data = NULL;
    }
    if(bl->pre!=NULL)
        bl->pre->next = NULL;
    bl->pre=NULL;
        return;
    bilistClear(bl->next);
    free(bl->next);
    bl->next =NULL;
}

void listInsertionSort(Node *List,int size,int(*comp)(void*,void*)){
    Node *p,*q,*t;
    void *key = (void*)malloc(size);
    for(p=List->next;p!=NULL;p=p->next){
        memcpy(key,p->data,size);
        q = p->pre;
        t=p;
        while(q!=NULL&&(comp(q->data,key)>0)){
            memcpy((q->next)->data,q->data,size);
            t =q;
            q=q->pre;
        }
        memcpy(t->data,key,size);
    }
}
int intGreater(void *x,void *y){
    return (*(int*)x-*(int*)y);
}
void printArray(int *array,int size){
    int *p= array;
    for(int i=0;i<size;i++)
        cout<<*p++<<"   ";
    cout<<endl;
}
int main(){
    srand(time(NULL));
    const int n = 10;
    struct Node *a,*t;
    int A[n];
    for(int i =0;i<n;i++)
        A[i] = rand()%10;
    printArray(A,n);
    a = builtList(A,n,sizeof(int));
    listInsertionSort(a,sizeof(int),intGreater);
    // printArray(A,n);
    t = a;
    while (t!=NULL)
    {
        cout<<*(int*)(t->data)<<"   ";
        t=t->next;
    }
    cout<<endl;
    
    

    

    return 0;
}
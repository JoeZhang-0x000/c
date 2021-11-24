#include<iostream>
using namespace std;
typedef struct LinkStack
{
    int value;
    LinkStack* next;
}stack;
stack* init(int v){
    stack* p=(stack*)malloc(sizeof(stack));
    p->value=v;
    p->next=NULL;
    return p;
}
stack* push(stack *p, int v){
    stack* temp=(stack*)malloc(sizeof(stack));
    temp->value=v;
    temp->next=p;
    p=temp;
    return p;
}

stack* pop(stack *p){
    if(p==NULL){
        cout<<"empty!"<<endl;
        return p;
    }
    stack* del=p;
    p=p->next;
    cout<<"pop:"<<del->value<<endl;
    free(del);
    return p;
}

void popAll(stack *p){
    stack* temp;
    while(temp){
        temp=p;
        p=pop(temp);
    }
}
int main(){
    stack *p=init(8);
    for(int i=0;i<10;i++)
        p=push(p,i);
    popAll(p);


    return 0;
}
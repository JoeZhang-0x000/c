#include<iostream>
using namespace std;
#define MaxSize 16
struct Stack
{
    int value[MaxSize];
    int top;
};
typedef Stack stack;

void pop(stack* s){
    if(s->top==0){
        cout<<"empty!"<<endl;
        return;
    }
    cout<<s->value[--s->top]<<endl;
}
void push(stack*s,int v){
    if(s->top==MaxSize-1){
        cout<<"full"<<endl;
        return;
    }
    s->value[s->top++]=v;
}
void popAll(stack*s){
    while(s->top>0)
        pop(s);
}
bool isEmpty(stack *s){
    return (s->top==0)?true:false;
}
bool isFull(stack *s){
    return (s->top==(MaxSize-1))?true:false;
}
stack* init(int v){
    stack* s=(stack*)malloc(sizeof(stack));
    s->top=0;
    return s;
} 

int main(){
    stack *s=init(1);
    push(s,9);
    push(s,7);
    push(s,4);
    popAll(s);
    cout<<isEmpty(s)<<endl;
    cout<<isFull(s)<<endl;

    return 0;
}
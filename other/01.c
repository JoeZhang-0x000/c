/*
#include<stdio.h>
#include<stdlib.h>


typedef int Datatype;
typedef struct Node
	{
		Datatype data;
		struct Node* next;
	}Node, *pNode;
typedef struct LinkStack
{
	pNode top;
	int count;
}LinkStack;
bool InitStack(LinkStack **S);
void DestroyStack(LinkStack *S);
void ClearStack(LinkStack *S);
bool StackEmpty(LinkStack S);
int  StackLength(LinkStack *S);
void GetTop(LinkStack *S,Datatype &e);
bool Push(LinkStack *S, Datatype e);
bool Pop(LinkStack *s, Datatype &e);
void StackPrint(LinkStack S);

bool InitStack(LinkStack **S)//初始化空栈Ｓ
{
	*S = (LinkStack *)malloc(sizeof(LinkStack)); 
	(*S)->count = 0;
	(*S)->top = 0;
	return 0;
}
void DestroyStack(LinkStack *S)//销毁堆栈， 
{
	pNode p;
	p =S->top;
 
	while(p)
		{
			S->top = p->next;
			free(p);
			p = S->top;
		}
	free(S);
}
void ClearStack(LinkStack *S)//清空堆栈 所有元素初始化为0
{	
		pNode p;
		p =S->top;
 
	while(p)
		{
			S->top = p->next;
			free(p);
			p = S->top;
		}
}
bool StackEmpty(LinkStack S)
{
	if(S.top)
		return 0;
	else 
		return 1;
 
}
int  StackLength(LinkStack *S)
{
	return (*S).count;
}
void GetTop(LinkStack *S,Datatype &e)
{
	if(S->top)
	e = S->top->data;
 
}
bool Push(LinkStack *S, Datatype e)//入栈操作
{
	pNode p = (Node *) malloc( sizeof(Node));
 
	p->data = e;
	p->next = S->top;
	S->top = p;
 
	S->count++;
 
	return 1;
}
bool Pop(LinkStack *S, Datatype &e)
{
	pNode p = S->top;
 
	if(StackEmpty(*S))
		return 0;
	e= p->data;
	S->top = p->next;
	free(p);
	
	S->count --;
	return 1;
}
void StackPrint(LinkStack S)
{
	pNode p;
	p = S.top;
 
	while( p )
	{	
		printf("%d\t", p->data);
		p = p->next;
	}
 
}
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int *base;//栈底 
	int *top;//栈顶 
	int stack;//最大空间 
}sqs;
void InitStack(sqs *s)//初始化栈 
{
	s->base = (int *)malloc(100 * sizeof(int));
	s->top = s->base;//最初栈顶和栈底重合 
	s->stack = 100;//栈的最大容量 
}

void Push(sqs *s,int e)///入栈 
{
	if(s->top - s->base >= s->stack){
		s->base = (int *)realloc(s->base, (s->stack + 10) * sizeof(int));//重新申请一段长度为s->stack+10的空间，并将原来的数据复制过去 
		s->top = s->base + s->stack;//设置栈顶
		s->stack = s->stack + 10;//设置栈的最大容量 
	}
	*(s->top) = e;
	s->top++;
}

void Pop(sqs *s)//出栈
{
	if(s->top == s->base)//栈为空栈 
		return;
	while(s->top - 1 != s->base)
		printf("%d ",*--(s->top));
	printf("%d\n",*(--s->top));
}





int protiety(char a ){
  if(a=='(') return 6;
  if(a=='=') return 0;
  if (a=='*'||a=='/') return 4;
  if(a=='+'||a=='-') return 2;
  if(a==')') return 1;
}

int sprotiety(char a){
   if(a=='(') return 1;
  if(a=='=') return 0;
  if (a=='*'||a=='/') return 5;
  if(a=='+'||a=='-') return 3;
  if(a==')') return 6;
}

int  main() {
    sqs *pStack1;//shu zi zhan
    sqs *pStack2;//fu hao zhan
 
	InitStack(&pStack1);
    InitStack(&pStack2);
    int i=0,j,tem0,tem1,tem2,tem3;
   char a[20];
   scanf( "%c",&a);
   while(1){
    for (i=0;i<20;i++){
        j=*(pStack2->top);
    if(a!='+'&&a!='-'&&a!='*'&&a!='/'&&a!='('&&a!=')')
        Push(pStack1,&a);
        continue;
     if(protiety(a)>sprotiety(j) )
    
        Push(pStack2,&a); 
        else 
        {
            Pop(pStack1,&tem0);
            Pop(pStack1,&tem1);
            Pop(pStack2,&tem2);
            if(tem2=='+') tem3=tem0+tem1;
            if(tem2=='-') tem3=tem0-tem1;
            if(tem2=='*') tem3=tem0*tem1;
            if(tem2=='/') tem3=tem1/tem0;
            Push(pStack1,&tem3);
            push(pStack2,&a);
        }
       if(a=='='){
           while(pStack2->top!=NULL){
           Pop(pStack1,&tem0);
            Pop(pStack1,&tem1);
            Pop(pStack2,&tem2);
            if(tem2=='+') tem3=tem0+tem1;
            if(tem2=='-') tem3=tem0-tem1;
            if(tem2=='*') tem3=tem0*tem1;
            if(tem2=='/') tem3=tem1/tem0;
            Push(pStack1,&tem3);
           }

           Pop(pStack1,&tem0);
           printf("%d",tem0);


       }   
    }
   }


    return 0;
}


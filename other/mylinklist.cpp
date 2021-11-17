#include<stdio.h>
#include<iostream>
typedef struct linklist{
  char data;
  int value;
  struct linklist* next;
}my_linklist;
my_linklist* head;
my_linklist* end;
my_linklist* node;
void init(){
    head=(my_linklist*)malloc(sizeof(my_linklist));
    end=head;
}
int main(){
 char a[10]={'a','b','v','g','4',' '};
 init();
 
 for(int i=0;i<10;i++){
  node=(my_linklist*)malloc(sizeof(my_linklist));
  node->data=a[i];
  end->next = node;//尾插法
  end=node; 
 }

end->next=NULL;
node=head->next;
while(node!=end){
 printf("%c",(node->data));
 node=node->next;
}
system("pause");
return 0;
}
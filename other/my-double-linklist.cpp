#include<stdio.h>
#include <stdlib.h>

typedef struct doublelinklist{
    char data;
   struct doublelinklist* pre;
    struct doublelinklist* next;
}list;
list* head;
list* end;
list* node;
//初始化
void init(){
 head = (list*)malloc(sizeof(list));//分配空间
 end = head;
}
//插入
void insert(char value){

    node=(list*)malloc(sizeof(list));
    node->data=value;
    printf("perfectly insert %c\n",node->data);
    node->pre=end;
    end->next=node;
    
    end=node;
   
}
//遍历
int vist(){
      node=head->next;
    while(node!=end){
    printf("vist %c\n",node->data);
    node=node->next;
    }
    printf("vist %c\n",end->data);
   return 0;

}           
//删除链表
void linkfree(){
    list* p;
    node=head;
    while(node!=end){
        
        p=node;
        p->pre->next=p->next;
        p->next->pre=p->pre;
        printf("scucessfully free %c\n",p->data);
      free(p);
       //node=node->next; 
       
    }
}


int main() {
     init();
     insert('a');
     insert('b');
     insert('c');
     vist();    
     linkfree();
     system("pause");
     return 0;
}
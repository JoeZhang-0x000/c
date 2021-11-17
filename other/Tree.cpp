#include"stdio.h"
typedef struct Tree
{
    int data;
    struct Tree *lc;
    struct Tree *rc;
}tree;
//创建
tree* node;
tree* root;
void init(int value){
   root=(tree*)malloc(sizeof(tree));
   root->dada=value;
   node=root;
}

void insert(int value){
    //如果插入的数值大于根节点的值则插到右子树
    if(value>=root->data){ 
        node=(tree*)malloc(sizeof(tree));
        node=root->rc;
        node->data=value;
    }                              
//如果插入的数值小于根节点的值插到左子树
else
{
    node=root->lc;
    node=(tree*)malloc(sizeof(tree));
    node->data=value;
}
}

int search(sturct *p){
    printf("%d",p->data);
    if((p=p->rc)!=NULL){
    return search(p);}
    else 
    return 0;
}

int main(){
 init(1);
 insert(2);
 search(root);

system ("pause");
    return 0;
}
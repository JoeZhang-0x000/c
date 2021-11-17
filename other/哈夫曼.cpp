#include<stdio.h>
#include<iostream>
FILE* fp;
char buf[1024];

typedef struct{
 char data;
 int quan;
 struct* next;
}list;

//二叉树的定义
typedef struct Node
{
	char data;
    int value;
	struct Node* LChild;
	struct Node* RChild;
}BiTNode, * BiTree;
//读取节点的值
void Visit(char data)  
{
	printf("%c", data);
}
//前序遍历
void PreOrder(BiTree root)   
{
	if (root != NULL)
	{
		Visit(root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
}
BiTNode *creatBiTree()
{
    char k;
    scanf("%c",&k);
    if(k=='#')
        return NULL;
    BiTNode *T=(BiTNode *)malloc(sizeof(BiTNode));
    T->data=k;
    T->lchild=creatBiTree();
    T->rchild=creatBiTree();
    return T;
}
//读文件
void read(char name){
  if(fp=fopen("name","r")==NULL)
  printf("文件不存在\n");
  else{
      int i=0;
    while(!feof(fp)){
        fsacnf(fp,"c",&buf[i])
        i++;
        }
   fclose(fp);
  }
}
//计算权值
void quan(char* p){
    int buflength=0; //buf  的长度
while(*p!='\0'){
    buflength++;
}
int quan //定义权
list* p->data=buf[0];
p->value=1;
for (int i=0;i<buflength;i++){
    p->next-
}

  }
}

}




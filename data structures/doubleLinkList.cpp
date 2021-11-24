#include<iostream>
using namespace std;
struct DoubleLink{
    int value;
    DoubleLink *pre;
    DoubleLink *next;
};
typedef DoubleLink doubleLink;

//初始化
doubleLink* init(int v){
    doubleLink *head = NULL;
    doubleLink *temp = (doubleLink*)malloc(sizeof(doubleLink));
    temp->value=v;
    temp->next=NULL;
    temp->pre=head;
    head=temp;
    return head;
}
//插入尾部
doubleLink *insertToTail(doubleLink *p,int v){
    doubleLink *temp=p;
    //找到尾节点的前驱
    while(temp->next!=NULL)
        temp=temp->next;
    //创建一个新的节点
    doubleLink *t=(doubleLink*)malloc(sizeof(doubleLink));
    t->value=v;
    t->pre=temp;
    t->next=temp->next;
    temp->next=t;
    return p;
}
//在index处插入元素
doubleLink *insert(doubleLink *p,int v,int index){
    doubleLink *temp = p;
    //插入位置为首节点特殊处理
    if(index==0){
        doubleLink *t=(doubleLink*)malloc(sizeof(doubleLink));
        t->value=v;
        t->next=temp;
        t->pre=temp->pre;
        temp->pre=t;
        p=t;
        return p;
    }
    //找到当前节点的前驱
    for(int i=1;i<index;i++){
        temp=temp->next;
        //若当前节点为尾节点,但是还没有找到前驱就说明不存在index
        if(!temp){
            cout<<"不存在要插入的节点"<<index<<endl;
            return p;
        }
    }

    //创建一个新的节点
    doubleLink *t = (doubleLink*)malloc(sizeof(doubleLink));
    t->value=v;

    //将待插入节点的后继连接上
    t->next=temp->next;
    temp->next->pre=t;

    //将待插入节点的前驱连接上
    t->pre=temp;
    temp->next=t;

    return p;
}

//遍历并打印链表
void visit(doubleLink *p){
    doubleLink *temp = p;
    if(!temp)
        cout<<"空链表"<<endl;

    //当前节点的后继有节点就继续访问，并打印其value
    while(temp){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//修改节点index处的值
doubleLink* update(doubleLink *p,int index,int value){
    doubleLink* temp=p;
    
    //找到当前节点的前驱
    for(int i=1;i<index;i++){
        temp=temp->next;
        //若当前节点为尾节点,但是还没有找到前驱就说明不存在index
        if(!temp){
            cout<<"不存在要修改的节点"<<index<<endl;
            return p;
        }
    }
    
    //修改当前节点的值
    temp->next->value=value;
    return p;
}
//删除节点
doubleLink* del(doubleLink* p,int index){
    doubleLink* temp=p;
    //找到需要删除节点
    for(int i=0;i<index;i++){
        temp=temp->next;
        if(!temp){
            cout<<"需要删除的节点不存在"<<index<<endl;
            return p;
        }
    }
    //del 即为待删除节点
    doubleLink *del = temp;
    //将要删除节点的后继的前驱设为其前驱
    temp->next->pre=temp->pre;
    //将前驱的后继设为要删除节点的后继
    temp->pre->next=temp->next;
    //始放内存
    free(del);
    return p;
}

//销毁
void delAll(doubleLink *p){
    doubleLink *temp=p;
    doubleLink *t;
    while(temp){
        t=temp;
        temp=temp->next;
        free(t);
        visit(temp);
    }
}

int main(){
    doubleLink *p = init(9);
    for(int i =1;i<6;i++)
        p=insertToTail(p,i);
    visit(p);
    p=insert(p,77,1);
    visit(p);
    delAll(p);
    
    return 0;

}
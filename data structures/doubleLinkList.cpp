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
    doubleLink *p = NULL;
    doubleLink *temp = (doubleLink*)malloc(sizeof(doubleLink));
    temp->value=v;
    temp->next=NULL;
    p=temp;
    return p;
}
//在index处插入元素
doubleLink *insert(doubleLink *p,int v,int index){
    doubleLink *temp = p;
    //找到要插入的节点的前驱
    for(int i =1;i<index-1;i++){
        temp=temp->next;
        if(!temp){
            cout<<"插入位置无效"<<endl;
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

    //释放内存
    free(t);
    return p;
}

//遍历并打印链表
void visit(doubleLink *p){
    doubleLink *temp = p;

    //当前节点的后继有节点就继续访问，并打印其value
    while(temp->next){
        temp=temp->next;
        cout<<temp->value<<" ";
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
        if(temp){
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

int main(){
    doubleLink *p = init(9);
    for(int i =1;i<6;i++)
        p = insert(p,i,i);
    visit(p);
    return 0;

}
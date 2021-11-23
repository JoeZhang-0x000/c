#include<iostream>
using namespace std;
typedef struct List {
    int value;
    List *next;
}list;
list init(int v){
    list l;
    l.value = v;
    l.next=NULL;
    return l;
}
list* initLink(){
    list *p =NULL;
    list *temp = (list*)malloc(sizeof(list));
    temp->value=1;
    temp->next=NULL;
    p=temp;
    for(int i =2;i<5;i++){
        list* a=(list*)malloc(sizeof(list));
        a->value=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}

void visit(list *l){
    list *temp=l;
    while(temp){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

list* insert(list *p,int v,int index){
    list* temp = p;
    //找到要插入的元素的上一个节点
    for(int i =1;i<index;i++){
        temp = temp->next;
        if(!temp){
            cout<<"插入位置无效"<<endl;
            return p;
        }
    }
    //创建一个新节点
    list *l = (list*)malloc(sizeof(list));
    l->value=v;
    l->next=temp->next;
    temp->next=l;
    return p;
}

list* deleteList(list *p,int index){
    list *temp = p;
    //找到要删除的节点的前一个节点
    for(int i =1;i<index;i++){
        temp=temp->next;
        //若要找的节点不存在就报错
        if(!temp){
            cout<<"要删除节点不存在"<<endl;
            return p;
        }
    }

    //经理了上一步现在的temp指向的是要删除的节点的前驱
    list *del = temp->next;
    temp->next=temp->next->next;
    free(del);
    return p;
}

int select(list *p,int v){
    list *temp = p;
    int index = 0;
    while(temp->next!=NULL){
        index++;
        temp=temp->next;
        if(temp->value==v){
            cout<<"找到了，在"<<index<<endl;
            return index;
        }
    }
    cout<<"没有找到！"<<endl;
    return -1;
}
list *update(list *p,int index,int value){
    list*temp = p;
    for(int i =1;i<index;i++){
        if(!temp){
            cout<<"没有这个节点！"<<endl;
            return p;
        }
        temp=temp->next;
    }
    temp->next->value=value;
    cout<<"更新成功!"<<endl;
    return p;
}
int main(){
    list *p = initLink();
    visit(p);
    insert(p,10,4);
    insert(p,9,5);
    visit(p);
    select(p,4);
    deleteList(p,3);
    visit(p);
    select(p,4);
    select(p,9);
    update(p,2,9);
    visit(p);
    select(p,9);
    return 0;

}
#include<iostream>
#include<list>
using namespace std;

const int num =10;
int count = 0;
list<int> A,B,C;

void print_hanoi(){
    cout<<"A: ";
    for(auto it = A.begin();it!=A.end();it++)
        std::cout<<*it<<" ";
    cout<<endl;
    cout<<"B: ";
    for(auto it = B.begin();it!=B.end();it++)
        std::cout<<*it<<" ";
    cout<<endl;
    cout<<"C: ";
    for(auto it = C.begin();it!=C.end();it++)
        std::cout<<*it<<" ";
    cout<<endl;
    cout<<"*********************"<<endl;
}
void move(list<int> &a,list<int> &b){
    count++;
    int tem = a.back();
    b.push_back(tem);
    a.pop_back();
    print_hanoi();
}
void move_hanoi(char a,char b){
    list<int> *pa,*pb;
    if(a=='A')
        pa = &A;
    if(a=='B')
        pa = &B;
    if(a=='C')
        pa = &C;
    if(b=='A')
        pb = &A;
    if(b=='B')
        pb = &B;
    if(b=='C')
        pb = &C;
    move(*pa,*pb);
}
void hanoi_solve(char a,char b,char c,int n){
    if(n==1){
        cout<<"no "<<count<<" move "<<a<<" to "<<c<<endl;
        move_hanoi(a,c);
        return;
    }
    //先把A上的n-1个移动到B上，再把A上最后一个移动到C
    hanoi_solve(a,c,b,n-1);   
    cout<<"no "<<count<<" move "<<a<<" to "<<c<<endl;
    move_hanoi(a,c);
    //再把B上的n-1个移动到A上，把B上的最后一个移动到C
    hanoi_solve(b,a,c,n-1);
}


int main(){
    char a = 'A';
    char b = 'B';
    char c = 'C';
    for(int i =0;i<num;i++)
        A.push_back(num-i);
    print_hanoi();

    hanoi_solve(a,b,c,num);
    cout<<"total count:"<<count;
    return 0;
}
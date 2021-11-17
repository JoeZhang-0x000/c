#include<iostream>
using namespace std;
int pickTopDisk(char *current,char x){
    int i =0;
    while(current[i]!=x)
        i++;
    return i;
}
void hanoi(char *current,int n,char A,char B,char C){
    static int count = 0;
    int i =0;
    if(n==1){
        i=pickTopDisk(current,A);
        current[i]=C;
        count++;
        cout<<"move "<<count<<" disk "<<(i+1)<<" : "<<A<<"->"<<C<<endl;
        return;
    }
    hanoi(current,n-1,A,C,B);
    current[n-1]=C;
    count++;
    cout<<"move "<<count<<" disk "<<(i+1)<<" : "<<A<<"->"<<C<<endl;
    hanoi(current,n-1,B,A,C);

}
int main(){
    char current[]={'A','A','A','A'};
    char A='A',B='B',C='C';
    hanoi(current,4,A,B,C);
    return (EXIT_SUCCESS);

}
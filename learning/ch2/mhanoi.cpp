#include<iostream>
using namespace std;

int pickToDisk(char* current,char A){
    int i =0;
    while(current[i]!=A)
        i++;
    return i;
}
void solve(char *current,int n,char A,char B,char C){
    static int count =0;
    if(n==1){
        int i =0;
        i = pickToDisk(current,A);
        current[i]=C;
        count++;
        cout<<"move:"<<count<<" disk "<<i+1<<" "<<A<<"->"<<C<<endl;
        return;
    }
    solve(current,n-1,A,C,B);
    current[n-1]=C;
    count++;
    cout<<"move:"<<count<<" disk "<<n<<" "<<A<<"->"<<C<<endl;
    solve(current,n-1,B,A,C);
}
int main(){
    char current[]={'A','A','A','A'};
    char A='A',B='B',C='C';
    solve(current,4,A,B,C);
    return (1);
}
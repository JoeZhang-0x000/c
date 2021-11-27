#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
struct Pair{
    int *c;
    int *b;
};
Pair lcs_length(char *x,int nx,char *y,int ny){
    int m=nx;
    int n=ny;
    //创建两个数组，b[i,j]用于指向的表项对应计算c[i,j]时所选择的子问题最优解。
    int *b=(int*)malloc(m*n*sizeof(int));
    int *c=(int*)malloc((m+1)*(n+1)*sizeof(int));
    Pair pair={b,c};
    for(int i=1;i<m+1;i++)
        //c[i,0]=0
        c[i*(n+1)]=0;
    for(int i=0;i<n+1;i++)
        //c[0,j]=0
        c[i]=0;
    for(int i=1;i<m+1;i++)
        for(int j=1;j<n+1;j++){
            if(x[i]==y[i]){
                //c[i,j]=c[i-1,j-1]
                c[i*(n+1)+j]=c[(i-1)*(n+1)+(j-1)];
                //b[i,j]=1;
                b[i*n+j]=1;
            }
            //if c[i-1,j]>=c[i,j-1]:
            if(c[(i-1)*(n+1)+j]>=c[(i*(n+1)+(j-1))]){
                //c[i,j]=c[i-1,j]
                c[i*(n+1)+j]=c[(i-1)*(n+1)+j];
                //b[i,j]=2
                b[i*n+j]=2;
            }
            //if c[i-1,j]<c[i,j-1]:
            else{
                //c[i,j]=c[i,j-1];
                c[i*(n+1)+j]=c[i*(n+1)+(j-1)];
                //b[i,j]=3
                b[i*n+j]=3;
            }
        }
    return pair;
}
void print_lcs(int *b,int n,char *x,int i,int j){
    if(i==0||j==0)
        return;
    //if b[i,j]==1:
    if(b[i*n+j]==1){
        print_lcs(b,n,x,i-1,j-1);
        cout<<x[i];
    }
    //if b[i,j]==2:
    if(b[i*n+j]==2)
        print_lcs(b,n,x,i-1,j);
    else
        print_lcs(b,n,x,i,j-1);
}
int main(){
    char x[]={'a','b','c','d','e','f'};
    int n=sizeof(x)/sizeof(char);
    char y[]={'b','c','f'};
    int m=sizeof(y)/sizeof(char);
    int *b =lcs_length(x,n,y,m).b;
    int *c =lcs_length(x,n,y,m).c;
    print_lcs(b,m,x,n,m);
    for(int i=0;i<n*m;i++){
        cout<<b[i]<<" ";
        if((i+1)%m==0)
            cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<(n+1)*(m+1);i++){
        cout<<c[i]<<" ";
        if((i+1)%(m+1)==0)
            cout<<endl;
    }

    return 0;
}
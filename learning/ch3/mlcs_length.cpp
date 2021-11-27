#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
int *lcs_length(char *x,char *y,int n_x,int n_y){
    int n=n_x+1,m=n_y+1;
    int *a=(int*)malloc(n*m*sizeof(int));
    memset(a,0,n*m*sizeof(int));
    //自底向上的进行计算，所以我们从小规模的子问题开始做，每次做的是x[0,i]与y[0,j]的最大子序列
    for(int i=1;i<=n_x;i++){
        char ch1=x[i-1];
        for(int j=1;j<=n_y;j++){
            char ch2=y[j-1];
            //有两种种情况,
            //1. x[i]=y[j],
            if(ch1==ch2)
                // a[i][j]=a[i-1][j-1]+1;
                *(a+i*m+j)=*(a+(i-1)*m+j-1)+1;
            //2.x[i]!=y[j]
            else{
                // a[i][j]=a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1];
                int tem1=*(a+(i-1)*m+j);
                int tem2=*(a+i*m+j-1);
                if(tem1>tem2)
                    *(a+i*m+j)=tem1;
                else
                    *(a+i*m+j)=tem2;
            }
        }
    }
    return a;
}
int main(){
    char x[]={'a','b','c','b','d','a','b'};
    int n=sizeof(x)/sizeof(char);
    char y[]={'b','d','c','a','b','a'};
    int m=sizeof(y)/sizeof(char);
    int *a=lcs_length(x,y,n,m);
    for(int i=0;i<10;i++)
        cout<<" ";
    for(int i=0;i<=m;i++)
        if(i>0)
            cout<<setw(10)<<y[i-1];
    cout<<endl;
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            cout<<setw(10)<<a[i*(m+1)+j];
        
        if(i>0)
            cout<<setw(10)<<x[i-1];
        else
            cout<<setfill(' ')<<setw(10);
        cout<<endl;
    }

    return 0;
}
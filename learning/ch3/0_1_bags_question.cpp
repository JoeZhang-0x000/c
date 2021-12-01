#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}

void m_bag(int *w,int *v,int num,int size){
    int dp[num+1][size+1];
    memset(dp,0,(num+1)*(size+1)*sizeof(int)); 
    for(int j=1;j<size+1;j++){
        for(int i=1;i<num+1;i++){
            //放不下第i件物品
            if(j<w[i-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
        }
    }
    for(int i=0;i<num+1;i++){
        for(int j=0;j<size+1;j++)
            cout<<setw(5)<<dp[i][j];
        cout<<endl;
    }

}

int main(){
    int v[]={3,4,5,6};
    int w[]={2,3,4,5};
    int capcity=10;
    m_bag(w,v,sizeof(v)/sizeof(int),capcity);

    return 0;
}
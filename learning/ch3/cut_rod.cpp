#include<iostream>
#include<string.h>
using namespace std;
int max(int *a,int *b){
    return *a>*b?*a:*b;
}
int memoized_cut_rod_aux(int *p,int n,int *r){
    //最大收益
    int q;
    //如果表里面已经记录过切割这个长度的钢条的最大收益，那么久直接引用表中数据
    if(r[n]>=0)
        q=r[n];
    //切割长度为0的钢条，收益为0
    if(n==0)
        q=0;
    //否则需要计算切割这个长度的钢条的最大收益
    else{
        q=INT_MIN;
        //最大收益就是切的任意段的价值中最高的一个,左边切成i段，右边切成n-i段的价值的和
        for(int i=1;i<n+1;i++)
            //p[i]代表的是长度为I的钢条的单价
            q=max(q,p[i]+memoized_cut_rod_aux(p,n-i,r));
        r[n]=q;
    }
    return q;
}
int memoized_cut_rod(int *p,int n){
    //先定义一个数组r,用于保存最优解,r[i]表示切割长度为i的钢条的最优解,显然，r[0]=0,r[]的长度应该为n+1，因为要让r[n]有意义，r[n]就是我们要的值。
    int *r=(int*)malloc((n+1)*sizeof(int));
    // 初始化r,让所有的切割收益为无穷小
    memset(r,INT_MIN,sizeof(r));
    
    return memoized_cut_rod_aux(p,n,r);
}

int main(){
    int p[]={0,1,5,8,9,10,17,17,20,24,30};
    for(int i=0;i<sizeof(p)/sizeof(int);i++)
        cout<<i<<" "<<memoized_cut_rod(p,i)<<endl;
    return 0;
}
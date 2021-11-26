#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
//定义一个结构体去存储两个数组，一个是最优解的价值，另一个是切割方法,这里我们只存储将最左边切割成多长，因为右边部分是更小的子问题，也可以用最左边切割成多长来表示
typedef struct Cut{
    int *r;
    int *s;
}cut;
int max(int *a,int *b){
    return *a>*b?*a:*b;
}

cut bottom_up_cut_rod(int *p,int n){
    //先定义一个数组r,用于保存最优解,r[i]表示切割长度为i的钢条的最优解,显然，r[0]=0,r[]的长度应该为n+1，因为要让r[n]有意义，r[n]就是我们要的值。
    int *r=(int*)malloc((n+1)*sizeof(int));
    // 初始化r,让所有的切割收益为无穷小
    memset(r,INT_MIN,sizeof(r));

    //再定义一个数组s,用于保存最优的切割方法，
    int *s=(int*)malloc((n+1)*sizeof(int));
    memset(s,INT_MIN,sizeof(s));
    cut ret={r,s};
    //最大收益
    int q;
    //现在采用自然增长模式对子问题进行求解,j代表着要求解的子问题的长度，它将从1开始到n，n即为我们要求解的最终问题
    for(int j=1;j<n+1;j++){
        q=INT_MIN;
        //求解模块为j的问题,那么也就是把长度为j的钢条分割的所有可能中最大的一种
        for(int i=0;i<=j;i++){
            // q=max(q,p[i]+r[j-i]);
            if(q<(p[i]+r[j-i])){
                q=p[i]+r[j-i];
                s[j]=i;
            }
        }
        r[j]=q;
    }
    return ret;   
}

int main(){
    int p[]={0,1,5,8,9,10,17,17,20,24,30};
    Cut cut=bottom_up_cut_rod(p,sizeof(p)/sizeof(int)-1);
    for(int i=0;i<sizeof(p)/sizeof(int);i++){
        cout<<setw(4)<<i;
    }
    cout<<endl;
    for(int i=0;i<sizeof(p)/sizeof(int);i++){
        cout<<setw(4)<<cut.r[i];
    }
    cout<<endl;
    for(int i=0;i<sizeof(p)/sizeof(int);i++){
        cout<<setw(4)<<cut.s[i];
    }
    cout<<endl;
    return 0;
}
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
//定义一个结构体，包含两个数组指针，将会用到来返回我们的结果
struct Answer
{
    int *m;
    int *s;
};
Answer martix_chain(int *p,int n){
    //m[i,j]代表着计算i,j加括号的代价,因为要和p是n维的
    int *m=(int*)malloc(n*n*sizeof(int));
    //初始化m
    memset(m,0,sizeof(m));
    //s[i,j]代表着加括号的顺序
    int *s=(int*)malloc(n*n*sizeof(int));
    //初始化
    memset(s,0,sizeof(s));
    Answer answer ={m,s};

    //m[i,i]=0,
    for(int i=0;i<n;i++)
        m[i*n+i]=0;
    //原问题是计算长度为n的矩阵链，子问题是计算长度为L的矩阵链,那么l从2开始扫描，因为l=1时候没有意义,l最长是n-1
    for(int l=2;l<n;l++){
        //计算子问题时候，设第一次将左边i个划分在一起是最优解
        for(int i=1;i<=n-l+1;i++){
            //因为是从i开始长度为L的子链，那么这个子链末尾j的下标应该是i+l-1
            int j=i+l-1;
            //问题转化成为了球m[i,j]最优解，先把其初始化为无穷大
            m[i*n+j]=INT_MAX;
            //现在将m[i,j]划分成为很多子链，我们只需要算最左边的子链的最优解即可，因为左边是最优解，那么右边一定也是
            for(int k=i;k<j;k++){
                //这里m[i,k]+m[k+1,j]分别是计算子链i...k和k+1...j的最优解，也就是在k处画括号后分别计算两边的子矩阵链所花费的乘法次数，而p[i-1]*p[k]*p[j]是说将画完括号的两个矩阵再相乘需要的乘法次数
                int q=m[i*n+k]+m[(k+1)*n+j]+p[i-1]*p[k]*p[j];
                //常规的比较大小，寻找更优解,并且将其划分的方式记录再s矩阵里面
                if(q<m[i*n+j]){
                    m[i*n+j]=q;
                    s[i*n+j]=k;
                }
            }
        }
    }

    return answer;
}

//打印最优解的过程
void print_optimal_parens(int *s,int n,int i,int j){
    if(i==j)
        cout<<"A"<<i;
    else{
        cout<<"(";
        print_optimal_parens(s,n,i,*(s+i*n+j));
        print_optimal_parens(s,n,*(s+i*n+j)+1,j);
        cout<<")";
    }

}
void print_optimal_value(int *m,int n,int i,int j){
    cout<<*(m+i*n+j);
}

int main(){
    int p[]={30,35,15,5,10,20,25};
    int n=sizeof(p)/sizeof(int);
    //u,v是两个下标，u是第一个矩阵的行数再p[]中的下标，v是最后一个矩阵的列数再p[]中的下标,比如这里我们计算A(35x15)*A(15x5)...*A(20x25),就取u=1,v=6
    int u=1,v=6;
    Answer a=martix_chain(p,n);
    //打印乘法次数矩阵
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<setw(20)<<*(a.m+i*n+j);
        cout<<endl;
    }
    cout<<endl;

    //打印最优解的划分方式矩阵
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++)
            cout<<setw(20)<<*(a.s+i*n+j);
        cout<<endl;
    }

    cout<<"最优解的乘法次数为：";
    print_optimal_value(a.m,n,u,v);
    cout<<endl;
    cout<<"最优解划分方式为: ";
    print_optimal_parens(a.s,n,u,v);
    cout<<endl;


    return 0;
}
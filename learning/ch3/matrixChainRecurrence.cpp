#include<iostream>
#include<iomanip>
using namespace std;
typedef struct {
    void *first;
    void *second;
} Pair;
Pair make_pair(void *f,void *s){
    Pair p={f,s};
    return p;
}
Pair matrixChainOrder(int *p,int n){
    int i,l,j,k,q;
    int *m=(int*)malloc((n+1)*(n+1)*sizeof(int));
    int *s=(int*)malloc((n+1)*(n+1)*sizeof(int));
    for(i=0;i<=n;i++)
        m[i*(n+1)+i]=0;//m[i,i]=0
    for(l=2;l<=n;l++)//l是子矩阵链的长度
        for(i=1;i<n-l+1;i++){
            j=i+l-1;
            m[i*(n+1)+j]=99999;//m[i,j]=infinity
            for(k=i;k<=j-l;k++){
                q=m[i*(n+1)+k]+m[(k+1)*(n+1)+j]+p[i-1]*p[k]*p[j];//q=m[i,k]+m[k+1,j]+pi-1*pk*pj
                if(q<m[i*(n+1)+j]){//q<m[i,j]
                    m[i*(n+1)+j]=q;//m[i,j]=q
                    s[i*(n+1)+j]=k;//s[i,j]=k
                }
            }
        }
    return make_pair((void*)m,(void*)s);
}

void printOptimalParens(int *s,int i,int j,int n){
    if(i==j)
        cout<<"A"<<i;
    else{
        cout<<"(";
        printOptimalParens(s,i,s[i*(n+1)+j],n);
        printOptimalParens(s,s[i*(n+1)+j]+1,j,n);
        cout<<")";
    }

}

int main(){
    int p[]={30,35,15,5,10,20,25};
    int *s,*m;
    Pair r=matrixChainOrder(p,6);
    m=(int*)r.first;
    s=(int*)r.second;
    // printOptimalParens(s,1,6,6);
    cout<<endl;
    for(int i =0;i<7*7;i++){
        cout<<setw(11)<<*(m+i)<<" ";
        if((i+1)%7==0)
            cout<<endl;
    }
    free(s);
    free(m);

    return 0;
}
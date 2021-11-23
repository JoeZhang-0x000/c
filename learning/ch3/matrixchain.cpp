#include<iostream>
using namespace std;
typedef struct{
    void *first;
    void *second;
}pair;
pair make_pair(void *f,void *d){
    pair p ={f,d};
    return p;
}
pair matrixChainOrder(int *p,int n){
    int i,j,k,q;
    int *m=(int*)malloc((n+1)*(n+1)*sizeof(int));
    int *s=(int*)malloc((n+1)*(n+1)*sizeof(int));
    for(i=0;i<=n;i++)
        m[i*(n+1)+i]=0;
}
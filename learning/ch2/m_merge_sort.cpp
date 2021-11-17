#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int intGreater(void *a,void *b){
    return (*((int*)a)-*((int*)b));
}
void echoa(void *a,int size){
    for(int i =0;i<size;i++)
        cout<<*((int*)(a+i*4))<<" ";;
    cout<<endl;
}
void merge(void *a,int size,int p,int q,int r,int(*comp)(void *,void *)){
    int i,j,k,n1=q-p+1,n2=r-q;
    void *L = (void*)malloc(n1*size);
    void *R = (void*)malloc(n2*size);
    memcpy(L,a+p*size,n1*size);
    memcpy(R,a+(q+1)*size,n2*size);

    i = 0,j = 0,k = p;
    while(i<n1&&j<n2)
        if(comp(L+i*size,R+j*size)<0)
            memcpy(a+(k++)*size,L+(i++)*size,size);
        else
            memcpy(a+(k++)*size,R+(j++)*size,size);

    while(i<n1)
        memcpy(a+(k++)*size,L+(i++)*size,size);

    while(j<n2)
        memcpy(a+(k++)*size,R+(j++)*size,size);

    // if(i<n1)
    //     memcpy(a+k*size,L+i*size,(n1-1)*size);
    // if(j<n2)
    //     memcpy(a+k*size,R+j*size,(n2-j)*size);

    free(L);
    free(R);

}


void mergesort(void *a,int size,int p,int r,int(*comp)(void*,void*)){
    if(p<r){
        int q = (p+r)/2;
        mergesort(a,size,p,q,comp);
        mergesort(a,size,q+1,r,comp);
        merge(a,size,p,q,r,comp);
    }

}
int main(){
    const int n =10;
    int a[n] = {9,3,0,5,5,0,2,7,4,4};
    srand(time(NULL));
    for(int i=0;i<n;i++)
        a[i]=rand()%10;
    
    echoa(a,n);
    // merge(a,sizeof(int),0,4,9,intGreater);
    mergesort(a,sizeof(int),0,n,intGreater);

    echoa(a,n);

    return 0;
}
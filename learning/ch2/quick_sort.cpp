#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//compare two integer,return the distance
int intGreater(void* a,void*b){
    return (*(int*)a-*(int*)b);
}
//打印数组
void pa(void *a,int size,int l){
    cout<<"a:";
    for(int i =0;i<l;i++)
        cout<<*(int*)(a+i*size)<<" ";
    cout<<endl;
}
//交换两个元素的值
void swap(void*a,void*b,int size){
    void* tem = (void*)malloc(size);
    memcpy(tem,a,size);
    memcpy(a,b,size);
    memcpy(b,tem,size);
    free(tem);
}
//将数组A中p,r的元素划分为两类，其中左边的元素都小于A[r],右边的元素都大于A[r]
int partition(void *A,int size,int p,int r,int (*comp)(void*,void*)){
    int i,j;
    void *key = (void*)malloc(size);
    //key = A[p]
    memcpy(key,A+r*size,size);

    //i,j维护了两个序列，期中p,i的元素都小于key,而j是从p,r的扫描
    //那么其实i-p+1就是比Key小的数字的个数，每次如果扫描到一个数字比key小，那么i就应该+1,
    //然后我们新扫描到的元素应该就置于比key小的序列的末尾了，所以是swap(A[i],A[j])
    i =p-1;
    for(j = p;j<r;j++){
        if(comp(key,A+j*size)>=0){
            i++;
            swap(A+i*size,A+j*size,4);
        }
    }
       free(key);
       //当扫描到r-1之后，此时的i指向了一个元素，这个元素应该是比key小的最后一个元素，那么key
       //应该被置于i+1这个位置。
        i++;
        swap(A+r*size,A+i*size,size);
        return i;
    }

//对p,q的子序列进行排序
void quickSort(void *A,int size,int p,int q,int(*comp)(void*,void*)){
    if(p<q){
        //让p,q之前的随机一个数字作为key
        //随机交换一个数字和 A[r]
        int tem = rand()%(q-p)+p;
        swap(A+tem*size,A+p*size,4);
        int m = partition(A,4,p,q,comp);
        quickSort(A,4,p,m-1,comp);
        quickSort(A,4,m+1,q,comp);
    }
}


int main(){
    srand(time(NULL));
    const int n = 10;
    int a[n] = {3,5,1,2,3,5,6,7,3,4};
    pa(a,4,n);
    quickSort(a,4,0,9,intGreater);
    pa(a,4,n);
    return 0;
}
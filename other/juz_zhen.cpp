#include<stdio.h>
#include<windows.h>


// zuo cheng fa 
void mulit(int m, int n, int p,int*a,int *b, int *c){
   for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            *(c+i*n+j)=0;
            for(int k=0;k<p;k++){
                *(c+i*n+j)+=*(a+i*n+k)**(b+k*n+j);
            }
        }
    }
 
}


int main(){
    ////////////////////////////////
  int juzhen1[100][100];
  int juzhen2[100][100];
  int juzhen3[100][100];
  int a,b,c;
  /***********************************/
  printf("please input the size:\n");
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  printf("please input the value  of juzhen1:\n");
  for(int i=0;i<a;i++){
      for(int j=0;j<b;j++){
          scanf("%d",&juzhen1[i][j]);
      }
  }
   printf("please input the value  of juzhen2:\n");
  for(int i=0;i<b;i++){
      for(int j=0;j<c;j++){
          scanf("%d",&juzhen2[i][j]);
      }
  }
   
  for(int i=0;i<a;i++){
      for(int j=0;j<c;j++){
          juzhen3[i][j]=0;
      }
  }
  int *a1=juzhen1[0];
  int *b1=juzhen2[0];
  int *c1=juzhen3[0];
 /////////////////////////////////////
mulit(a,b,c,a1,b1,c1);
/*************************************/

for(int i=0;i<a;i++){
    for(int j=0;j<c;j++){
        if(j==c-1) printf("\n");
        printf("%d    ",juzhen3[i][j]);
    }
}


system("pause");
return 0;
}
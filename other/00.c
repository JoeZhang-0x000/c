#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define times0 200
#define times1 1000
int main() {
srand((unsigned)time(NULL));
 int a[10][10];
 int i=0;  //矩阵的行标 
 int j=0;     //矩阵的列标 
 int c=0; //用于记录实验的次数 
 int x,y;
 int tem; 
 double p=0;
// int aa=0; //引入这个变量为了防止进入死胡同导致算法异常终止，我会让他进入死胡同时候这个值变为1，然后直接进入下一个实验 
 int sun=0; //这个变量用于统计进入死胡同的次数 
 int sum=0; //用于记录总共收敛的次数            
 A:{	
 while(c<times1) {  //我做了  times1 次模拟 
 c++; //每次执行时候总执行次数加1 
 // aa=0; //每次新的循环开始时候先把这个防止进入死胡同的锁恢复 
 for (i=0;i<10;i++){      //每次都先把矩阵初始化 
    for(j=0;j<10;j++)
    a[i][j]=0;} 
   x=5;
   y=5;
   int t=0;
   
   
    while(!a[5][5]){    //如果在  times0 步里面没有收敛那么认为这次失败 
        t++;
        if(t==times0) {      
        	sun++;
        	goto A;
		}
    
    for (i=0;i<10;i++)   //用于按照 10*10 的格式打印矩阵 
     for(j=0;j<10;j++){
	 //if(aa==1) break; 
    printf("%d\t",a[i][j]);
    if(j==9) printf("\n");
    if(i==9&&j==9) printf("\n") ;  //为了美观打印 
      
      tem=1;    //这里相当于一个锁， 保证每次只朝一个方向前进  
     switch (rand()%4) //四种不同方向的随机前进 
     { 
     case 0:
         if(x++!=9){  //加入有一条路不通了，那么就走下一条路 
		 
         a[x][y]+=1;
         if(x==10||y==10){
         	sun++;
		  printf(" \n进入了死胡同第%d次\n",sun);
		  goto A;}
          if(--tem==0) break; 
     }
         //break;
         case 1:
         if(y++!=9){
		 
         a[x][y]+=1;
         if(x==10||y==10){
         	sun++;
		  printf(" \n进入了死胡同第%d次\n",sun);
		  goto A;}
         if(--tem==0) break; 
         }//break;
         case 2:
         if(x--!=0){
         a[x][y]+=1;
         if(x==10||y==10){
         	sun++;
		  printf("\n进入了死胡同第%d次\n",sun);
		  goto A;}
          if(--tem==0) break; 
         }//break;
         case 3:
         if(y--!=0){
		 
         a[x][y]+=1;
         if(x==10||y==10){
         	sun++;
		  printf("\n进入了死胡同第%d次\n",sun);
		  goto A;}
         if(--tem==0) break; 
         }//break;
     
     default:
     	sun++;
		printf("\n进入了死胡同第%d次\n",sun);
     	//aa=1;
     	goto A;
        // break;
     }
       }
    
}

}//这是我的A语句的末尾括号 
 if (a[5][5]!=0){
 printf("a[5][5]=%d,a[5][6]=%d\n",a[5][5],a[5][6]);
 sum++;
}

}
printf("\n总共收敛了%d",sum);
printf("\n总共进入死胡同%d次\n",sun);
p=sum*1.0/times1;
printf("\n所以该算法本次实验%d次的收敛率为%f",times1,p*100);
printf("%%");
 return 0;
}

 

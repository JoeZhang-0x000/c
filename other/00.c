#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define times0 200
#define times1 1000
int main() {
srand((unsigned)time(NULL));
 int a[10][10];
 int i=0;  //������б� 
 int j=0;     //������б� 
 int c=0; //���ڼ�¼ʵ��Ĵ��� 
 int x,y;
 int tem; 
 double p=0;
// int aa=0; //�����������Ϊ�˷�ֹ��������ͬ�����㷨�쳣��ֹ���һ�������������ͬʱ�����ֵ��Ϊ1��Ȼ��ֱ�ӽ�����һ��ʵ�� 
 int sun=0; //�����������ͳ�ƽ�������ͬ�Ĵ��� 
 int sum=0; //���ڼ�¼�ܹ������Ĵ���            
 A:{	
 while(c<times1) {  //������  times1 ��ģ�� 
 c++; //ÿ��ִ��ʱ����ִ�д�����1 
 // aa=0; //ÿ���µ�ѭ����ʼʱ���Ȱ������ֹ��������ͬ�����ָ� 
 for (i=0;i<10;i++){      //ÿ�ζ��ȰѾ����ʼ�� 
    for(j=0;j<10;j++)
    a[i][j]=0;} 
   x=5;
   y=5;
   int t=0;
   
   
    while(!a[5][5]){    //�����  times0 ������û��������ô��Ϊ���ʧ�� 
        t++;
        if(t==times0) {      
        	sun++;
        	goto A;
		}
    
    for (i=0;i<10;i++)   //���ڰ��� 10*10 �ĸ�ʽ��ӡ���� 
     for(j=0;j<10;j++){
	 //if(aa==1) break; 
    printf("%d\t",a[i][j]);
    if(j==9) printf("\n");
    if(i==9&&j==9) printf("\n") ;  //Ϊ�����۴�ӡ 
      
      tem=1;    //�����൱��һ������ ��֤ÿ��ֻ��һ������ǰ��  
     switch (rand()%4) //���ֲ�ͬ��������ǰ�� 
     { 
     case 0:
         if(x++!=9){  //������һ��·��ͨ�ˣ���ô������һ��· 
		 
         a[x][y]+=1;
         if(x==10||y==10){
         	sun++;
		  printf(" \n����������ͬ��%d��\n",sun);
		  goto A;}
          if(--tem==0) break; 
     }
         //break;
         case 1:
         if(y++!=9){
		 
         a[x][y]+=1;
         if(x==10||y==10){
         	sun++;
		  printf(" \n����������ͬ��%d��\n",sun);
		  goto A;}
         if(--tem==0) break; 
         }//break;
         case 2:
         if(x--!=0){
         a[x][y]+=1;
         if(x==10||y==10){
         	sun++;
		  printf("\n����������ͬ��%d��\n",sun);
		  goto A;}
          if(--tem==0) break; 
         }//break;
         case 3:
         if(y--!=0){
		 
         a[x][y]+=1;
         if(x==10||y==10){
         	sun++;
		  printf("\n����������ͬ��%d��\n",sun);
		  goto A;}
         if(--tem==0) break; 
         }//break;
     
     default:
     	sun++;
		printf("\n����������ͬ��%d��\n",sun);
     	//aa=1;
     	goto A;
        // break;
     }
       }
    
}

}//�����ҵ�A����ĩβ���� 
 if (a[5][5]!=0){
 printf("a[5][5]=%d,a[5][6]=%d\n",a[5][5],a[5][6]);
 sum++;
}

}
printf("\n�ܹ�������%d",sum);
printf("\n�ܹ���������ͬ%d��\n",sun);
p=sum*1.0/times1;
printf("\n���Ը��㷨����ʵ��%d�ε�������Ϊ%f",times1,p*100);
printf("%%");
 return 0;
}

 

#include"stdio.h"
#include"windows.h"

int E=1;
double v=0.2;
double xi, xj ,xk,yi,yj,yk,ui,uj,uk,vi,vj,vk;
double S[3][6];
double D[3][3];
double B[3][6];
double x[6][1];
double y[3][3];
double det(double a, double b, double c, double d){
    return a*d-b*c;
}
void juzhenchangfa(){
    //chu shi hua
    
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            S[i][j]=0;
        }
    }
 for (int i=0;i<6;i++){
    S[0][0]+=D[0][i]*D[i][0];
    S[0][1]+=D[0][i]*D[i][1];
    S[0][2]+=D[0][i]*D[i][2];
    S[0][3]+=D[0][i]*D[i][3];
    S[0][4]+=D[0][i]*D[i][4];
    S[0][5]+=D[0][i]*D[i][5];
    S[1][0]+=D[1][i]*D[i][0];
    S[1][1]+=D[1][i]*D[i][1];
    S[1][2]+=D[1][i]*D[i][2];
    S[1][3]+=D[1][i]*D[i][3];
    S[1][4]+=D[1][i]*D[i][4];
    S[1][5]+=D[1][i]*D[i][5];
    S[2][0]+=D[2][i]*D[i][0];
    S[2][1]+=D[2][i]*D[i][1];
    S[2][2]+=D[2][i]*D[i][2];
    S[2][3]+=D[2][i]*D[i][3];
    S[2][4]+=D[2][i]*D[i][4];
    S[2][5]+=D[2][i]*D[i][5];
 }
    /*
     for(int i=0;i<3;i++){
        for(int k=0;k<6;k++){
        for(int j=0,m=0;j<3;j++,m++){
            S[i][k]+=D[i][j]*B[j][m];
        }
     }
        
    }
    */
}
void print_ying_li_juz_hen(){
   /*
    printf("input E,v\n");
    scanf("%d %d",&E,&v);
    */
    printf("in put xi,xj,xk,yi,yj,yk,ui,uk,vi,vj,vk:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d ",&xi,&xj,&xk,&yi,&yj,&yk,&ui,&uj,&uk,&vi,&vj,&vk);
      B[0][0]=yj-yk;
      
      B[0][2]=yk-yi;
      B[0][4]=yi-yj;
      B[1][1]=-xj+xk;
      B[1][3]=-xk+xi;
      B[1][5]=-xi+xj;
      B[2][0]=det(1,xj,1,xk);
      B[2][1]=-det(1,yi,1,yk);
      B[2][2]=-det(1,xi,1,xk);
      B[2][3]=det(1,yi,1,yk);
      B[2][4]=-det(1,xi,1,xj);
      B[2][5]=-det(1,yi,1,yj);
      D[0][0]=1;
      D[0][1]=v;
      D[0][2]=0;
      D[1][0]=v;
      D[1][1]=1;
      D[1][2]=0;
      D[2][0]=0;
      D[2][1]=0;
      D[2][2]=(1-v)*0.5;
}
void qiuzhi(){
    x[0][0]=ui;
    x[1][0]=vi;
    x[2][0]=uj;
    x[3][0]=vj;
    x[4][0]=uk;
    x[5][0]=vk;

for(int i=0;i<3;i++){
    for (int j=0;j<6;j++){
        y[i][0]=S[0][j]*x[j][0];
    }

}


}

int main (){
    print_ying_li_juz_hen();
    juzhenchangfa();
     for(int i=0;i<3;i++){
         printf("%d \n",y[i][0]);
     }
 /*
     for (int i=0;i<3;i++){
         for (int j=0;j<6;j++){
             if (j%5==0) printf("\n");
             printf("%d",S[i][j]);
         }
     }
     */
    system("pause");
    return 0;
}
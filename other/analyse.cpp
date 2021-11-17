#include "iostream"
#include <math.h>
using namespace std;

//R,L,C的范围，其中R∈[Rl,Rr],L,C，同理
#define Rl 0.01
#define Rr 50
#define Ll 0.01
#define Lr 1
#define Cl 0.001
#define Cr 5

//MAX MIN的理想值
#define MAX 100
#define MIN 10

//置信范围
#define Cigema 0.1
#define Fin 0.1



//num 表示每一层要迭代的总次数
#define num 10

// /**************************************************************/
// //这部分的变量是用于以后优化数据的，
// //Rset 是存储可以置信的R的取值， Lset是对应的L取值，Cset是对应的C取值
// //fin，cigema 这两个数组存对应的 百分误差
// double Rset[10]={0};
// double Lset[10]={0};
// double Cset[10]={0};
// double fin[10]={1};
// double cigema[10]={1};

/******************************************************************/


//判断是否满足两个波峰的取值
bool boolean_true(double max , double min);
//计算最大值百分误差
float caculate_Cigema(double R,double L,double C);
//计算最小值百分误差
float caculate_Fin(double R,double L,double C);
//调用赵哥的函数，并且获取最大最小值的函数
double getmymin();
double getmymax();








int  main(){

    double a=0,b=0;
    double R=0,L=0,C=0;

    float minCigema=1;
    float minFin=1;
    float tem=1000000;

    //   循环按照一定的梯度进行计算
    for (int i=0;(Rl+((Rr-Rl)/num)*i)<Rr;i++){
        for (int j=0;(Ll+((Lr-Ll)/num)*j)<Lr;j++){
            for (int k=0;(Cl+((Cr-Cl)/num)*k)<Cr;k++){ 
                //判断是否可以符合标准
                //a,b两个变量暂时存储 百分误差
               a=caculate_Cigema(Rl+num*i,Ll+num*j,Cl+num*k);
               b=caculate_Fin(Rl+num*i,Ll+num*j,Cl+num*k);
               //如果在容许范围内
               if (boolean_true(a,b))
               {
                   //获得更接近的取值
                   if((a*b)/(a+b)<tem){
                       tem =(a*b)/(a+b);

                       R=Rl+num*i;
                       L=Ll+num*j;
                       C=Cl+num*k;

                   }
               }
            }
        }

            //打印本轮结果
        cout<<"R的合适取值为"<<R<<"/n"
        <<"L的合适取值为"<<L<<"/n"
        <<"C的合适取值为"<<C<<endl;
    }

    /******************/
    char aaa;
    cin>>aaa;
    /**************/
    return 0;
}
//判断是否满足两个波峰的取值
bool boolean_true(double max, double min){
    
    
   
    //如果调用函数取得的最大最小值与预期最大最小值百分误差在可接受范围内
    if  (max<=Cigema&&min<=Fin){
        return true;
    }

    return false;
}

//计算最大值百分误差
float caculate_Cigema(double R,double L,double C){
    double my_MIN=0;
    my_MIN=getmymin();
    return  abs((my_MIN-MIN)/MIN);
}
//计算最小值百分误差
float caculate_Fin(double R,double L,double C){
    double my_MAX=0;
    my_MAX=getmymax();
    return abs((my_MAX-MAX)/MAX);
}


//调用赵哥的函数，并且获取最大最小值的函数
double getmymin(){
    
    return 0;
}

double getmymax(){
    return 0;
}

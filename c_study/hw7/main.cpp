/**
 * @author 张鑫
 * @name hw7
 * @tool:c++20
 * @description:如果无法编译可能是g++版本问题,在压缩包中附有linux编译后的二进制文件。
 *
 * */
 /**
  * ppt ch8:48-52
  * */
#include<iostream>
#include <iomanip>
#include<stdlib.h>
#include<time.h>
#define N 64
using namespace std;
void menu();
void genernddata(float* stable, int row, int col);
void printalldata(float* stable, int row, int col);
void diplaysingledata(float* stable, int sno, int row, int col);
void sdf();

int main() {
    menu();
    return 0;
}

void menu() {
    char ch;
    srand(time(NULL));
    int n = 5;
    int m = 6;
    float scoretable[N][N] = { 0 };



    while (true)
    {
        cout << "please input ur choice:" << endl;
        cout << "G:generate student info" << endl;
        cout << "P:print all scores" << endl;
        cout << "S:print single student scores" << endl;
        cout << "Q:quit the program" << endl;
        cin >> ch;
        switch (ch)
        {
        case 'g':
        case 'G':
            cout << "生成学生总数：" << endl;
            cin >> m;
            cout << "测验总数:" << endl;
            cin >> n;
            genernddata(scoretable[0], n, m);
            break;

        case 'p':
        case 'P':
            printalldata(scoretable[0], n, m);
            break;
        case 's':
        case 'S':
            int scno;
            cout << "input the sno:" << endl;
            cin >> ch;
            scno = ch - '0';
            diplaysingledata(scoretable[0], scno, n, m);
            break;
        case 'q':
        case 'Q':
            return;
        default:
            break;
        }
        cout << setw(20) << setfill('-') << endl;
    }





}
void genernddata(float* stable, int row, int col) {
    int sno;
    float score;
    float* p = stable;
    float tem;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < col; j++) {
            score = float((rand() % 50) + 50);
            *(p + i * N + j) = (score);
        }
        // sno = rand()%1000;
        sno = i;
        *(p + i) = (sno);
    }

    //求每行最大值
    p = stable;
    for (int i = 1; i < row; i++) {
        tem = 0;
        for (int j = 0; j < col; j++)
            // tem = (*(p+N*i+j)>tem)? *(p+N*i+col):tem;
            if (tem < (*(p + N * i + j)))
                tem = *(p + N * i + j);
        //在stable[][col]放MAX
        *(p + N * i + col) = tem;
    }

    //求每行最小值
    p = stable;
    for (int i = 1; i < row; i++) {
        tem = 100;
        for (int j = 0; j < col; j++)
            if (tem > (*(p + N * i + j)))
                tem = *(p + N * i + j);
        //在stable[][col+1]放MIN
        *(p + N * i + col + 1) = tem;
    }

    //求每行平均值
    p = stable;
    for (int i = 1; i < row; i++) {
        int sum = 0;
        tem = 0;
        for (int j = 0; j < col; j++)
            sum += *(p + N * i + j);
        //在stable[][col]放AVG
        *(p + N * i + col + 2) = 1.0 * sum / col;
    }

    //求每列最大值
    p = stable;
    for (int i = 0; i < col; i++) {
        tem = 0;
        for (int j = 1; j < row; j++)
            if (tem < (*(p + j * N + i)))
                tem = *(p + j * N + i);
        //在stable[row+1][i]位置放入最大值
        *(p + (row)*N + i) = tem;
    }

    //求每列最小值
    p = stable;
    for (int i = 0; i < col; i++) {
        tem = 100;
        for (int j = 1; j < row; j++)
            if (tem > (*(p + j * N + i)))
                tem = *(p + j * N + i);
        //在stable[row+2][i]位置放入最小值
        *(p + (row + 1) * N + i) = tem;
    }

    //求每列平均值 
    p = stable;
    for (int i = 0; i < col; i++) {
        int sum = 0;
        for (int j = 1; j < row; j++)
            sum += *(p + j * N + i);
        //在stable[row+3][i]位置放入平均值
        *(p + (row + 2) * N + i) = sum / row;
    }

}

void printalldata(float* stable, int row, int col) {
    float* p = stable;
    for (int i = 0; i < row + 3; i++) {
        if (i == 0) {
            cout << setw(6) << setfill(' ') << "sno:";
            for (int j = 0; j < col; j++) {
                cout << setw(12) << setfill(' ') << *(p + j);
            }
            cout << setw(12) << setfill(' ') << "MAX" << setw(12) << setfill(' ') << "MIN" << setw(12) << setfill(' ') << "AVG" << endl;
        }
        else {
            if (i < row)
                cout << "第" << i << "次:";
            if (i == row)
                cout << setw(6) << setfill(' ') << "MAX:";
            if (i == row + 1)
                cout << setw(6) << setfill(' ') << "MIN:";
            if (i == row + 2)
                cout << setw(6) << setfill(' ') << "AVG:";
            for (int j = 0; j < col + 3; j++) {
                if (i >= row && j >= col)
                    continue;
                cout << setw(12) << setfill(' ') << setprecision(4) << *(p + i * N + j);
            }
            cout << endl;
        }

    }

    //打印绩点
    p = stable;
    cout << setw(6) << setfill(' ') << "GPA";
    for (int i = 0; i < col; i++) {
        if (*(p + (row + 2) * N + i) < 60)
            cout << setw(12) << setfill(' ') << 0;
        else {
            if (*(p + (row + 2) * N + i) >= 90)
                cout << setw(12) << setfill(' ') << 4.00;
            else
                cout << setw(12) << setfill(' ') << setprecision(4) << (*(p + (row + 2) * N + i) - 50) / 10;
        }

    }
    cout << endl;


}
void diplaysingledata(float* stable, int sno, int row, int col) {
    float* p = stable;
    for (int i = 0; i < col; i++)
    {
        if (*p++ == sno) {
            for (int j = 0; j < row + 3; j++)
            {
                p = stable;
                if (j == 0)
                    cout << "sno:  ";
                else {
                    if (j < row)
                        cout << "第" << j << "次:";
                    else
                        if (j == row)
                            cout << setw(6) << setfill(' ') << "MAX:";
                    if (j == row + 1)
                        cout << setw(6) << setfill(' ') << "MIN:";
                    if (j == row + 2)
                        cout << setw(6) << setfill(' ') << "AVG:";
                }

                cout << setw(4) << setfill(' ') << *(p + j * N + i) << endl;
            }
            return;

        }
    }
    cout << "您输入的学号不存在！" << endl;

}
/*
**/

/**
 * hw8 第二题 移动数组
 **
#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#define N 10
using namespace std;
void printArray(int *,int);
void rotateArray(int *,int,int);
int main(){
    int array[N] = {0};
    int ch;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        *(array+i) = rand()%200+1;
    }
    while (true)
    {
        cout<<"原数组: ";
        printArray(array,N);
        cout<<"input a number:(0 to end)"<<endl;
        cin>>ch;
        if (ch==0)
            break;
        rotateArray(array,N,ch);
        cout<<"移位后数:";
        printArray(array,N);
        rotateArray(array,N,-ch);
        cout<<"******************************"<<endl;
    }



    return 0;
}
void rotateArray(int *array,int n,int m){
    int *p=array;
    int a[N];
    for(int i=0;i<n;i++){
        a[i] = *p+(i+m)%n;
    }
    for(int i =0;i<n;i++){
        *(p+i)= a[i];
    }
}
void printArray(int *array,int n){
    int *p = array;
    cout<<endl;
    for(int i =0;i<n;i++)
        cout<<setw(3)<<setfill(' ')<<*(p++)<<"  ";
    cout<<endl;
}

**/

/**
 * hw3 维吉尼亚密码
 * *
#include<iomanip>
#include<string>
#include<iostream>
using namespace std;
#define N 26
void printCodebook();
void menu();
void printCoder(int *,int);
void virginiaCoder(int *,int*,int,int);
void virginiaDecoder(int*,int*,int,int);
int main(){
    menu();

    return 0;
}
void menu(){
    int ch;
    string message;
    string key;
    int b[1024];
    int c[1024];
    int n;
    int m;
    while (true)
    {
        cout<<"please input ur choice:"<<endl;
        cout<<"-1--------exit"<<endl;
        cout<<"1--------coder"<<endl;
        cout<<"2--------decoder"<<endl;
        cout<<"3--------print code block"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"input message:"<<endl;
            cin>>message;
            n=message.length();
            for(int i =0;i<n;i++){
                b[i]=message[i]-'a';
            }
            cout<<"input key:"<<endl;
            cin>>key;
            m=key.length();
            for(int i =0;i<m;i++){
                c[i] = key[i]-'a';
            }
            cout<<"message:"<<endl;
            printCoder(b,n);
            cout<<endl;
            cout<<"key:"<<endl;
            printCoder(c,m);
            cout<<endl;
            cout<<"code:"<<endl;
            virginiaCoder(b,c,sizeof(b)/sizeof(int),sizeof(c)/sizeof(int));
            printCoder(b,n);
            break;
        case 2:
            cout<<"input the encrypted message:"<<endl;
            cin>>message;
            n=message.length();
            for(int i =0;i<n;i++){
                b[i]=message[i]-'a';
            }
            cout<<"input key:"<<endl;
            cin>>key;
            m=key.length();
            for(int i =0;i<m;i++){
                c[i] = key[i]-'a';
            }
            cout<<"encrypted message:"<<endl;
            printCoder(b,n);
            cout<<endl;
            cout<<"key:"<<endl;
            printCoder(c,m);
            cout<<endl;
            cout<<"message:"<<endl;
            virginiaDecoder(b,c,sizeof(b)/sizeof(int),sizeof(c)/sizeof(int));
            printCoder(b,n);
            break;
        case 3:
            printCodebook();
            break;

        case -1:
            return;

        default:
            break;
        }
    cout<<endl;

    }


}
void printCodebook(){
    char v[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            v[i][j] = (i+j)%26+'a';
        }

    }
    cout<<"  ";
    for (int i = 0; i < N; i++)
    {
        cout<<char(i+'A')<<" ";
    }
    cout<<endl;

    for (int i = 0; i < N; i++)
    {   cout<<char(i+'A')<<" ";
        for (int j = 0; j < N; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printCoder(int *message,int n){
    int *p = message;
    for(int i =0;i<n;i++)
        cout<<char(*(p++)+'a')<<" ";
}
void virginiaCoder(int *message,int *key,int n,int m){
    int *p = message;
    int *t = key;
    for(int i =0,j=0;i<n;i++){
        *(p+i)=((*(p+i))+(*(t+j)))%26;
        j=(++j)%m;
    }
}

void virginiaDecoder(int *message,int *key,int n,int m){
    int *p = message;
    int *t = key;
    for(int i =0,j=0;i<n;i++){
        // *(p+i)=((*(p+i))+(*(t+j)))%26-2;
        if (*(p+i)<*(t+j))
            *(p+i)=*(p+i)+26-*(t+j);
        else
            *(p+i)=*(p+i)-*(t+j);

        j=(++j)%m;
    }
}
**/
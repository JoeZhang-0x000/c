#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX_PERSONS 100
typedef struct tagSTUDENT
{
    //补充代码，补充商品信息结构体 
    //姓名
    char name[16];
    //学号
    int id;
    //座位号
    int seat_id;

}STUDENT, * PSTUDENT;

// 录入或读取商品信息,nBufSize为缓冲区大小，返回为录入或读取磁盘中存储的商品条数
int ReadStudentsData(STUDENT studentsArry[], int nBufSize)
{

    int  nPersons = 0;
    FILE* pFile = fopen("student.dat", "rb+");           //此处补充打开文件的代码 
    if (pFile)
    {
        //补充读入文件数据的代码 
        rewind(pFile);
        for (int i = 0; !feof(pFile);i++) {
            fread(&studentsArry[i], sizeof(STUDENT), 1, pFile);
            nPersons++;
        }
        nPersons--;
        fclose(pFile);
    }

    if (0 == nPersons)
    {
        //补充录入数据的代码 
        while (1) {
            STUDENT t;
            printf("请输入第%d个学生的姓名:\n",nPersons);
            scanf("%s", t.name);
            printf("请输入%s的学号：\n", t.name);
            scanf("%d", &t.id);
            if (t.id == -1)
                break;
            studentsArry[nPersons] = t;
            nPersons++;
        }
    }
    return nPersons;

}
//以下函数处理菜单1--生成座位号 ，按题目格式要求
void GenSeatsNumber(STUDENT  studentsArry[], int nPersons)
{
    //补充代码，实现函数功能 
    int r1, r2, t;
    //创建一个nPersons长度的数组
    int* n = (int*)malloc(sizeof(int)*nPersons);
    //先生产1-nPersons的座位号
    for (int i = 0; i < nPersons; i++) {
        n[i] = i + 1;
    }
    //再将其随机交换n/2次
    for (int i = 0; i < nPersons / 2; i++) {
        r1 = rand() % nPersons;
        r2 = rand() % nPersons;
        t = n[r1];
        n[r1] = n[r2];
        n[r2] = t;
    }
    //为每个学生对应座位号
    for (int i = 0; i < nPersons; i++) {
        studentsArry[i].seat_id = n[i];
    }
}
void PrintStudentsInfo(STUDENT  studentsArry[], int nPersons)
{
    //排序
    //补充代码
    STUDENT tem;
    for (int i = 0; i < nPersons; i++) {
        int key = studentsArry[i].id;
        for (int j = i; j < nPersons; j++) {
            //若key>s[j],则交换
            if (key > studentsArry[j].id) {
                tem = studentsArry[i];
                studentsArry[i] = studentsArry[j];
                studentsArry[j] = tem;
            }
        }
    }

    //打印 
    //补充代码 
    printf("姓名\t学号\t座位号\n");
    for (int i = 0; i < nPersons; i++) {
        printf("%s\t%d\t%d\n", studentsArry[i].name, studentsArry[i].id, studentsArry[i].seat_id);
    }
}
void SaveStudentsData(STUDENT  studentsArry[], int nPersons)
{
    FILE* pFile = fopen("student.dat", "wb+");         //此处补充打开文件的代码 
    //补充存储数据的代码 
    if (pFile == NULL)
        printf("没有这个文件,且不可创建!\n");
    fwrite(studentsArry, sizeof(STUDENT), nPersons,pFile);
    rewind(pFile);
    STUDENT restudents[16];
    fread(restudents, sizeof(STUDENT), 3, pFile);
    fclose(pFile);
}
int main()
{
    STUDENT studentsArry[MAX_PERSONS] = { { {0},0,0 } };
    int nPersons = ReadStudentsData(studentsArry, MAX_PERSONS);
    int option = 0;    //存储用户输入的菜单选项 
    do {
        //补充代码，输出菜单供用户选择
        srand(time(NULL));
        printf("请选择你需要的操作：\n");
        printf("1-生产座位号\n");
        printf("2-打印信息\n");
        printf("3-数据存盘\n");
        printf("4-退出\n");
        /////////////////////////////////////
        scanf("%d", &option);
        //补充代码，根据用户输入的option值调用相关函数 
        switch (option)
        {
        case 1:
            GenSeatsNumber(studentsArry, nPersons);
            break;
        case 2:
            PrintStudentsInfo(studentsArry, nPersons);
            break;
        case 3:
            SaveStudentsData(studentsArry, nPersons);
            break;
        case 4:
            return 0;
        default:
            break;
        }


        /////////////////////////////////////

    } while (option != 4);//此处补充菜单循环终止条件 

    return 0;
}

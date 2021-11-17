/**
 * hw 8
 * 随机生成10个元素数组，完成排序，返回最小值，最大值，和中数。
 * */
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#define MAX 1024
using namespace std;
void menu();
void generatearray(int*, const int);
void printarray(int*, const int);
void selectionSort(int*, const int);
void swap(int*, int*);
void getinfo(int*, const int, int*, int*, int*);
int main(void) {
    srand(time(NULL));
    menu();
    return 0;
}
void menu() {
    char ch;
    const int size = 10;
    int a[size] = { 0 };
    int max;
    int min;
    int mid;
    while (true) { 
        cout << "press any key to continue...(maybe u should press the ENTER key  more than once!" << endl;
        cin.ignore(MAX, '\n');
        cin.get();
        system("cls");
        cout << "choose the function:" << endl;
        cout << "G-------------generate number" << endl;
        cout << "S-------------sort and print" << endl;
        cout << "P-------------print array" << endl;
        cout << "E-------------exit" << endl;
        cout << ">>";
        cin >> ch;
        cout << endl;
        switch (ch) {
        case 'g':
        case 'G':
            generatearray(a, size);
            break;
        case 's':
        case 'S':
            cout << "the array before sorted:";
            printarray(a, size);
            getinfo(a, size, &max, &min, &mid);
            cout << "the array after sorted:";
            printarray(a, size);
            cout << "Max:" << max << endl;
            cout << "Min:" << min << endl;
            cout << "Mid:" << mid << endl;
            break;
        case 'p':
        case 'P':
            printarray(a, size);
            break;
        case 'e':
        case 'E':
            return;
            break;
        default:
            cout << "unexpected input" << endl;
        }
    }
}

void generatearray(int* array, const int size) {
    {
        int* p = array;
        for (int i = 0; i < size; i++)
            *p++ = rand() % 100 + 1;
    }
    cout << "generate finished!" << endl;
}

void printarray(int* array, const int size) {
    int* p = array;
    for (int i = 0; i < size; i++)
        cout << p[i] << "   ";
    cout << endl;
}

void selectionSort(int* array, const int size) {
    int* p = array;
    int key;
    int k;
    for (int i = 0; i < size; i++) {
        key = p[i];
        // k = i;
        // for(int j=i-1;j>-1;j--){
        //     if(p[j]>key){
        //         p[j+1] = p[j];
        //         k--;
        //     }
        // }
        // p[k]=key;

        for (int j = i; j > -1; j--)
            if (p[j] > key)
                swap(&p[j], &p[j + 1]);
    }
}

void swap(int* element1Ptr, int* element2Ptr) {
    int tem = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = tem;
}

void getinfo(int* array, const int size, int* max, int* min, int* mid) {
    selectionSort(array, size);
    *max = array[size - 1];
    *min = array[0];
    //size is odd,mid = [(size+1)/2-1], size is even,mid = ([size/2-1]+[size/2])/2
    *mid = (size % 2 != 0) ? array[(size + 1) / 2 - 1] : (array[size / 2 - 1] + array[size / 2]) / 2;
}
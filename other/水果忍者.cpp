#include <iostream>
#include <windows.h>
using namespace std;
 
HWND hq_HWND(char ming[]){//��ȡ���  ���������������exe������HWND (ʧ�ܷ���0)
	//cout<<ming<<endl;
	HWND hWnd=FindWindow(NULL,ming);
	return hWnd; 
}
 
DWORD hq_PID(HWND hWnd){//������  ����pid��ʧ�ܴ���0��  
	DWORD PID;
	GetWindowThreadProcessId(hWnd,&PID);
	return PID;
} 
 
HANDLE hq_Process(DWORD PID){ //��ȡһ�����   �������  ���� PID 
	HANDLE lsProcess=0;
	lsProcess=OpenProcess(PROCESS_ALL_ACCESS,FALSE,PID);
	return lsProcess;
}
 
 
int main(int argc, char** argv) {
	//cout<<hq_HWND("Tutorial-i386")<<endl; //���ڻ�ȡ���
	//cout<<hq_PID(hq_HWND("Tutorial-i386"))<<endl;//���ڻ�ȡPID 
	
	
	HANDLE lsProcess;
	lsProcess=hq_Process(hq_PID(hq_HWND("Fruit Ninja")));
	
	DWORD ss=999;
	DWORD dizhi=0x0BF308C;
	//FruitNinja.exe+1B308C
	DWORD s;
	
	do{
		ReadProcessMemory(lsProcess, (LPVOID)dizhi, &s, 4, NULL);
		printf("��ǰˮ������:");
		cout<<s<<endl;
		Sleep(300);
		system("cls");
	} while(TRUE); 
	
	//WriteProcessMemory(lsProcess,(LPVOID)dizhi,&ss,4,NULL);
	
	
	return 0;
}
 

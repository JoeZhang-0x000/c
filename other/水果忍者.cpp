#include <iostream>
#include <windows.h>
using namespace std;
 
HWND hq_HWND(char ming[]){//获取句柄  传入进程名（不加exe）传出HWND (失败返回0)
	//cout<<ming<<endl;
	HWND hWnd=FindWindow(NULL,ming);
	return hWnd; 
}
 
DWORD hq_PID(HWND hWnd){//传入句柄  传出pid（失败传出0）  
	DWORD PID;
	GetWindowThreadProcessId(hWnd,&PID);
	return PID;
} 
 
HANDLE hq_Process(DWORD PID){ //获取一个许可   返回许可  传入 PID 
	HANDLE lsProcess=0;
	lsProcess=OpenProcess(PROCESS_ALL_ACCESS,FALSE,PID);
	return lsProcess;
}
 
 
int main(int argc, char** argv) {
	//cout<<hq_HWND("Tutorial-i386")<<endl; //用于获取句柄
	//cout<<hq_PID(hq_HWND("Tutorial-i386"))<<endl;//用于获取PID 
	
	
	HANDLE lsProcess;
	lsProcess=hq_Process(hq_PID(hq_HWND("Fruit Ninja")));
	
	DWORD ss=999;
	DWORD dizhi=0x0BF308C;
	//FruitNinja.exe+1B308C
	DWORD s;
	
	do{
		ReadProcessMemory(lsProcess, (LPVOID)dizhi, &s, 4, NULL);
		printf("当前水果数量:");
		cout<<s<<endl;
		Sleep(300);
		system("cls");
	} while(TRUE); 
	
	//WriteProcessMemory(lsProcess,(LPVOID)dizhi,&ss,4,NULL);
	
	
	return 0;
}
 

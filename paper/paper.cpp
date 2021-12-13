#include<iostream>
#include<windows.h>
#include<stdio.h>
using namespace std;

BOOL CALLBACK EnumWindowsProc(_In_ HWND hwnd, _In_ LPARAM Lparam)
{
	HWND hDefView = FindWindowEx(hwnd, 0, "SHELLDLL_DefView", 0);
	if (hDefView != 0) {
		// 找它的下一个窗口，类名为WorkerW，隐藏它
		HWND hWorkerw = FindWindowEx(0, hwnd, "WorkerW", 0);
		ShowWindow(hWorkerw, SW_HIDE);

		return FALSE;
	}
	return TRUE;
}
int main(int argc,char*argv[])
{
    char szCommandLine[]="D:\\Tools\\ffmpeg\\bin\\ffplay.exe C:\\Users\\zhangx\\Desktop\\1.mp4  -noborder -x 2500 -y 2000  -loop 0";
    STARTUPINFO si={sizeof(si)};
    PROCESS_INFORMATION pi;
    si.dwFlags=STARTF_USESHOWWINDOW;//指定wShowWindow成员效
    si.wShowWindow=TRUE;//此成员设为TRUE的话则显示新建进程的主窗口
    BOOL bRet=CreateProcess(
        NULL,//不在此指定可执行文件的文件名
        szCommandLine,//命令行参数
        NULL,//默认进程安全性
        NULL,//默认进程安全性
        FALSE,//指定当前进程内句柄不可以被子进程继承
        CREATE_NEW_CONSOLE,//为新进程创建一个新的控制台窗口
        NULL,//使用本进程的环境变量
        NULL,//使用本进程的驱动器和目录
        &si,
        &pi);  
    if(bRet)
    {
        Sleep(400);												// 等待视频播放器启动完成。可用循环获取窗口尺寸来代替Sleep()

		HWND hProgman = FindWindow("Progman", 0);				// 找到PM窗口
		SendMessageTimeout(hProgman, 0x52C, 0, 0, 0, 100, 0);	// 给它发特殊消息
		HWND hFfplay = FindWindow("SDL_app", 0);				// 找到视频窗口
		SetParent(hFfplay, hProgman);							// 将视频窗口设置为PM的子窗口
		EnumWindows(EnumWindowsProc, 0);						// 找到第二

        //不使用的句柄最好关掉
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
        printf("新进程的ID号：%d\n",pi.dwProcessId);
        printf("新进程的主线程ID号：%d\n",pi.dwThreadId);
    }

    getchar();
    return 0;
}

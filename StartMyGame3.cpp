// StartMyGame3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//#include <Windows.h>
#include <afxwin.h>
#include <atlstr.h>

int main(int argc, char* argv[])
{
	

	int times = 3;
	if (argc >= 2) 
	{
		printf("参数个数为:\t%d\n", argc);
		printf("第一个参数是:\t%s\n", argv[0]);
		printf("第二个参数是:\t%d\n", atoi(argv[1]));
		times = atoi(argv[1]);
	}
	if (times > 10) { printf("参数过大，程序退出！\n"); return -1; }
	TCHAR szDir[_MAX_PATH] = L"./V5/V5.exe";
	
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	//初始化变量
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	si.wShowWindow = SW_SHOW;
	si.dwFlags = STARTF_USESHOWWINDOW;
	CreateProcess((LPCTSTR)szDir,
		NULL,
		(LPSECURITY_ATTRIBUTES)NULL,
		(LPSECURITY_ATTRIBUTES)NULL,
		false,
		DETACHED_PROCESS,
		(LPVOID)NULL,
		NULL,
		(LPSTARTUPINFO)&si,
		(LPPROCESS_INFORMATION)&pi);
	Sleep(100);


		CString str = _T("V5 程序多开器 0.1 Beta");
		CWnd* pWnd = CWnd::FindWindow(NULL, str);//获取目的窗口对象
		if (pWnd)
		{
			CString strChild = _T("隔离打开程序");
			CWnd* pWndChild = pWnd->FindWindowEx(pWnd->GetSafeHwnd(), NULL, NULL, strChild);
			for (size_t i = 0; i < times; i++)
			{

				if (pWndChild)
				{
					Sleep(500);
					pWndChild->SendMessage(WM_LBUTTONDOWN, 0, 0); //发送左键按下消息
					Sleep(100);
					pWndChild->SendMessage(WM_LBUTTONUP, 0, 0); //发送左键抬起消息
				}

			}
			Sleep(1000);
			pWnd->PostMessage(WM_CLOSE, 0, 0);
		}
		else
		{
			AfxMessageBox(_T("没有找到MYRECEIVER窗口！"));
		}
	
	CloseHandle(pi.hProcess);
	//system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

// 程序重新启动示例.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <direct.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#define SET_DEFINE_TITLE system("title Win32 Console 程序重启");
#pragma warning(disable: 4996)  //VS2017 
constexpr auto MAX_PATH = 300;
using namespace std;
//函数声明
void toMain();
bool reboot();
char AddChar(char* a, char* b);
string GetSelfPathWithoutEXE();
string GetSelfEXEPath();




int main()
{
	SET_DEFINE_TITLE  //详见define
	cout << "Hello World!\n";
	int x; cin >> x;
	if (x == 1)
		reboot();  //硬重启
	else
		toMain();  //类似递归的重启
	return 0;
}
string GetSelfPathWithoutEXE()
{
	char buffer[MAX_PATH];
	getcwd(buffer, _MAX_PATH);
	string path = buffer;
//	cout << path ;
	return path;
}

string GetSelfEXEPath()
{
	string x = _pgmptr;
	return x;
}
void toMain()
{
	main(); //类似于递归 你也可以用goto
}
bool reboot() {
	system("title 程序正在重新启动,请稍候..");
	system("cls");
	cout << "正在重启" << endl;
	//Todo :
	/* 1.string拼接出批处理内的命令内容 <==choice /t 1 /d y /n >nul
									  _pgmptr<使用函数GetSelfEXEPath>*/
	// 2.输出批处理文件
	// 3.打开批处理文件然后结束进程==>exit(1);


	// 1.拼接生成批处理命令内容
	string cmd="@echo off\nchoice /t 2 /d y /n >nul\n"+GetSelfEXEPath();
	// 2.输出
//	cout << cmd << endl;
//	system("pause");
	ofstream mycout(".reboot.cmd");
	mycout << cmd << endl;
	mycout.close();
	// 3.打开cmd文件
	system(".reboot.cmd");
	SET_DEFINE_TITLE  //详见define
	system("cls");
	return 1;
	exit(1);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

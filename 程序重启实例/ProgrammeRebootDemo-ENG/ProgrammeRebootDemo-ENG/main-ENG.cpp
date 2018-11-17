/* 
You are reading the ENGLISH version code. But it just translated by BAIDU translator,
so please forgive something error.

Adding relevant compile/run environment hints and related settings and error handling, I hope it helps.

-------Translated by BAIDU translator:
Important explanation
It has been open source on GitHub and code cloud. Run successfully using Visual Studio 2017 C compiler and run normally on windows10 x64.
Important setting
If this project is not successfully compiled on your Visual Studio 2017, please try to:
1) Project attributes => C/C++ ==> preprocessor ==> preprocessor definition ==> paste directly into _CRT_SECURE_NO_WARNINGS
2) item attribute ==>C/C++ ==> language == > conform to pattern ==> No.
If the above two operations are carried out, it is still wrong or unable to compile and pass,that please try to:
The item attribute ==>C/C++ ==> code generation ==> runtime ==>Mtd
If there are more questions, please submit Issue on GitHub or use search engines to solve problems.
GitHub address: https://github.com/Mactor2018/ProgrammeReBoot
*/
#include <iostream>
#include <direct.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#define SET_DEFINE_TITLE system("title Win32 Console Programme Reboot");
#pragma warning(disable: 4996)  //VS2017   or will tip 'error 4996' 
constexpr auto MAX_PATH = 300;
using namespace std;
//Function declaration
void toMain();
int reboot();
string GetSelfPathWithoutEXE();
string GetSelfEXEPath();

int main()
{
	SET_DEFINE_TITLE  //Please see define in detail
		cout << "Hello World!\n";
	int x; cin >> x;
	if (x == 1)
		reboot();  //reboot
	else
		toMain();  //reboot like recursion
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
	main(); //Similar to recursion, you can also use goto.
}
int reboot() {
	system("title The programme is rebooting,please waiting for a while..");
	system("cls");
	cout << "ReBooting.. plz waiting.." << endl;
	//Todo:
	// 1. string spliced command contents in bat processing <= = choice / t 1 / d y / n > nul
	//                                                           _pgmptr< uses function GetSelfEXEPath>
	// 2. output bat file
	// 3. open the batch file and end the process == > exit(1);

	// 1.Using string splice to generate batch command contents.
	string cmd = "@echo off\nchoice /t 2 /d y /n >nul\n" + GetSelfEXEPath();
	// 2.Output --> To File
//	cout << cmd << endl;
//	system("pause");
	ofstream mycout(".reboot.cmd");
	mycout << cmd << endl;
	mycout.close();
	// 3.open cmd file
	system(".reboot.cmd");
	SET_DEFINE_TITLE  //Please see define in detail
		system("cls");
	return 0;
}

// running program : Ctrl + F5 or debugging > start execution(not debugging) menu
// debugger: F5 or debug > start debugging menu.
// tips:
// 1. use Solution Explorer window to add / manage files
// 2. use the team Explorer window to connect to source code management
// 3. use output window to view output and other messages.
// 4. use error list window to view errors
//5. Go to Project > Add New Items to create new code files, or to Project > Add Existing Items to add existing code files to projects.
//6. In the future, to open this project again, go to File > Open > Project and select. SLN file.

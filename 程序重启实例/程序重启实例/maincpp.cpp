// ������������ʾ��.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
#include <iostream>
#include <direct.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#define SET_DEFINE_TITLE system("title Win32 Console ��������");
#pragma warning(disable: 4996)  //VS2017 
constexpr auto MAX_PATH = 300;
using namespace std;
//��������
void toMain();
bool reboot();
char AddChar(char* a, char* b);
string GetSelfPathWithoutEXE();
string GetSelfEXEPath();




int main()
{
	SET_DEFINE_TITLE  //���define
	cout << "Hello World!\n";
	int x; cin >> x;
	if (x == 1)
		reboot();  //Ӳ����
	else
		toMain();  //���Ƶݹ������
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
	main(); //�����ڵݹ� ��Ҳ������goto
}
bool reboot() {
	system("title ����������������,���Ժ�..");
	system("cls");
	cout << "��������" << endl;
	//Todo :
	/* 1.stringƴ�ӳ��������ڵ��������� <==choice /t 1 /d y /n >nul
									  _pgmptr<ʹ�ú���GetSelfEXEPath>*/
	// 2.����������ļ�
	// 3.���������ļ�Ȼ���������==>exit(1);


	// 1.ƴ��������������������
	string cmd="@echo off\nchoice /t 2 /d y /n >nul\n"+GetSelfEXEPath();
	// 2.���
//	cout << cmd << endl;
//	system("pause");
	ofstream mycout(".reboot.cmd");
	mycout << cmd << endl;
	mycout.close();
	// 3.��cmd�ļ�
	system(".reboot.cmd");
	SET_DEFINE_TITLE  //���define
	system("cls");
	return 1;
	exit(1);
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�

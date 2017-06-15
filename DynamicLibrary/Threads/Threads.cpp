// Threads.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MathFuncsDll.h"
#include "windows.h"
#include <iostream>

using namespace std;

void proc1(CRITICAL_SECTION sec)
{
	EnterCriticalSection(&sec);
	cout << "Выполняется первый поток" << endl;
	LeaveCriticalSection(&sec);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	CRITICAL_SECTION sec1;
	InitializeCriticalSection(&sec1);
	proc1(sec1);
	MathFuncs::MyMathFuncs::proc2();
	system("PAUSE");
	return 0;
}
// MathFuncsDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MathFuncsDll.h"
#include <stdexcept>
#include <iostream>

using namespace std;

CRITICAL_SECTION sec2;

namespace MathFuncs
{
	double MyMathFuncs::Add(double a, double b)
	{
		return a + b;
	}

	double MyMathFuncs::Subtract(double a, double b)
	{
		return a - b;
	}

	double MyMathFuncs::Multiply(double a, double b)
	{
		return a * b;
	}

	double MyMathFuncs::Divide(double a, double b)
	{
		if (b == 0)
		{
			throw invalid_argument("b cannot be zero!");
		}

		return a / b;
	}
	
	void MyMathFuncs::proc2()
	{
		InitializeCriticalSection(&sec2);
		EnterCriticalSection(&sec2);
		cout << "Выполняется второй поток" << endl;
		LeaveCriticalSection(&sec2);
	}
}


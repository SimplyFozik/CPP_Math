#pragma once
//#include <iostream>
#include <string>
//#include "Form1.h"
//#include <windows.h>
#include <sstream>

int TopStack = -1;
int NumTopStack = 0;
char Stack[100];
float NumStack[100];
std::string reversed_polk;

template <typename T> std::string tostr(const T& t)
{
	std::ostringstream os;
	os << t;
	return os.str();
}

void funcStackAdd(char symbol)
{
	TopStack++;
	Stack[TopStack] = symbol;
}

void funcStackRemove()
{
	TopStack--;
}

int funcPriority(char operation)
{
	if ((operation == '+') || (operation == '-')) return 0;
	else if ((operation == '*') || (operation == '/')) return 1;
	else return -1;
}

void funcReversedWrite(char symbol)
{
	reversed_polk = reversed_polk + symbol;
}

void funcNullPriority(int priority) // ex. *-**/+
{
	if (TopStack >= 0)
	{
		for (int i = TopStack; (i >= 0) && (funcPriority(Stack[i]) >= priority); i--)
		{
			funcReversedWrite(Stack[i]);
			funcStackRemove();
		}
	}
}

void funcEnd()
{
	for (int i = TopStack; i >= 0; i--)
	{
		funcReversedWrite(Stack[i]);
		funcStackRemove();
	}
}

void funcPairsPush()
{
	for (int i = TopStack; Stack[i] != '('; i--)
	{
		funcReversedWrite(Stack[i]);
		funcStackRemove();
	}
	funcStackRemove();
}

void funcClearEverything()
{
	for (int i = 0; i < 100; i++)
	{
		NumStack[i] = 0;
		Stack[i] = '\0';
	}
	reversed_polk = "";
}

float funcCalculate(std::string& new_string)
{
	for (int i = 0; i < reversed_polk.size(); i++)
	{
		if (isdigit(reversed_polk[i]))
		{
			NumStack[NumTopStack] = 0;
			for (; isdigit(reversed_polk[i]); i++)
			{
				NumStack[NumTopStack] = (NumStack[NumTopStack] * 10) + reversed_polk[i] - '0';
				//cout << NumStack[NumTopStack] << endl;
			}
			NumTopStack++;
			i--;
		}
		else if (funcPriority(reversed_polk[i]) == 0 || funcPriority(reversed_polk[i]) == 1)
		{
			//new_string = "";
			new_string += (tostr(NumStack[NumTopStack - 2]) + " " + reversed_polk[i] + " " + tostr(NumStack[NumTopStack - 1]) + " = ");
			//std::cout << NumStack[NumTopStack - 2] << " " << reversed_polk[i] << " " << NumStack[NumTopStack - 1] << " = ";
			
			switch (reversed_polk[i])
			{
			case '+':
				NumStack[NumTopStack - 2] = NumStack[NumTopStack - 2] + NumStack[NumTopStack - 1];
				NumTopStack--;
				break;
			case '-':
				NumStack[NumTopStack - 2] = NumStack[NumTopStack - 2] - NumStack[NumTopStack - 1];
				NumTopStack--;
				break;
			case '*':
				NumStack[NumTopStack - 2] = NumStack[NumTopStack - 2] * NumStack[NumTopStack - 1];
				NumTopStack--;
				break;
			case '/':
				NumStack[NumTopStack - 2] = NumStack[NumTopStack - 2] / NumStack[NumTopStack - 1];
				NumTopStack--;
				break;
			}
			new_string += (tostr(NumStack[NumTopStack - 1]) + "\n");
			//std::cout << NumStack[NumTopStack - 1] << std::endl;
		}
	}
	return NumStack[NumTopStack - 1];
}

float funcAnalyze(std::string arr, int size,std::string& new_string)
{
	for (int i = 0; i < size; i++)
	{
		if (isdigit(arr[i]))
		{
			for (; isdigit(arr[i]); i++)
			{
				funcReversedWrite(arr[i]);
			}
			funcReversedWrite(' ');
			i--;
		}
		else if (funcPriority(arr[i]) == 1)
		{
			funcNullPriority(1);
			funcStackAdd(arr[i]); // add '*' or '/'
		}
		else if (funcPriority(arr[i]) == 0) // add '+' or '-'
		{
			funcNullPriority(0);
			funcStackAdd(arr[i]);
			
		}
		else if (arr[i] == '(')
		{
			funcStackAdd(arr[i]); // add '('
		}
		else if (arr[i] == ')')
		{
			funcPairsPush();
		}
		else
		{
			break;
		}
	}
	funcEnd();
	//std::cout << std::endl;
	//std::cout << reversed_polk << std::endl;
	float res = funcCalculate(new_string);
	funcClearEverything();
	return res;
}

//15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))
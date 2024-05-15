#pragma once
#include <iostream>
#include <string>

using namespace std;

int TopStack = -1;
int NumTopStack = 0;
char Stack[100];
float NumStack[100];
string reversed_polk;

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

void funcStackWrite()
{
	for (int i = 0; i < TopStack; i++)
	{
		cout << Stack[i];
	}
	cout << " <- Top Of Stack" << endl;
}


void funcCalculate()
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
			cout << NumStack[NumTopStack - 2] << " " << reversed_polk[i] << " " << NumStack[NumTopStack - 1] << " = ";
			
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
			cout << NumStack[NumTopStack - 1] << endl;
		}
	}
	cout << "Result " << NumStack[NumTopStack - 1] << endl;
}

void funcAnalyze(string arr, int size)
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
	}
	funcEnd();
	cout << endl;
	cout << reversed_polk << endl;
	funcStackWrite();
	funcCalculate();
}

//15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))
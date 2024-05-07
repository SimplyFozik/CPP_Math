#pragma once
#include <iostream>
#include <string>

using namespace std;

int TopStack = -1;
int NumTopStack = -1;
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

void funcNullPriority() // ex. *-**/+
{
	if (TopStack > 0)
	{
		for (int i = TopStack; (i >= 0) && (funcPriority(Stack[i]) > 0); i--)
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

void funcCollectNumber()
{

}

void funcCalculate()
{
	for (int i = 0; i < reversed_polk.size(); i++)
	{
		if (isdigit(reversed_polk[i]))
		{
			for (int j = i; reversed_polk[j] != '+' || reversed_polk[j] != '-' || reversed_polk[j] != '/' || reversed_polk[j] != '*' || reversed_polk[j] != ' '; j++)
			{
				NumStack[NumTopStack] += reversed_polk[j] - '0';
			}
			NumTopStack++;
		}
		else if (funcPriority(reversed_polk[i]) == 0 || funcPriority(reversed_polk[i]) == 1)
		{
			switch (reversed_polk[i])
			{
			case '+':
				NumStack[NumTopStack - 1] = NumStack[NumTopStack - 1] + NumStack[NumTopStack];
				NumTopStack--;
				break;
			case '-':
				NumStack[NumTopStack - 1] = NumStack[NumTopStack - 1] - NumStack[NumTopStack];
				NumTopStack--;
				break;
			case '*':
				NumStack[NumTopStack - 1] = NumStack[NumTopStack - 1] * NumStack[NumTopStack];
				NumTopStack--;
				break;
			case '/':
				NumStack[NumTopStack - 1] = NumStack[NumTopStack - 1] / NumStack[NumTopStack];
				NumTopStack--;
				break;
			}
		}
	}
	cout << "Result " << NumStack[0];
}

void funcAnalyze(string arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (isdigit(arr[i]))
		{
			funcReversedWrite(arr[i]);
		}
		else if (funcPriority(arr[i]) == 1)
		{
			funcStackAdd(arr[i]); // add '*' or '/'
		}
		else if (funcPriority(arr[i]) == 0) // add '+' or '-'
		{
			funcNullPriority();
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
			cout << "Error!" << endl << "There is no " << to_string(arr[i]) << " Operation!" << endl;
		}
	}
	funcEnd();
	cout << endl;
	cout << reversed_polk << endl;
	funcStackWrite();
	funcCalculate();
}

//15/(7-(1+1))*3-(2+(1+1))*15/(7-(200+1))*3-(2+(1+1))*(15/(7-(1+1))*3-(2+(1+1))+15/(7-(1+1))*3-(2+(1+1)))
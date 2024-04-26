#pragma once
#include <iostream>
#include <string>

using namespace std;

int TopStack = -1;
char Stack[100];
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
		for (int i = TopStack - 1; (i > 0) && (funcPriority(Stack[i]) > 0); i--)
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

//void funcPairsPush(int index)
//{
//	for (int i = index; Stack[i] != '('; i--)
//	{
//		funcStackAdd(Stack[i]);
//	}
//}



void funcStackWrite()
{
	for (int i = 0; i < TopStack; i++)
	{
		cout << Stack[i];
	}
	cout << " <- Top Of Stack";
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
			funcStackAdd(arr[i]);
			funcNullPriority();
		}
		else if (arr[i] == '(')
		{
			funcStackAdd(arr[i]); // add '('
		}
		else if (arr[i] == ')')
		{

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
}
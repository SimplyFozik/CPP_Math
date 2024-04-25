#pragma once
#include <iostream>
#include <string>

using namespace std;

int TopStack = -1;
int Stack[100];
string reversed_polk;

void funcStackAdd(char symbol)
{
	TopStack++;
	Stack[TopStack] = symbol;
}

int funcPriority(char operation)
{
	if ((operation == '+') || (operation == '-')) return 0;
	else if ((operation == '*') || (operation == '/')) return 1;
	else return -1;
}

void funcNullPriority(int index) // ex. *-**/+
{
	for (int i = index - 1; (i > 0) && (funcPriority(Stack[i]) > 0); i--)
	{
		funcStackAdd(Stack[i]);
	}
}

//void funcPairsPush(int index)
//{
//	for (int i = index; Stack[i] != '('; i--)
//	{
//		funcStackAdd(Stack[i]);
//	}
//}

void funcStackRemove()
{
	TopStack--;
}

void funcStackWrite()
{
	for (int i = 0; i < TopStack; i++)
	{
		cout << Stack[i];
	}
	cout << " <- Top Of Stack";
}

void funcReversedWrite()
{
	cout << "Result: " << reversed_polk;
}

void funcAnalyze(string arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (isdigit(arr[i]))
		{
			reversed_polk += arr[i];
		}
		else if (funcPriority(arr[i]) == 1)
		{
			funcStackAdd(arr[i]); // add '*' or '/'
		}
		else if (funcPriority(arr[i]) == 0) // add '+' or '-'
		{
			funcNullPriority(i);
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
	funcReversedWrite();
	cout << endl;
	funcStackWrite();
}
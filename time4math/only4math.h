#pragma once 
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

char Stack[100];
int TopStack = -1;
string newArr;

void printArr(string arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
}

void stackAdd(int size, char operat)
{
	TopStack++;
	Stack[TopStack] = operat;
}

void stackDel(int size)
{
	for (int i = TopStack; i >= 0; i--)
	{
		if (Stack[i] == '+' || Stack[i] == '-')
		{
			for (int j = TopStack - 1; j >= 0; j--)
			{
				if (Stack[j] == '*' || Stack[j] == '/')
				{
					newArr = newArr + Stack[j];
					Stack[j] = NULL;
				}
				else if (j >= TopStack)
				{
					break;
				}
			}
		}
		else if (Stack[i] == ')')
		{
			for (int x = Stack[i]; Stack[x] != '('; x--)
			{
				if (Stack[x] == '(')
				{
					for (int y = x; y >= 0; y--)
					{
						newArr = newArr + Stack[y];
						Stack[y] = NULL;
					}
				}
				else
				{
					cout << "Something went wrong! pairs problem";
				}
			}
		}
	}
}
void stackFin(int size)
{
	for (int i = TopStack; i >= 0; i--)
	{
		if (Stack[i] == '*' || Stack[i] == '/')
		{
			newArr = newArr + Stack[i];
		}
		if (Stack[i] == '+' || Stack[i] == '-')
		{
			newArr = newArr + Stack[i];
		}
		if (Stack[i] == '(')
		{
			newArr = newArr + Stack[i];
		}
	}
}

	
string Analyze(string arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (isdigit(arr[i]))
		{
			newArr = newArr + arr[i];
		}
		else if (arr[i] == '+' || arr[i] == '/' || arr[i] == '-' || arr[i] == '*')
		{
			if (arr[i] == '+')
			{
				stackAdd(size, '+');
				stackDel(size);
			}
			else if (arr[i] == '-')
			{
				stackAdd(size, '-');
				stackDel(size);
			}
			else if (arr[i] == '*')
			{
				stackAdd(size, '*');
			}
			else if (arr[i] == '/')
			{
				stackAdd(size, '/');
			}
			else if (arr[i] == '(')
			{
				stackAdd(size, '(');
			}
		}
	}
	stackFin(size);
	cout << newArr;
	return newArr;
}


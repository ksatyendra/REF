#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 50
using namespace std;

class Stack
{
	char element[MAX];
	int top;
	public:
		Stack()
		{
			top = -1;
		}
		void push(char c)
		{
			if(isFull())
			{
				cout<<"Stack Overflow..!!"; exit(1);
			}
			element[++top] = c;
		}
		char pop()
		{
			if(isEmpty())
			{
				cout<<"Stack EMpty..!!"; exit(2);
			}
			char ch = element[top];
			element[top--]=NULL;
			return ch;
		}
		char topelement()
		{
			return element[top];
		}
		int isFull()
		{
			if(MAX==top+1)
				return 1;
			return 0;
		}
		int isEmpty()
		{
			if(top==-1)
				return 1;
			return 0;
		}

};

int calculate(char op2,char op1, char op)
{
	op1 = op1-48; op2 = op2-48;
	if(op == '-')
		return op1-op2;
	else if(op == '+')
		return op1+op2;
	else if(op == '*')
		return op1*op2;
	else if(op == '/')
		return op1/op2;
}

int main()
{
	char postfx[100];  Stack s; int val=0; char ch;

	cout<<"Enter Expression : ";
	cin.getline(postfx,100);
	int i,j;
	for(i=0; postfx[i]!='\0'; i++)
	{
		if(isalnum(postfx[i]))
			s.push(postfx[i]);
		else
		{
			val = calculate(s.pop(),s.pop(),postfx[i]);
			ch = val+48;
			s.push(ch);
		}
	}
	cout<<"\n Value of expression : "<<s.topelement()-48;
}
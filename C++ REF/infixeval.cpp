#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 50
using namespace std;

class Stack
{
	char elem[MAX];
	int top;
   public:
	Stack(){ top = -1; }
	void push(char k)
	{
		if(isFull())
		{
			cout<<"Stack Overflow..!!"; exit(1);
		}
		elem[++top] = k;
	}
	char pop()
	{
		if(isEmpty())
		{
			cout<<"Stack is Empty..!!";  exit(1);
		}
		return elem[top--];
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
	char topelem()
	{
		return elem[top];
	}
};
int prec(char op)
{
    switch(op)
    {
    case '(':
        return 0;
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    }
}
int calc(char op,char op2,char op1)
{
    int a = op1-48; int b = op2-48;
    switch(op)
    {
    case '+':
        return b+a;
    case '-':
        return b-a;
    case '*':
        return b*a;
    case '/':
        if(a!=0)
           return b/a;
    }
}
int main()
{
    char infx[50]; Stack opd,opr;  char ch;  int val;
    cout<<"Enter Infix Expression : "; cin>>infx;
    int i,j;
    for(i=0; infx[i]!='\0'; i++)
    {
        if(isdigit(infx[i]))
            opd.push(infx[i]);
        else if(infx[i]=='(')
            opr.push(infx[i]);
        else if(infx[i]==')')
        {
            while(opr.topelem()!='(')
            {
                val = calc(opr.pop(),opd.pop(),opd.pop());
                ch = val+48;
                opd.push(ch);
            }
            opr.pop();
        }
        else if(infx[i]=='+' || infx[i]=='-' || infx[i]=='*'||infx[i]=='/')
        {
            while(!opr.isEmpty() && (prec(infx[i]) <= prec(opr.topelem())))
            {
                val = calc(opr.pop(),opd.pop(),opd.pop());
                ch = val+48;
                opd.push(ch);
            }
            opr.push(infx[i]);
        }
    }
    while(!opr.isEmpty())
    {
        val = calc(opr.pop(),opd.pop(),opd.pop());
        ch = val+48;
        opd.push(ch);
    }
    ch = opd.topelem();
    val = ch-48;
    cout<<"\n Value of infix expression : "<<val;
}

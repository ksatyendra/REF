#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define MAX 25
class Stack
{
	char element[MAX];
	int size;
	int top;
	public:
	Stack(){
		top = -1;
		size = 0;
	}
	Stack(char s[],int n)
	{
		top = -1;
		for(int i =0; i<n ; i++)
		{	
			element[i] = s[i];
			++top;
		}
		size = n;
	}
	void push(char);
	char pop();
	int isEmpty();
	int isFull();
};

void Stack::push(char k)
{
	if(isFull())
		cout<<"\nStack is Full..!!";
	else
		element[++top] = k;
}
char Stack::pop()
{
	if(isEmpty())
	{
		cout<<"\nStack is Empty..!!";
		exit(1);
	}
	else
	{
		return element[top--];
		element[top--] = NULL;
	}	
}
int Stack::isEmpty()
{
	if(top==-1)
	    return 1;
	else
		return 0;
}
int Stack::isFull()
{
	if(size == top+1)
		return 1;
	else
		return 0;
}
int main()
{
	char str[25]; Stack s; int i,flag;
	cout<<"Enter String : ";
	cin.getline(str,25);
	int len = strlen(str);
	for(i=0; i<len; i++)
	{
		s.push(str[i]);
	}
	for(i=0; i<len/2; i++ )
	{
		flag = 0;
		if(str[i]==s.pop())
			flag=1;
	}
	if(flag == 1)
	  cout<<"\nGiven String is a Palindrome.";
	else
	  cout<<"\nGiven String is NOT a Palindrome.";	
}

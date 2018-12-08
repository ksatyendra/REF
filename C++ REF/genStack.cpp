#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX 50
using namespace std;
union data
{
	int no;
	char str[25];
	float fno;
};
struct st
{
    data d;
    int tag;
};
class Stack
{
	st s[MAX];
	int top;
	int size;
   public:
    Stack(){ top = -1; }
    void push(int);
	void push(char*);
	void push(float);
	void pop();
	int isEmpty();
	int isFull();
};

void Stack::push(int k)
{
	if(isFull())
	{
		cout<<"\nStack Overflow..!!"; exit(1);
	}
	s[++top].tag=1;
	s[top-1].d.no = k;
}
void Stack::push(char ch[])
{
	if(isFull())
	{
		cout<<"\nStack Overflow..!!"; exit(1);
	}
	s[++top].tag = 2;
	strcpy(s[top-1].d.str,ch);
}
void Stack::push(float k)
{
	if(isFull())
	{
		cout<<"\nStack Overflow..!!"; exit(1);
	}
	s[++top].tag = 3;
	s[top-1].d.fno=k;
}
void Stack::pop()
{
	if(isEmpty())
	{
		cout<<"\nStack is Empty..!!";
		exit(1);
	}
	else
	{
		if(s[top].tag == 1)
		{
			cout<<s[top].d.no;
			s[top--].d.no = NULL; }
		else if(s[top].tag == 2)
		{
			cout<<s[top].d.str;
			strcpy(s[top--].d.str,NULL); }
		else if(s[top].tag == 3)
		{
			cout<<s[top].d.fno;
			s[top--].d.fno = NULL;
		}
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
	if(MAX == top+1)
		return 1;
	else
		return 0;
}
int main()
{
	int no; int ch; char ch1,str[25]; float f;   Stack stac;
	do{
		cout<<"Enter choice : "; cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter Integer : "; cin>>no;
				stac.push(no);
				break;
			case 2:
				cout<<"Enter String: "; cin>>str;
				stac.push(str);
				break;
			case 3:
				cout<<"Enter Float : "; cin>>f;
				stac.push(f);
				break;
			default:
				{cout<<"invalid option.."; exit(2);}
		}
		cout<<"wanna add more data (y/n) : "; cin>>ch1;
	}while(ch1=='y');
    cout<<"\nDisplaying Data...\n";
    while(1)
    {
        stac.pop();
    }
	return 0;
}

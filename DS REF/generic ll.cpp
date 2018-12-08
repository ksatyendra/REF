#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

union mytype
{
    int data;
    char str[15];
};
struct lnode
{
    mytype m;
    int tag;
    lnode *next;
};
void firstItem(lnode **L,int k)
{
    lnode *T;
    T = new lnode;
    T->tag = 1;
    T->m.data = k;
    T->next = NULL;
    *L = T;
}
void firstItem(lnode **L,char k[])
{
    lnode *T;
    T = new lnode;
    strcpy(T->m.str,k);
    T->tag = 0;
    T->next = NULL;
    *L = T;
}
void addEnd(lnode *L,int k)
{
    lnode *T;
    while(L->next != NULL)
        L = L->next;
    T = new lnode;
    T->tag = 1;
    T->m.data = k;
    T->next = NULL;
    L->next = T;
}
void addEnd(lnode *L,char k[])
{
    lnode *T;
    while(L->next != NULL)
        L = L->next;
    T = new lnode;
    strcpy(T->m.str,k);
    T->tag = 0;
    T->next = NULL;
    L->next = T;
}
void display(lnode *L)
{
    cout<<"\n-------Printing List-------\n\n";
	while(L!= NULL)
	{
	    if(L->tag == 1)
            cout<<" --> "<<L->m.data;
        else if(L->tag == 0)
            cout<<"--> "<<L->m.str;
		L = L->next;
	}
}
int main()
{
    lnode *L = NULL;
    char ch,str[15];  int X,k;
    cout<<"Enter 1st Node data 1 for integer 0 for string : ";
        cin>>X;
        if(X==1)
            {cout<<"Enter integer : "; cin>>k;  firstItem(&L,k); }
        else
        {
            cout<<"Enter string : "; cin>>str;
            firstItem(&L,str);
        }
	do{
		cout<<"\nEnter node data 1 for integer 0 for string : ";
		cin>>X;
        if(X==1)
            {cout<<"Enter integer : "; cin>>k;  addEnd(L,k); }
        else
        {
            cout<<"Enter string : "; cin>>str;
            addEnd(L,str);
        }
		cout<<"Wanna Continue..<Y/N> ... "; cin>>ch;
	}while(ch=='y'||ch=='Y');
	display(L);
	return 0;
}

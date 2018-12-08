#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

struct node
{
    char data;
    node *next;
};
struct ptrnode
{
    node *next;
    node *nnext;
};
node *head; ptrnode *root;
void input(node *L,char ch)
{
    node *t;
        if(L == NULL)
        {
            L = new node;
            L->data = ch;
            L->next = NULL;
            head = L;
        }
        else
        {
            while(L!=NULL)
                L = L->next;
            t = new node;
            t->data = ch;
            t->next = NULL;
            L->next = t;
        }
}
int main()
{
    node *L=NULL; ptrnode *p=NULL;
    char str[100]; int i,j=0,k=0;
    cout<<"Enter String : "; cin>>str;
    for(i=1; str[i+1]!='\0'; i++)
    {
        if(str[i]=='[')
        {
            p = new ptrnode;
            p->next = NULL;
            p->nnext = NULL;
            root = p;
        }
        else if(str[i]==']')
        {
            j--; i++;
        }
        else
        {
            L =
        }
    }
    return 0;
}

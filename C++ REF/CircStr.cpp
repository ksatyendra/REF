#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct node
{
    char data;
    node *next;
};
node *head; int count = 0;
//creating new node
void input(node *L,char str[])
{
    node *t; int k=0;
    while(str[k]!='\0')
    {
        if(L == NULL)
        {
            L = new node;
            L->data = str[k++];
            L->next = L;
            head = L;
        }
        else
        {
            t = new node;
            t->data = str[k++];
            t->next = head;
            L->next = t;
        }
        L = L->next;
    }
}
void extractList(node *L,char str[])
{
    L = head;  int k =0;
    do
    {
        str[k++] = L->data;
        L = L->next;
    }while(L!=head);
}
void moveHead(int i)
{
    for(int k=0; k<i; k++)
        head = head->next;
}
void show( node *L)
{
    L = head;
    cout<<"\nString is....\n";
    do
    {
        cout<<L->data;
        L = L->next;
    }while(L!=head);
    cout<<"\n";
}
int main()
{
    node *L = NULL; int n,i; char str1[25],str2[25];
    cout<<"\nEnter String 1 : "; cin>>str1;
    cout<<"\nEnter String 2 : "; cin>>str2;
    input(L,str1);
    show(head);
    for(i=0; i<strlen(str1); i++)
    {
        extractList(L,str1);
        cout<<"\nRotated String : "<<str1<<"\n";
        if(strcmp(str1,str2)==0)
        {
            cout<<"\nMatch Found..!!";
            cout<<"\n\nNo. of Rotation : "<<i<<"\n\n";
            exit(1);
        }
        moveHead(1);
    }
    return 0;
}

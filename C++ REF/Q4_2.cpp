#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct lnode
{
    int data;
    lnode* next;
}* lptr;

lptr getNode(int k)
{
    lptr t = new lnode;
    t->data = k;
    t->next = NULL;
    return t;
}

void addEnd(lptr &L,int k)
{
    if(L==NULL)
    {
        L = getNode(k);
    }
    else
    {
        lptr t = L;
        while(t->next)
            t = t->next;
        t->next = getNode(k);
    }
}

void createList(lptr &L)
{
    char ans='y'; int k;
    while(ans=='y')
    {
        cout<<"\nEnter Data : "; cin>>k;
        addEnd(L,k);
        cout<<"\nWanna Continue (y/n) ? "; cin>>ans;
    }
}
void display(lptr L)
{
    if(!L)
        return;
    cout<<"  "<<L->data;
    display(L->next);
}
void sort(lptr &L)
{
    if(L==NULL)
        return;
    lptr temp = L;
    lptr temp2 = temp->next;
    while(temp2)
    {
        if( temp->data < temp2->data)
            swap(temp2->data,temp->data);
        temp2 = temp2->next;
    }
    sort(temp->next);
}
int main()
{
    lptr L = NULL;
    createList(L);
    cout<<"\n\nDisplaying List ..\n";
    display(L);
    sort(L);
    cout<<"\n---------------------\n";
    cout<<"\n\nDisplaying Sorted List ..\n\n";
    display(L);
    cout<<"\n---------------------\n";
    return 0;
}

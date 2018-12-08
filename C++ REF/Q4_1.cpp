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
lptr mergeLists(lptr L1, lptr L2)
{
    lptr t = NULL;
    if(!L1 && !L2)
        return NULL;
    else if(!L1)
        return L2;
    else if(!L2)
        return L1;
    else
    {
        if(L1->data >= L2->data)
        {
            addEnd(t,L2->data);
            t->next = mergeLists(L1, L2->next);
        }
        else if(L1->data < L2->data)
        {
            addEnd(t,L1->data);
            t->next = mergeLists(L1->next, L2);
        }
    }
    return t;
}
int main()
{
    lptr L1 = NULL; lptr L2 = NULL;
    createList(L1);
    cout<<"\n\nDisplaying List 1..\n";
    display(L1);
    createList(L2);
    cout<<"\nDisplaying List 2..\n";
    display(L2);
    lptr L3  = mergeLists(L1,L2);
    cout<<"\nDisplaying List 3..\n";
    display(L3);
    cout<<"\n---------------------\n";
    return 0;
}

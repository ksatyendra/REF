#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct lnode
{
    int data;
    lnode* next;
    lnode* nptr;
}* lptr;

lptr getNode(int k)
{
    lptr t = new lnode;
    t->data = k;
    t->next = NULL;
    t->nptr = NULL;
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
    L->nptr = L->next->next;
    L->next->nptr = L->next->next->next;
    L->next->next->next->nptr = L->next->next;
}
void display(lptr L)
{
    if(!L)
        return;
    cout<<"  "<<L->data;
    display(L->next);
}
lptr copyList(lptr L)
{
    lptr ltemp=NULL;
    while(L)
    {
        addEnd(ltemp, L->data);
        L = L->next;
    }
    return ltemp;
}
int findPos(lptr L,int k)
{
    while(L)
}
lptr copyPtr(lptr L1, lptr L2)
{

}
int main()
{
    lptr L1 = NULL; lptr L2 = NULL;
    createList(L1);
    cout<<"\n\nDisplaying List 1..\n";
    display(L1);
    L2 = copyList(L1);
    cout<<"\n";
    display(L2);
    return 0;
}

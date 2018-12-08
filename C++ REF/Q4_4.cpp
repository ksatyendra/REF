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
void removeNode(lptr &L,int k)
{
    lptr temp = L; int i=0;
    if(k == 1)  // first item removal
        L = L->next;
    else
    {
        while(temp->next->data != k)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
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

int countList(lptr L)
{
    int i = 0;
    while(L)
    {
        L = L->next;
        i++;
    }
    return i;
}

int main()
{
    lptr L = NULL; int k=0,count=0;
    createList(L);
    cout<<"\n\nDisplaying List ..\n";
    display(L);
    cout<<"\n---------------------\n";
    int n = countList(L);
    cout<<n;
    //adjust(L);
    lptr ltemp = L;
    while(ltemp)
    {
        k = ltemp->data - count;
        if(num <= n)
        {
            removeNode(L, k );
            ltemp = L; count++; n--;
            continue;
        }
        ltemp = ltemp->next;
    }
    cout<<"\n\nDisplaying Adjusted List ..\n";
    display(L);
    cout<<"\n---------------------\n";*/
    return 0;
}

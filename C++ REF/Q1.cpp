#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef struct bnode
{
    int data;
    bnode *lchild;
    bnode *rchild;
}* bstptr;

typedef struct lnode
{
    int data;
    lnode *next;
    bstptr bptr;
}* lptr;

void display(bstptr root)
{
    if(root)
    {
        display(root->lchild);
        cout<<root->data<<" ,";
        display(root->rchild);
    }
}
void display(lptr L)
{
    if(L)
    {
        if(L->next)
            cout<<L->data<<" -- "<<L->next->data;
        else
            printf("%d --   : ", L->data);
        display(L->bptr);
        cout<<"\n\n";
        display(L->next);
    }
}
lptr getNode(int k)
{
    lptr t = new lnode;
    t->data = k;
    t->bptr = NULL;
    t->next = NULL;
    return t;
}
bstptr getBNode(int k)
{
    bstptr t = new bnode;
    t->data = k;
    t->lchild = t->rchild = NULL;
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
        cout<<t->data;
        t->next = getNode(k);
    }
}
void createList(lptr &L)
{
    char ans='y'; int k;
    while(ans=='y')
    {
        cout<<"\nEnter Range Data for List : "; cin>>k;
        addEnd(L,k);
        cout<<"\nWanna Continue (y/n) ? "; cin>>ans;
    }
}
void insertTree(bstptr &root, int  k )
{
    if(root == NULL)
    {
        root = getBNode(k);
    }
    else
    {
        if( k < root->data )
            insertTree(root->lchild, k);
        else if( k > root->data )
            insertTree(root->rchild, k);
    }
}
void createTree(lptr &L)
{
    char ans='y'; int k,flag; lptr ltemp = L;
    while(ans=='y')
    {
        cout<<"\nEnter Data : "; cin>>k;
        while(ltemp->data < k )
        {
           if(ltemp->next)
           {
               if(ltemp->next->data < k)
                flag=1;
           }
           if(flag == 1)
            {ltemp = ltemp->next;
            flag = 0;}
           else
            break;
        }
        insertTree(ltemp->bptr, k);
        ltemp = L;
        //cout<<L->bptr->data;
        cout<<"\nWanna Continue (y/n) ? "; cin>>ans;
    }
}
int search(bstptr root, int k)
{
    if(root)
    {
        if(root->data == k)
            return 1;
        else if(root->data >k)
            return search(root->lchild, k);
        else if(root->data < k)
            return search(root->rchild, k);
    }
}
int search(lptr L, int k)
{
    lptr ltemp = L; int flag;
    while(ltemp->data < k )
    {
        if(ltemp->next)
        {
            if(ltemp->next->data < k)
                flag=1;
        }
        if(flag == 1)
        {
            ltemp = ltemp->next;
            flag = 0;
        }
        else
            break;
    }
    return search(L->bptr, k);
}
int main()
{
    lptr L=NULL; int num;
    createList(L);
    cout<<"\nList Created Successfully..!!!\n";
    cout<<"\nEnter data for tree node...\n\n";
    createTree(L);
    cout<<"\n----------Displaying Data in Given Format---------\n\n";
    display(L);
    cout<<"\n--------------------------------------------------\n\n";
    cout<<"\nEnter Number to search : "; cin>>num;
    if(search(L,num))
        cout<<"\nFound..!!\n";
    else
        cout<<"\nNot Found..!!\n";
    return 0;
}

#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<stdio.h>
using namespace std;
int m;
struct bnode
{
    int *data;
    bnode *lChild;
    bnode *rChild;
};
typedef bnode* bptr;
bptr new_node()
{
    bptr t;
    t = new bnode;
    t->data = new int[m];
    for(int i=0; i<m; i++)
    {
        printf("\nEnter Data %d : ",i+1);
        cin>>t->data[i];
    }
    t->lChild = t->rChild = NULL;
    return t;
}
void insert(bptr &root, bptr t,int k)
{
    if(root == NULL)
    {
        root = t;
    }
    else
    {
        if(t->data[k] < root->data[k])
        {
            cout<<"\nL\n";
            insert(root->lChild,t,(k+1)%m);
        }
        else if(t->data[k] >= root->data[k])
        {
            cout<<"\nR\n";
            insert(root->rChild,t,(k+1)%m);
        }
    }
}
void display(bptr root)
{
    if(root!=NULL)
    {
        display(root->lChild);
        cout<<" ( ";
        for(int i=0; i<m; i++)
            cout<<root->data[i]<<",";
        cout<<" )";
        display(root->rChild);
    }
}
int main()
{
    bptr root=NULL,t; char ans='y'; int k=0;
    cout<<"\nEnter how many Data in one node : "; cin>>m;
    while(ans=='y')
    {
        t = new_node();
        insert(root,t,k);
        cout<<"Wanna Continue (y/n) ? "; cin>>ans;
    }
    display(root);
    return 0;
}
S

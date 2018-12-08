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
            insert(root->lChild,t,(k+1)%m);
        }
        else if(t->data[k] >= root->data[k])
        {
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
int search(int ar[], int k)
{
    for(int i = 0; i<m; i++)
        if(ar[i]==k)
        return 1;
    return 0;
}
int search(bptr root, int k, int flag)
{
    int flg;
    if(root)
    {
        if(search(root->data, k))
            return 1;
        else if( k < root->data[flag])
            search(root->lChild, k, (flag+1)%m);
        else if( k > root->data[flag])
            search(root->rChild, k, (flag+1)%m);
        flg = 1;
    }
    if(flg != 1)
        return 0;

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
    int flag=0;
    display(root);
    do{
        cout<<"Enter Number to Search : " ; cin>>k;
        if(search(root, k, flag))
            cout<<"\nFound..!!\n\n";
        else
            cout<<"\nNot Found..!!\n\n";
        flag = 0;
        cout<<"Wanna Continue (y/n) ? "; cin>>ans;
    }while(ans=='y');
    return 0;
}

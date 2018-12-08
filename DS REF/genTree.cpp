#include<iostream>
#include<stdlib.h>

using namespace std;
int max(int ar[], int n);
struct gtnode
{
    int data;
    int cc;
    gtnode **nextChild;
};
typedef gtnode* gtptr;
gtnode *new_gtnode()
{
    int k;
    gtnode *temp;
    temp = new gtnode;
    cout<<"\nEnter Node Data ( 0 for null) : "; cin>>k;
    if(k==0)
        return NULL;
    temp->data = k;
    cout<<"\nEnter no. of Child of Parent "<<k<<" : "; cin>>temp->cc;
    temp->nextChild = new gtnode* [temp->cc];
    for(int i=0; i<temp->cc; i++)
        temp->nextChild[i] = NULL;
    return temp;
}
void createTree(gtnode **root)
{
    gtnode *t = *root;
    for(int i=0; i< t->cc; i++)
    {
        cout<<"\nEnter "<<i+1<<" child details of parent "<<t->data<<" : ";
        t->nextChild[i] = new_gtnode();
        createTree(&t->nextChild[i]);
    }

}

void printTree(gtptr T,int ht)
{
    if( ht == 1)
    {
        cout<<"  "<<T->data;
    }
    else
    for(int i=0; i< T->cc; i++)
    {
        printTree(T->nextChild[i],ht-1);
    }
}

int height(gtptr root)
{
    if(!root)
        return -1;
    else
    {
        int i,ar[10];
        for(i = 0; i < root->cc; i++)
        {
            ar[i] = height(root->nextChild[i]);
        }
        int m = max(ar, root->cc);
        return (1+m);
    }
}

int main()
{
    gtptr root,temp; int i=0;
    root = new_gtnode();
    createTree(&root);
    cout<<"\nPrinting tree in level order ...\n";
    int ht = height(root);
    cout<<" height : "<<ht<<"\n";
    for(i=1; i<=ht; i++)
    printTree(root, i,),cout<<"\n";
    return 0;
}

int max(int ar[], int n)
{
    int i,m = 0;
    for(i=0; i< n; i++)
        if(ar[i] > m)
        m = ar[i];
    return m;
}


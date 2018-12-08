#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
using namespace std;

char inorder[20];
char preorder[20];

typedef struct bnode
{
    char data;
    bnode* lchild;
    bnode* rchild;
}* bptr;

bptr newNode(char data)
{
    bptr t = new bnode;
    t->data = data;
    t->lchild = t->rchild = NULL;
    return t;
}

int pos(char data,int start,int end)
{
    int i;
    for( i=start; i<=end ; i++)
        if(data == inorder[i])
            return i;
}

bptr insert(int start,int end)
{
    static int i=0;
    if(start > end)
        return NULL;
    bptr t = newNode(preorder[i++]);
    if(start == end)
        return t;
    int startIndex = pos(t->data,start ,end);
    t->lchild = insert(start, startIndex-1);
    t->rchild = insert(startIndex+1, end);
}

void Inorder(bptr root)
{
    if(root)
    {
        Inorder(root->lchild);
        cout<<" "<<root->data;
        Inorder(root->rchild);
    }
}

int height(bptr root)
{
    if(root == NULL)
        return 0;
    else
        return (1+max(height(root->lchild),height(root->rchild)));
}

int main()
{
    bptr root=NULL; int i;
    cout<<"\nEnter In-Order String : ";
    cin>>inorder;
    cout<<"\nEnter Pre-Order String : ";
    cin>>preorder;
    root = insert(0, strlen(preorder));
    Inorder(root);
    cout<<"\n"<<height(root);
    return 0;
}

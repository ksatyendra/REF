#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
using namespace std;
typedef struct bnode
{
    char data;
    bnode* lchild;
    bnode* rchild;
}* bptr;
void substr(char str1[],char str2[], int s,int t)
{
    int k=0;
    for(int i = s; i< t; i++)
        str1[k++] = str2[i];
    str1[k] = '\0';
}
bptr newNode(char data)
{
    bptr t = new bnode;
    t->data = data;
    t->lchild = t->rchild = NULL;
    return t;
}

int pos(char str[],char data)
{
    int i;
    for( i=0; i<strlen(str) ; i++)
        if(data == str[i])
            return i;
}

bptr insert(char inorder[],char levelorder[])
{
    static int i=0; int k=0;
    if(strlen(inorder)==0)
        return NULL;
    bptr t = newNode(levelorder[i++]);
    //cout<<" i "<<i<<" "<<t->data;
    int startIndex = pos(inorder ,t->data);
    cout<<" start "<<startIndex;
    if(strlen(levelorder)==i)
        return t;
    char temp1[10],temp2[10];
    substr(temp1,inorder, 0, startIndex);
    substr(temp2,inorder,startIndex+1 , strlen(inorder));
    //cout<<" temp1 : "<<temp1;
    //cout<<" temp2 : "<<temp2;
    t->lchild = insert(temp1,levelorder);
    t->rchild = insert(temp2,levelorder);
    return t;
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

void preorder(bptr root)
{
    if(root)
    {
        cout<<" "<<root->data;
        preorder(root->lchild);
        preorder(root->rchild);
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
    char inorder[20], levelorder[20];
    bptr root=NULL; int i;
    cout<<"\nEnter In-Order String : ";
    cin>>inorder;
    //inorder[0]='\0';
    cout<<"\nEnter level-Order String : ";
    cin>>levelorder;
    root = insert(inorder ,levelorder);
    cout<<"\nIn-order Traversal : ";
    Inorder(root);
    cout<<"\npre-order Traversal : ";
    preorder(root);
    cout<<"\nheight : "<<height(root);
    return 0;
}

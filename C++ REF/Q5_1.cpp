#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct bnode
{
    int data;
    char key;
    bnode *lchild;
    bnode *rchild;
}* bptr;

bptr getNode(int k,char key)
{
    bptr t = new bnode;
    t->data = k;
    t->key = key;
    t->lchild = t->rchild = NULL;
    return t;
}

bptr insert(bptr root, int k , char key)
{
    if(root == NULL)
    {
        root = getNode( k, key);
    }
    else
    {
        if(key < root->key)
            root->lchild = insert(root->lchild, k, key);
        else if( key > root->data)
            root->rchild = insert(root->rchild , k, key);
    }
    return root;
}

void inorder(bptr root)
{
    if(root)
    {
        inorder(root->lchild);
        cout<<" ("<<root->key<<","<<root->data<<") ";
        inorder(root->rchild);
    }
}
int isTreap(bptr root)
{
    if(!root)
        return 1;
    else
    {
        if(root->lchild)
        {
            if(root->lchild->data > root->data && root->lchild->key < root->key)
            {
                cout<<"l";
                isTreap(root->lchild);
            }
            else
                return 0;
        }
        if(root->rchild)
        {
            if(root->rchild->data > root->data && root->rchild->key > root->key)
            {
                cout<<"r";
                isTreap(root->rchild);
            }
            else
                return 0;
        }
    }
}
int main()
{
    char ans='y', ch; int k; bptr root = NULL;
    while(ans=='y')
    {
        cout<<"Enter Key And Data : ";
        cin>>ch>>k;
        root = insert(root,k,ch);
        cout<<"\nWanna Continue (y/n) ? ";
        cin>>ans;
    }
    cout<<"\n\nDisplay In-order .....\n\n";
    inorder(root);
    if(isTreap(root))
        cout<<"\n\nYeah..!! It is a Treap...\n\n";
    else
        cout<<"\n\nDon't ..!! It is Not a Treap...\n\n";
    return 0;
}




















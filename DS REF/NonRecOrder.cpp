#include<iostream>
#include<stdlib.h>
#define Max 20
using namespace std;

struct btnode
{
    btnode *lchild;
    int data;
    btnode *rchild;
};

typedef btnode * btptr;

class Stack_btree
{
    btptr ptrnode[Max];
    int top;
public:
    Stack_btree(){ top = -1; }
    void push(btptr);
    btptr pop();
    int isFull();
    int isEmpty();
    btptr topelem();
};
void Stack_btree::push(btptr node)
{
    if(isFull())
        cout<<"\nStack is Full..!!";
    else
        ptrnode[++top] = node;
}
btptr Stack_btree::topelem()
{
    if(!isEmpty())
        return ptrnode[top];
}
btptr Stack_btree::pop()
{
    if(isEmpty())
    {
        cout<<"\nstack is Empty..!!";
        return NULL;
    }
    else
        return ptrnode[top--];
}
int Stack_btree::isEmpty()
{
	if(top==-1)
	    return 1;
	else
		return 0;
}
int Stack_btree::isFull()
{
	if(Max == top+1)
		return 1;
	else
		return 0;
}

btnode *get_btnode()
{
   btnode *temp;
   temp = new btnode;
    cout<<"\n Enter the node data : ";
    cin>>temp->data;
    if(temp->data == 0)
        return NULL;
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
}
int findMax(btnode *t)
{
    if(t!=NULL)
    {
        while(t->rchild!=NULL)
            t = t->rchild;
        return t->data;
    }
    return 0;
}
void inorder(btnode *t)
{
    cout<<"\nIn-order printing....\n";
    btnode *curr,*prev;
    if(t == NULL)
        return;
    curr = t;
    while(curr != NULL)
    {
        if(curr->lchild == NULL)
        {
            cout<<" "<<curr->data;
            curr = curr->rchild;
        }
        else
        {
            prev = curr->lchild;
            while(prev->rchild != NULL && prev->rchild != curr)
            {
                prev = prev->rchild;
            }
            if(prev->rchild == NULL)
            {
                prev->rchild = curr;
                curr = curr->lchild;
            }
            else
            {
                prev->rchild = NULL;
                cout<<" "<<curr->data;
                curr = curr->rchild;
            }
        }
    }
}
void preorder(btnode *t)
{
    cout<<"\nPre-Order printing...\n";
    Stack_btree S; btptr temp;
    S.push(t);
    while(!S.isEmpty())
    {
        temp = S.pop();
        cout<<" "<<temp->data;
        if(temp->rchild)
        {
            S.push(temp->rchild);
        }
        if(temp->lchild)
        {
            S.push(temp->lchild);
        }

    }
}
void postorder(btnode *t)
{
    cout<<"\nPost-Order printing...\n";
    Stack_btree S; btptr temp;
    while(1)
    {
        if(t)
        {
            S.push(t);
            t = t->lchild;
        }
        else
        {
            if(S.isEmpty())
            {
                cout<<"\nStack is Empty..!!\n";
                break;
            }
            else if(S.topelem()->rchild == NULL)
            {
                t = S.pop();
                cout<<" "<<t->data;
                if(t == S.topelem()->rchild)
                {
                    cout<<" "<<S.topelem()->data;
                    S.pop();
                }
            }
            if(!S.isEmpty())
                t = S.topelem()->rchild;
            else
                t = NULL;
        }
    }
}

int main()
{
    btnode *root; btptr T,temp; int n,i; char ch;
    cout<<"\nEnter no. of nodes : "; cin>>n;
    root = get_btnode();
    for(i=1; i<n; i++)
    {
        T = root;
        while(T!=NULL)
        {
            temp = T;
            cout<<"\nEnter 'r' for R-child 'l' for L-child and for "<<T->data<<" : ";  cin>>ch;
            if(ch == 'l')
            {
                T = T->lchild;
                if(T == NULL)
                    temp->lchild = get_btnode();
            }
            else if(ch == 'r')
            {
                 T = T->rchild;
                 if(T == NULL)
                    temp->rchild = get_btnode();
            }
        }
    }
   // inorder(root);
    preorder(root);
   // postorder(root);
}
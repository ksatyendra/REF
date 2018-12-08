#include<bits/stdc++.h>
using namespace std;
//#define getBalance(x) (height(x->lchild)-height(x->rchild))
typedef struct AvlNode{
    AvlNode* lchild;
    int data;
    AvlNode* rchild;
    AvlNode(){
        lchild = rchild = NULL;
    }
}* nptr;

nptr SrotateL(nptr root);
nptr SrotateR(nptr root);
nptr DrotateL(nptr root);
nptr DrotateR(nptr root);
int height(nptr root);
int isBalanced(nptr root);
int getBalance(nptr root);
nptr insert(nptr root, int k);
int search(nptr root, int k);
nptr findMin(nptr T);
nptr deleteNode(nptr T, int k);
void levelPrint(nptr root, int lev);
void display(nptr root);

int main()
{
    nptr root = NULL; int k; char ans='1',ch;
    while(ans=='1')
    {
        cout<<"\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit \n\t Select Choice ";
        cin>>ch;
        switch(ch)
        {
        case '1':
            cout<<"\nEnter Data to Insert : "; cin>>k;
            root = insert(root, k);
            break;
        case '2':
            cout<<"\nEnter Data to Search : "; cin>>k;
            if(search(root, k) == 1)
                cout<<"\nFound..!!\n";
            else
                cout<<"\nNot Found..!!\n";
            break;
        case '3':
            cout<<"\nEnter Data to Delete : "; cin>>k;
            root = deleteNode(root, k);
            break;
        case '4':
            cout<<"\n----------Displaying Level-Order Traversal-----------\n";
            display(root);
            cout<<"\n--------------------------------------------------\n";
            break;
        case '5':
            exit(0);
        default:
            cout<<"\nWrong Choice..!!\n";
        }
    }
    return 0;
}

nptr SrotateL(nptr root)
{
    if(!root)
        return NULL;
    nptr t = root->rchild;
    root->rchild = t->lchild;
    t->lchild = root;
    return t;
}

nptr SrotateR(nptr root)
{
    if(!root)
        return NULL;
    nptr t = root->lchild;
    root->lchild = t->rchild;
    t->rchild = root;
    return t;
}

nptr DrotateL(nptr root)
{
    root->lchild = SrotateR(root->lchild);
    root = SrotateL(root);
    return root;
}

nptr DrotateR(nptr root)
{
    root->rchild = SrotateL(root->rchild);
    root = SrotateR(root);
    return root;
}

int height(nptr root)
{
    if(!root)
        return -1;
    else
        return ( 1+ max( height(root->lchild), height(root->rchild) ));
}

int isBalanced(nptr root)
{
    if(!root)
        return 1;
    int b = abs(height(root->lchild) - height(root->rchild));
    if( b < 2)
        return 1;
    return 0;
}

int getBalance(nptr root){
    return (height(root->lchild) - height(root->rchild));
}
nptr insert(nptr root, int k)
{
    if(!root){
        root = new AvlNode;
        root->data = k;
        return root;
    }
    if( k < root->data){
        root->lchild = insert(root->lchild, k);
        if(!isBalanced(root) && getBalance(root) > 0){
            if( k < root->lchild->data)
                root = SrotateR(root);
            else
                root = DrotateR(root);
        }
    }
    else if( k > root->data){
        root->rchild = insert(root->rchild, k);
        if(!isBalanced(root) && getBalance(root) < 0 ){
            if( k > root->rchild->data )
                root = SrotateL(root);
            else
                root = DrotateL(root);
        }
    }
    return root;
}

int search(nptr root, int k){
    if(root){
        if(root->data == k)
            return 1;
        else if(root->data > k)
            search(root->lchild, k);
        else if(root->data < k)
            search(root->rchild, k);
    }
}
nptr findMin(nptr T)
{
    if(T == NULL)
        return NULL;
    else if (T->lchild == NULL)
        return T;
    else
        return findMin(T->lchild);
}
nptr deleteNode(nptr T, int k)
{
    nptr tmp;
    if(T != NULL)
    {
        if(k < T->data)
            T->lchild = deleteNode(T->lchild,k);
        else if(k > T->data)
            T->rchild = deleteNode(T->rchild,k);
        else if(T->lchild && T->rchild)
        {
            tmp = findMin(T->rchild);
            T->data = tmp->data;
            T->rchild = deleteNode(T->rchild,T->data);
        }
        else{
            tmp = T;
            if( T->lchild == NULL)
                T = T->rchild;
            else if(T->rchild == NULL)
                T = T->lchild;
        }
        if(!isBalanced(T)){
            if(getBalance(T) > 0){
                if( k < T->lchild->data)
                    T = SrotateR(T);
                else
                    T = DrotateR(T);
            }
            else if(getBalance(T) < 0){
                if( k > T->rchild->data )
                    T = SrotateL(T);
                else
                    T = DrotateL(T);
            }
        }
    }
    return T;
}
void levelPrint(nptr root, int lev){
    if(!root) return;
    if(lev==0)
        cout<<setw(3)<<root->data;
    else{
        levelPrint(root->lchild, lev-1);
        levelPrint(root->rchild, lev-1);
    }
}
void display(nptr root)
{
    int h = height(root);
    for(int i=0; i<=h; i++){
        cout<<"\n";
        levelPrint(root,i);
    }
}

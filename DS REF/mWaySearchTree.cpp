#include<iostream>
using namespace std;
struct MStree
{
   int data1,data2;
   MStree *lchild,*mchild,*rchild;
};
typedef MStree* mstptr;
void insert(MStree *,int );
void inorder(MStree *);
MStree *get_MStree()
{
   MStree *temp;
   temp = new MStree;
   temp->data1 = 0;
   temp->data2 = 0;
   temp->lchild = NULL;
   temp->mchild = NULL;
   temp->rchild = NULL;
   return temp;
}
//Main Function
int main()
{
    MStree *root = NULL; int k;  char ans;
    do
    {
        cout<<"\nEnter Data : "; cin>>k;
        if (root == NULL)
        {
            root = get_MStree();
            root->data1 = k;
        }
        else
            insert(root, k);
        cout<<"\nWant To enter More Elements (y/n) : ";
        cin>>ans;
    } while (ans == 'y' || ans=='y');
    cout<<"\n=====Printing In-order======\n\n";
    inorder(root);
    cout<<"\n\n============================\n";
    return 0;
}

void insert(MStree *root,int k)
{
    if(k < root->data1)
    {
        if (root->lchild == NULL)
        {
            root->lchild = get_MStree();
            root->lchild->data1 = k;
        }
        else
            insert(root->lchild, k);
    }
    if (k > root->data1)
    {
        if(root->data2 == 0)
        {
            root->data2 = k;
        }
        if(k < root->data2)
        {
            if(root->mchild==NULL)
            {
                root->mchild = get_MStree();
                root->mchild->data1 = k;
            }
            else
                insert(root->mchild,k);
        }
        else if(k > root->data2)
        {
            if( root->rchild == NULL)
            {
                root->rchild = get_MStree();
                root->rchild->data1 = k;
            }
            else
                insert(root->rchild, k);
        }
    }
}
void inorder(MStree *temp)
{
   if (temp != NULL)
    {
      inorder(temp->lchild);
      if(temp->data1!=0)
        cout<<" "<<temp->data1;
      inorder(temp->mchild);
      if(temp->data2!=0)
        cout<<" "<<temp->data2;
      inorder(temp->rchild);
    }
}

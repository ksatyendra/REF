#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<math.h>
using namespace std;
struct bnode
{
   int data;
   bnode *lchild, *rchild;
};
typedef bnode* bstptr;
void insert(bstptr , bstptr );
int height(bstptr );
bstptr get_bnode();
void PrintTree(bstptr ,int );
int main()
{
   int choice;
   char ans = 'N';
   int key,ht;
   bnode *new_bnode, *root=NULL;
   do
    {
        new_bnode = get_bnode();
        if (root == NULL)
            root = new_bnode;
        else
            insert(root, new_bnode);
        cout<<"\nWanna Continue ? (y/n) : ";
        cin>>ans;
    }while(ans=='y');
    ht = height(root);
    cout<<"\n\n\tPrinting Level order \n\n";
    for(int i=ht; i >=1; i--)
    {
        PrintTree(root,i);
    }
   return 0;
}
int height(bstptr root)
{
   if (root==NULL)
       return 0;
    else
      return (1+max(height(root->lchild),height(root->rchild)));
}
void PrintTree(bstptr root, int level)
{
  if(level == 1)
    cout<<" "<<root->data;
  else if(level > 1)
  {
    PrintTree(root->lchild, level-1);
    PrintTree(root->rchild, level-1);
  }
}
bstptr get_bnode()
{
   bstptr temp;
   temp = new bnode;
    cout<<"\nenter node data : "; cin>>temp->data;
   temp->lchild = NULL;
   temp->rchild = NULL;
   return temp;
}
void insert(bnode *root,bnode *new_bnode)
{
   if (new_bnode->data < root->data)
    {
      if (root->lchild == NULL)
         root->lchild = new_bnode;
      else
         insert(root->lchild, new_bnode);
    }
    if (new_bnode->data >= root->data)
    {
      if (root->rchild == NULL)
         root->rchild = new_bnode;
      else
         insert(root->rchild, new_bnode);
    }
}

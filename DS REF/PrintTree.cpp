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
typedef bnode * bstptr;
bstptr insert(bstptr ,int );
void inorder(bstptr );
int height(bstptr node);
void PrintTree(bstptr ,int ,int );
void printSpace(int k)
{
    for(int i=0; i<k ; i++)
        cout<<"  ";
}
int main()
{
    bstptr root = NULL; int i,ht,k;
    while(1){
        cin>>k;
        if(!k) break;
        root = insert(root, k);
    }
    ht  = height(root);
    cout<<"\n\n\tPrinting Tree\n\n";
    for(int i=1; i <= ht; i++)
    {
        PrintTree(root,i,ht-i+1);
        cout<<"\n\n";
    }
   return 0;
}
bstptr insert(bstptr root, int key){
    if(!root){
        root = new bnode;
        root->data = key;
        root->lchild = root->rchild = NULL;
        return root;
    }
    if(key < root->data)
        root->lchild = insert(root->lchild, key);
    else if(key > root->data)
        root->rchild = insert(root->rchild, key);
    return root;
}
int height(bstptr root)
{
   if (root==NULL)
       return 0;
   else
    return(1+max(height(root->lchild), height(root->rchild)));
}
void PrintTree(bstptr root, int level,int ht)
{
  if(root == NULL) return;
  if(level == 1)
      cout<<setw(2)<<root->data;
  else if(level > 1)
  {
    PrintTree(root->lchild, level-1, ht);
    PrintTree(root->rchild, level-1, ht);
  }
}

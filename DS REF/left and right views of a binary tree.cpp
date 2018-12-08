// Author: Abhiram
// Branch: III/IV ECE
// Solution For: Left and Right Views of a Binary Tree

#include<iostream>
using namespace std;
struct node
{
       node*left,*right;
       char data;
}*root;

class btree
{
      private:  
             char *a;
             int cnt,max;
             
      public:
              void inorder(node *sr);
              void insert(int index,int size);
              btree(char *ar,int index);
              node* buildtree(char *ar,int index,int size);
              void display();
};

btree::btree(char *ar,int index)
{
                  max=cnt=0;
                  root=NULL;
                  a=new char[index];
                  for(int i=0;i<index;i++)
                  a[i]=ar[i];
}

void btree::display()
{
     inorder(root);
     return;
}

void btree::insert(int index,int size)
{
     root=buildtree(a,index,size);
     return;
}

void btree::inorder(node *sr)
{
     if(sr!=NULL)
     {
                 inorder( sr -> left ) ;
                 cout << sr -> data << " " ;
		         inorder (sr -> right) ;
	 }
	 return;
}

node* btree::buildtree(char *ar,int index,int size)
{
      node *temp=NULL;
      if(*(ar+index)!='\0'&&index<size)
      {
                           temp=new node;
		                   temp -> left = buildtree ( ar, 2 * index + 1 ,size) ;
		                   temp -> data = * ( ar + index ) ;
		                   temp -> right = buildtree ( ar, 2 * index + 2 ,size) ;
      }
      return temp;
}

int main( )
{      
	char arr[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'} ;
    int sz = sizeof ( arr ) ;
	btree bt ( arr, sz )  ;
	bt.insert ( 0 ,sz) ;
	bt.display( ) ;
	system("PAUSE");
	return 0;
} 

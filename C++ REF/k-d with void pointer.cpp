#include<iostream>
using namespace std;

struct node
{
    void *p[2]; 
	node* left;
	node* right;
};
int height(node* temp);
node* insert(node* root,int data,char ch)
{
	if(root==NULL)
	{
		node* temp=new node;
		temp->p[0]=new int;
		temp->p[1]=new char;
		*(int*)(temp->p[0])=data;
		*(char*)(temp->p[1])=ch;
		root=temp;temp->left=NULL;
		temp->right=NULL;
		return root;
	}
	int h=height(root);  // 1
	cout<<h<<" ";
	int i=h%2;
	 if(data<=(*(int*)(root->p[i])))
	{
		root->left=insert(root->left,data,ch);
	}
	else
	{
		root->right=insert(root->right,data,ch);
	}
	return root;
}

int height(node* temp)
{
	if(temp==NULL)
	return 0;
	int t1=height(temp->left);
	int t2=height(temp->right);
	if(t1>t2)
	return t1+1;
	else
	return t2+1;
	
}
void preorder(node* root)
{
	if(root==NULL)
	return ;
	cout<<*(int*)(root->p[0])<<" "<<*(char*)(root->p[1])<<endl;
	preorder(root->left);
	preorder(root->right);
}
 
int main()
{
  node* root=NULL;
 /* root=insert(root,15,'x');	
  root=insert(root,10,'h');
  root=insert(root,20,'g');
  root=insert(root,25,'d');
  root=insert(root,80,'e');
  root=insert(root,12,'o');
   root=insert(root,55,'q');
  root=insert(root,62,'t');
  */
  root=insert(root,10,'x');
   root=insert(root,20,'q');
  root=insert(root,30,'t');
  root=insert(root,5,'a');
  preorder(root);
  

}

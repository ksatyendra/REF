#include<iostream>
#include<cstdlib>
#include"queuetemplate.cpp"
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data,space_id;
	bstnode *rchild;
};
void insert(bstnode* &b,int k)
{
	if(b==NULL)
	{
		b=new bstnode;
		b->data=k;
		b->lchild=NULL;
		b->rchild=NULL;
	}
	if(k>b->data)
	{
		insert(b->rchild,k);
	}
	else if(k<b->data)
	insert(b->lchild,k);

}
void construct(bstnode* t,bstnode* t1,bstnode* t2)
{
	static int i=t1->data;
	if(t==NULL)
	return;
	else
	if(t->data<i)
	{
	/*	t1->lchild=new bstnode;
		t1->lchild->data=t->data;
		t1->lchild->lchild=NULL;
		t1->lchild->rchild=NULL;
		t1=t1->lchild;
		*/insert(t1,t->data);
	}
	else if(t->data>i)
	{
		/*t2->rchild=new bstnode;
		t2->rchild->data=t->data;
		t2->rchild->lchild=NULL;
		t2->rchild->rchild=NULL;
		t2=t2->rchild;
		*/
		insert(t2,t->data);
	}		
	construct(t->lchild,t1,t2);
	construct(t->rchild,t1,t2);
}
int findmax(bstnode *b)
{
	if(b->rchild==NULL)
	return(b->data);
	else
	return(findmax(b->rchild));

}
int findmin(bstnode *b)
{
	if(b->lchild==NULL)
	return(b->data);
	else
	return(findmin(b->lchild));
}
bstnode* findmaxp(bstnode *b)
{
	if(b->rchild==NULL)
	return(b);
	else
	return(findmaxp(b->rchild));

}
bstnode* findminp(bstnode *b)
{
	if(b->lchild==NULL)
	return(b);
	else
	return(findminp(b->lchild));
}
void print(bstnode* b,int in,int pre,int post)
{
 if(b==NULL)
 return;
  if(pre==1)
  cout<<b->data<<" ";
  print(b->lchild);
  if(in==1)
  cout<<b->data<<" ";
  print(b->rchild);
  if(post==1)
  cout<<b->data<< " " ;
}
void inorder(bstnode *b)
{
	if(b!=NULL)
	{
	inorder(b->lchild);
	cout<<b->data<<" ";
	inorder(b->rchild);
	}
}
void find(bstnode *b,int k)
{   if(b!=NULL)
    {

	if(b->data==k)
	{
		cout<<"Element is present in the tree...\n";
		return;
	}
	else if(k>b->data)
	find(b->rchild,k);
	else if(k<b->data)
	find(b->lchild,k);
    }
	else
	cout<<"Element is not present in the tree..\n";

}
void delete_node(bstnode* &b,int k)
{
	if(b==NULL)
	return;		//Item not found
	if(k>b->data)
	delete_node(b->rchild,k);
	else if(k<b->data)
	delete_node(b->lchild,k);
	else if(b->lchild!=NULL&&b->rchild!=NULL)
	{
		b->data=findminp(b->rchild)->data;
		delete_node(b->rchild,b->data);
	}
	else
	{
		bstnode *t=b;
		b=(b->lchild!=NULL) ? b->lchild :b->rchild;
		delete t;
	}
}
void print_level_order(bstnode *root)
{	if(root==NULL)
	return;
	queue<bstnode*> q(20);
	bstnode *temp,*l,*r;
	q.enqueue(root);
	q.enqueue(NULL);
	
	while(!q.empty())
	{
		temp=q.dequeue();
		if(temp!=NULL)
		{
		cout<<temp->data<<" ";
		if(temp->lchild!=NULL) q.enqueue(temp->lchild);
		if(temp->rchild!=NULL) q.enqueue(temp->rchild);
		}
		else
		 if (!q.empty())
            {	cout<<endl;
				q.enqueue(NULL);
			}
             
              
	}
}
int i=0;
void spaces_id(bstnode *b)
{
	if(b!=NULL)
	{
	spaces_id(b->lchild);
	b->space_id=i;
	i++;

	cout<<b->data<<" "<<b->space_id<<" \n";
	spaces_id(b->rchild);
	}
}
void print_spaces(int n)
{	for(int i=0;i<2*n;i++)
	cout<<"*";
}
void print_like_tree(bstnode *root)
{
	spaces_id(root);
	if(root==NULL)
	return;
	queue<bstnode*> q(20);
	bstnode *temp,*l,*r;
	q.enqueue(root);
	q.enqueue(NULL);
	
	while(!q.empty())
	{
		temp=q.dequeue();
		if(temp!=NULL)
		{
		print_spaces(temp->space_id);
		cout<<temp->data;
		if(temp->lchild!=NULL) q.enqueue(temp->lchild);
		if(temp->rchild!=NULL) q.enqueue(temp->rchild);
		}
		else
		 if (!q.empty())
            {	cout<<endl;
				q.enqueue(NULL);
			}
             
              
	}
	
}
int max(int x,int y)
{
	if(x>=y)
	return x;
	else
	return y;
}
int height(bstnode* b)
{	

	if(b==NULL)
	return -1;
	else
	return(max(height(b->lchild),height(b->rchild))+1);
	//if(height(b->lchild)>=height(b->rchild))
	//return(height(b->lchild)+1);
	//else
	//return(height(b->rchild)+1);
}
void balanced_tree(bstnode *b)
{
	if(b!=NULL)
	{	int hleft,hright;
		hleft=height(b->lchild);
		hright=height(b->rchild);
		if((hleft-hright==0)||(hleft-hright==1)||(hleft-hright==-1))
		{
			balanced_tree(b->lchild);
			balanced_tree(b->rchild);
			cout<<"Tree is Balanced..."<<endl;
		}
		//cout<<"Tree is not Balanced..."<<endl;
	}
	
}

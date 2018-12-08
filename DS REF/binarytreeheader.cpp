#include<iostream>
#include<cstdlib>
#include<stack>
#include"queuetemplate.cpp"
using namespace std;
struct btnode
{
	btnode *lchild;
	char data;
	btnode *rchild;
};
void insert(btnode* &b,char k)
{	if(k!='0')
	{
	char x;	
	if(b==NULL)
	{	
		b=new btnode;
		b->data=k;
		b->lchild=NULL;
		b->rchild=NULL;
	}
		cout<<"Enter the lchild of "<<b->data<<" else 0: ";
		cin>>x;  
		insert(b->lchild,x);
	
		cout<<"Enter the rchild of "<<b->data<<" else 0: ";
		cin>>x;
		insert(b->rchild,x);
	}

}
void print_level_order(btnode *root)
{	if(root==NULL)
	return;
	queue<btnode*> q(20);
	btnode *temp;
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
void printf(btnode* b,int in,int pre,int post)
{
 if(b==NULL)
 return;
  if(pre==1)
  cout<<b->data<<" ";
  printf(b->lchild,in,pre,post);
  if(in==1)
  cout<<b->data<<" ";
  printf(b->rchild,in,pre,post);
  if(post==1)
  cout<<b->data<< " " ;
}
void inorder(btnode *b)
{
	if(b!=NULL)
	{
	inorder(b->lchild);
	cout<<b->data<<" ";
	inorder(b->rchild);
	}
}
void preorder(btnode *b)
{
	if(b!=NULL)
	{
	
	cout<<b->data<<" ";
	preorder(b->lchild);
	preorder(b->rchild);
	}
}
void postorder(btnode *b)
{
	if(b!=NULL)
	{
	

	postorder(b->lchild);
	postorder(b->rchild);
	cout<<b->data<<" ";
	}
}
void print_preorder(btnode *b)
{
/*	stack<btnode*> s;
	btnode *t;
	s.push(b);
	cout<<b->data<<" ";
	while(b!=NULL)
	{	
		b=b->lchild;
		if(b!=NULL) 
		{
			s.push(b);
			cout<<b->data<<" ";
		}
	}
	while(!s.empty())
	{
		b=s.top();
		s.pop();
		if(b->rchild!=NULL)
		{
			t=b->rchild;
			s.push(t);
			cout<<t->data<<" ";
			while(t!=NULL)
			{	
				t=t->lchild;
				if(t!=NULL) 
				{
					s.push(t);
					cout<<t->data<<" ";
				}
			}
		}
		
	}*/
		stack<btnode*> s;
	s.push(b);
	while(!s.empty())
	{
		btnode *t=s.top();
		s.pop();
		cout<<t->data<<" " ;
		if(t->rchild!=NULL)
		s.push(t->rchild);
		if(t->lchild!=NULL)
		s.push(t->lchild);
	}
	
	
}
void print_inorder(btnode *b)
{	/*
	stack<btnode*> s;
	btnode *t;
	s.push(b);
	//cout<<b->data<<" ";
	while(b!=NULL)
	{	
		b=b->lchild;
		if(b!=NULL) 
		{
			s.push(b);
			//cout<<b->data<<" ";
		}
	}
	while(!s.empty())
	{
		b=s.top();
		s.pop();
		cout<<b->data<<" ";
		if(b->rchild!=NULL)
		{
			t=b->rchild;
			s.push(t);
			//cout<<t->data<<" ";
			while(t!=NULL)
			{	
				t=t->lchild;
				if(t!=NULL) 
				{
					s.push(t);
				//	cout<<t->data<<" ";
				}
			}
		}
		
	}
	*/
		stack<btnode*> s;
	btnode *t;
	while(1)
	{
		while(b!=NULL)
		{
			s.push(b);
			b=b->lchild;
		}
		if(!s.empty())
		{
			b=s.top();
			s.pop();
		}
		else
		break;
		cout<<b->data<<" ";
		b=b->rchild;
			
		}
}
void print_postorder(btnode *root)
{
	stack<btnode*> child;
	stack<btnode*> parent;
	if(root==NULL)
	return;
	child.push(root);//Initialize
	while(!child.empty())
	{
		btnode *t=child.top();
		child.pop();
		parent.push(t);
		if(t->lchild) 
			child.push(t->lchild);
		if(t->rchild)
			child.push(t->rchild);	
	}
	while(!parent.empty())
	{
		cout<<parent.top()->data<<" ";
		parent.pop();
		}
	
}




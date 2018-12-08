#include<iostream>
#include<cstdlib>
#include"queuetemplate.cpp"
using namespace std;
struct gnode
{
	gnode *firstchild;
	int data;
	gnode *nextsibling;
};
void insert(gnode* &b,int k)
{	if(k!=0)
	{
	int x;	
	if(b==NULL)
	{	
		b=new gnode;
		b->data=k;
		b->firstchild=NULL;
		b->nextsibling=NULL;
	}
		if(b->firstchild==NULL)
		{
			cout<<"Enter the Firstchild of "<<b->data<<" else 0: ";
			cin>>x;  
			insert(b->firstchild,x);
		}
		cout<<"Enter the next sibling of "<<b->data<<" else 0: ";
		cin>>x;
		insert(b->nextsibling,x);
	}
}
void inorder(gnode *b)
{
	if(b!=NULL)
	{
	inorder(b->firstchild);
	cout<<b->data<<" ";
	inorder(b->nextsibling);
	}
}
void print_level_order(gnode *root)
{	if(root==NULL)
	return;
	queue<gnode*> q(20);
	gnode *temp;
	q.enqueue(root);
	q.enqueue(NULL);
	
	while(!q.empty())
	{
		temp=q.dequeue();
		if(temp!=NULL)
		{
		cout<<temp->data<<" ";
		if(temp->firstchild!=NULL) q.enqueue(temp->firstchild);
		
		gnode* t=temp->firstchild;
		while(t!=NULL) 
		{cout<< "IN" <<endl;
			q.enqueue(t->nextsibling);
			t=t->nextsibling;
		
		}
		}
		else{	cout<<endl;
			if(!q.empty())
				q.enqueue(NULL);}
             
              
	}
}
void print(gnode *g)
{
	gnode *t=g;
	if(g!=NULL)
	{
	while(g!=NULL)
	{
		cout<<g->data<<" ";
		g=g->nextsibling;
	}
	cout<<"\n";
	while(t!=NULL)
	{
	
		print(t->firstchild);
		t=t->nextsibling;
		cout<<" ";
	}
	}
}
int main()
{
    int flag,num,i,pos,choice;
    gnode *m=NULL,*n=NULL;
    cout<<"Menu:\n";
    cout<<"1.Insert\n2.Display\n3.Exit\n";
    while(1)
    {	cout<<"Enter choice: ";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter the root parent: ";
			cin>>num;
			insert(m,num);
		}
		if(choice==2)
		//inorder(m);
			print(m);
		//print_level_order(m);
		if(choice==3)
		exit(1);
	}
	return 0;
}
	

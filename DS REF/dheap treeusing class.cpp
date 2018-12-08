#include<iostream>
#include"dendqueuetemplate.cpp"
using namespace std;
class heap
{	public:
	heap();
	struct node
	{
		int data;
		node* parent;
		node **n;
		node();
	}*p;
	int d;
	node::node()
	{	
		parent=NULL;
		n=new node[d];
		for(int i=0;i<d;i++)
		n[i]=NULL;	
	}
	queue<node*> q(20);
	void insert(int k);
	void delete_top();
	void display();
};
heap::heap(int x)
{
	d=x;
	p=NULL;
}
void heap::insert(int k)
{
	if(p==NULL)
	{
		p=new node;
		q.enqueue(p);
		return;
	}
	else
	{
	
	}
}

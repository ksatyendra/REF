#include<iostream>
#include"queuetemplate.cpp"
#include<cstdlib>
using namespace std;
struct gnode
{
	char data;
	gnode **n;
	gnode *parent;
	int no_child;
	gnode();
};
gnode::gnode()
{
	n=NULL;
	parent=NULL;
}
void insert(gnode* &g,char c,gnode *parent)
{	char ch;
	if(g==NULL)
	{	
		g=new gnode;
		g->data=c;
		g->parent=parent;
	}
	cout<<"How many children for "<<g->data<<" else 0: ";
	cin>>g->no_child;
	if(g->no_child!=0)
	{
		g->n=new gnode*[g->no_child];
		for(int i=0;i<g->no_child;i++)
		g->n[i]=NULL;
		for(int i=0;i<g->no_child;i++)
		{
			cout<<"Enter the "<<i+1<<"child of "<<g->data<<": ";
			cin>>ch;
			insert(g->n[i],ch,g);	
			
		}
	}
}
void print(gnode *b)
{
	if(b!=NULL&&b->n!=NULL)
	{
		cout<<b->data<<" : ";
		if(b->n!=NULL)
		{
			for(int i=0;i<b->no_child;i++)
			{
				cout<<b->n[i]->data<<" ";	
			}
			cout<<endl;
			for(int i=0;i<b->no_child;i++)
			print(b->n[i]);
		}
	}
}
void print_level_order(gnode* b)
{
	queue<gnode*> q(20);
	q.enqueue(b);
	q.enqueue(NULL);
	gnode* temp;
	
	while(!q.empty())
	{
	temp=q.dequeue();
	if(temp!=NULL)
	{
		cout<<temp->data<<" ";
		for(int i=0;i<temp->no_child;i++)
		{
			if(temp->n[i]!=NULL)
			q.enqueue(temp->n[i]);
			
		}
	}
		else
		if (!q.empty())
            {	cout<<endl;
				q.enqueue(NULL);
			}
	
	}
}
int main()
{
    int flag,num,i,pos,choice;
    gnode *m=NULL,*n=NULL;
    char ch;
    cout<<"Menu:\n";
    cout<<"1.Insert\n2.Display\n3.Exit\n";
    while(1)
    {	cout<<"Enter choice: ";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter the root parent: ";
			cin>>ch;
			insert(m,ch,NULL);
		}
		if(choice==2)
		//print(m);
		print_level_order(m);
		if(choice==3)
		exit(1);
	}
	return 0;
}


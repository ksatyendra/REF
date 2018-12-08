#include<iostream>
#include<cstdlib>
#include"queuetemplate.cpp"
using namespace std;
struct gnode
{
	int data;
	gnode **n;
	gnode *parent;
	gnode();
};
gnode::gnode()
{
	n=NULL;
	parent=NULL;

}
void percolateup(gnode *h)
{
	if(h->parent!=NULL)
	{
		if(h->data<h->parent->data)
		{
			swap(h->data,h->parent->data);
			percolateup(h->parent);
		}
	}
}
void levelenqueue(queue<gnode*> q,int k,int d)
{
	gnode *b=NULL;
	if(q.front!=q.rear)
	{
		b=q.dequeue();
		if(b!=NULL)
		{	
			for(int i=0;i<d;i++)
			{
				if(b->n[i]!=NULL)
				q.enqueue(b->n[i]);
				else
				{
					b->n[i]=new gnode;
					b->n[i]->n=new gnode*[d];
					for(int j=0;j<d;j++)
					b->n[i]->n[j]=NULL;
					b->n[i]->data=k;
					b->n[i]->parent=b;
					percolateup(b->n[i]);
					return;
				}
			}
		}
		else if(b==NULL&&q.rear!=NULL)
		q.enqueue(b);
		levelenqueue(q,k,d);
	}	
}

void insert(gnode* &b,int k,int d)
{	int i;
	if(b==NULL)
	{
	b=new gnode;
	b->data=k;
	b->n=new gnode*[d];
	for(i=0;i<d;i++)
	b->n[i]=NULL;
	}
	else
	{
		queue<gnode*> q(20);
		q.enqueue(b);
		q.enqueue(NULL);
		levelenqueue(q,k,d);
	}
}
gnode* lastelement(queue<gnode*> q,int d)
{
	gnode *b=NULL;
	if(q.front!=q.rear)
	{
		b=q.dequeue();
		if(b!=NULL)
		{	
			if(b->n[0]==NULL&&q.elements[q.front]==NULL)
			{
				gnode *t=b;
				b=b->parent;
				for(int i=0;i<d;i++)
				{
					if(b->n[i]==t)
					{
						b->n[i]=NULL;
						break;
					}
				}
				return t;
			}
			for(int i=0;i<d;i++)
			if(b->n[i]!=NULL)
			q.enqueue(b->n[i]);
		}
		else if(b==NULL&&q.rear!=NULL)
		{
			q.enqueue(b);
		}
		return(lastelement(q,d));
	}
}
void percolatedown(gnode *&h,int d)
{
	int min,pos;
	if(h!=NULL)
	{
		if(h->n[0]!=NULL)
		{
			min=h->n[0]->data;pos=0;
			for(int i=0;i<d-1;i++)
			{
				if(h->n[i+1]!=NULL)
				{
					if(h->n[i+1]->data<min)
					{
						min=h->n[i+1]->data;
						pos=i+1;
					}
				}
				else break;
			}
			if(h->data>h->n[pos]->data)
			{
				swap(h->data,h->n[pos]->data);
				percolatedown(h->n[pos],d);
			}
			else return;
		}
	}
}
void deletion(gnode *&h,int d)
{
	if(h!=NULL)
	{
		queue<gnode*> q(20);
		cout<<h->data<<" ";
		gnode *t=NULL;
		q.enqueue(h);
		q.enqueue(t);
		if(h->n[0]==NULL)
		{
			h=NULL;return;
		}
		else
		h->data=(lastelement(q,d))->data;
		percolatedown(h,d);
		deletion(h,d);
	}
}
void roottreetoqueue(gnode *b,queue<gnode*> &q)
{
	if(b!=NULL)
	{
	gnode *t=NULL;
	q.enqueue(b);
	q.enqueue(t);
	}
}
void print_level_order(gnode* b,int d)
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
		for(int i=0;i<d;i++)
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
	int n,num,i,d,choice;
	queue<gnode*> queue(20);
	cout<<"Enter d value: ";
        cin>>d;
        gnode *heap=NULL,*head=NULL;
        cout<<"Menu:\n";
   		 cout<<"1.Insert\n2.Display level order\n3.Display in sorted order\n4.Exit\n";
   		 while(1)
   		 {
			cout<<"Enter choice: ";
			cin>>choice;
			if(choice==1)
			{
        	cout<<"Enter the number: ";
			cin>>num;
			if(heap==NULL)
			{
			insert(heap,num,d);
			head=heap;
			}
			else
			insert(heap,num,d);
			}
			if(choice==2)
			print_level_order(head,d);
			if(choice==3)
			{
				roottreetoqueue(head,queue);
				queue.front=NULL;queue.rear=NULL;
				deletion(head,d);
				}
				if(choice==4)
				exit(1);
			
		}
		cout<<endl;
	return 0;
}


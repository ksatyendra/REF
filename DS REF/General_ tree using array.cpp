#include<iostream>
#include<cstdlib>
using namespace std;
struct gnode
{
	char data;
	gnode *n;
};
void insert(gnode *g,char c)
{	char ch;
	int no_child;
	if(g==NULL)
	{	
		g=new gnode;
		g->data=c;
		g->n=NULL;
	}
	else g->data=c;
	cout<<"How many children for "<<g->data<<" else 0: ";
	cin>>no_child;
	if(no_child!=0)
	{
		//g=new gnode;
		g->n=new gnode[no_child];
		for(int i=0;i<no_child;i++)
		{
			cout<<"Enter the "<<i+1<<"child data: ";
			cin>>ch;
			insert(&(g->n[i]),ch);
			
		}
	}
	else
	g->n=NULL;
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
			insert(m,ch);
		}
		if(choice==2)
		//inorder(m);
		//print(m);
		if(choice==3)
		exit(1);
	}
	return 0;
}


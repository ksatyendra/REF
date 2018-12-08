#include<iostream>
#include<cstdlib>
#include"linkedlisttemplate.cpp"
using namespace std;
struct gnode
{
	char c;
	ll<gnode> n;
};
void insert(gnode *g,char c)
{	char ch;
	if(g==NULL)
	{	
		g=new gnode;
		g->data=c;
		g->n=NULL;
	}
	g->data=ch;
	cout<<"Enter children for "<<g->data<<" else 0: ";
	cin>>ch;
	while(ch!=0)
	{
		g->n.append(ch);
		insert(g->n->n,ch);

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


#include<iostream>
using namespace std;
struct n
{
 int d;
 n *l;
};
void dis(n *h)
{
	cout<<"List is :\n";
	while(h->l != NULL)
    {
    	h = h->l;
		cout<<h->d<<"  ";
    } 
}
void in(n *h)
{
	n *t;
	int dt;
	char ch='y';
	while(ch=='y')
	{
		cout<<"Enter no. : ";
		cin>>dt;
	    t=new n;
	    t->l=NULL;
		t->d=dt;
		h->l=t;
		h=h->l;
		cout<<"\nIf you want to enter more no. then enter 'y' otherwise 'n' : ";
		cin>>ch;
    }
}
void sort(n *h)
{
	int sz=0,p,i,j;
	for(n *t1=h->l;t1->l!=NULL;t1=t1->l,sz++);
	for(i=0;i<sz;i++)
    {
	 n *t2=h->l;
	 for(j=0;j<sz;j++,t2=t2->l)
     { 
	  if(t2->d>t2->l->d)
	  {
	   p=t2->d;
	   t2->d=t2->l->d;
       t2->l->d=p;
	  }	
	 }
	}
	for(n *t1=h->l;t1->l!=NULL;)
	 if(t1->d==t1->l->d)
	  t1->l=t1->l->l;
	 else
	  t1=t1->l;
}
int main()
{
	int ch=0;
	n *h=new n;
	while(ch!=3)
	{
		cout<<"\nEnter our choice [1 to input & 2 to display & 3 to exit & 4 to sort] : ";
		cin>>ch;
		if(ch==3)
	     return 0;
	    else if(ch==4)
	     sort(h);
		else if(ch==2)
	     dis(h);
        else if(ch==1)
	     in(h);
	     else
	     {  
		   cout<<"\nEnter right choice.\n";
	       continue;
		 }
	}	
}

#include<iostream>
using namespace std;
class ll
{

	struct node
	{
    int data;
    node *sublist;
    node *next;
	}*p;
	public:
		void getdata(int no_courses);
		void append(int );
		ll();
		void display();
		void topological_sort(int c);
};
ll::ll()
{
	p=NULL;
}
void ll :: append ( int num )
{
	node *temp ;
	temp = p ;

	// if the list is empty, create first node
	if ( temp == NULL )
	{
		temp = new node ;
		p = temp ;
	}
	else
	{
		// go to last node
		while ( temp -> next != NULL )
			temp = temp -> next ;

		// add node at the end
		temp -> next = new node ;
		temp = temp -> next ;
	}

	// assign data to the last node
	temp -> data = num ;
	temp -> next = NULL ;
	temp->sublist=NULL;
}
void ll::getdata(int no_courses)
{
	int i,n=0;
	node *t,*x;
	p=new node;
	t=p;x=t;
	for(i=1;i<=no_courses;i++)
	{
		if(i==1){ p->data=i; p->sublist=NULL;}
		else
		append(i);
		}
	for(i=1;i<=no_courses;i++)
	{cout<<"Enter the courses which can be opted before "<<i<<" & add -1 at the end: ";
	cin>>n;
	if(n!=-1)
	{
		while(n!=-1)
		{
	
		x->sublist=new node;
		x->sublist->data=n;
		x->sublist->next=NULL;
		x->sublist->sublist=NULL;
		x=x->sublist;
		cin>>n;
		}
	}
		n=0;
		t=t->next;
		x=t;
	}
}
	
void ll::display()
{
	node *t=p,*x=p;
	while(p!=NULL)
	{
		cout<<p->data<<":- ";
		while(t->sublist!=NULL)
		{
			cout<<t->sublist->data<<" ";
			t=t->sublist;
		}
		cout<<endl;
		p=p->next;
		t=p;
		
	}
	p=x;
}
int a[10],i=0;
void ll::topological_sort(int c)
{
	node* t=p;
	while(t!=NULL)
	{
		if(t->data==c)
		break;
		else
		t=t->next;
	}
	node* q=t;
	if(t->sublist!=NULL)
	{	t=t->sublist;
		while(t!=NULL)
		{topological_sort(t->data);
		t=t->sublist;
		}
	}
	t=q;
	int j;
	for(j=0;j<i;j++)
	{if(t->data==a[j])
		break;
		}
		if(j==i)
		{  cout<<t->data;
	  	a[i]=t->data;
	  	i++;
    	}	
	
}
int main()
{
	int num,course_man;
	cout<<"Enter the  no of courses: ";
	cin>>num;
	ll l;
	l.getdata(num);
	l.display();
	cout<<"Enter the course which is to be completed: ";
	cin>>course_man;
	l.topological_sort(course_man);
}

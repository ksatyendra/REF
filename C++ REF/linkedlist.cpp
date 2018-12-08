#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void add(node* &l,int k)
{//node* l=t;
 if(l==NULL)
 {
     l=(new node);
     l->data=k;
     l->next=NULL;
     //cout<<"First added\n";
 }
 else
 {
     while(l->next!=NULL)
     l=l->next;
     l->next=new (node);
     l->next->data=k;
    // cout<<"Added\n";
     l->next->next=NULL;
 }
}
void print_list(node* l)
{
    cout<<"The list contains:";
    while(l!=NULL)
    {
        cout<<l->data<<" ";
        l=l->next;
    }
}
int search(node* l,int k)
{
    while(l!=NULL)
    {
    if(l->data==k)
    {
        cout<<"Element found";
        return 1;
    }
    else
    l=l->next;
    }
}
int search_recursive(node *l,int k)
{
    if(l==NULL)
    return 0;
    if(l->data==k)
    {   cout<<"Found..";
        return 1;}
    else
    {
    return(search_recursive(l->next,k));

    }
}
void delete_element(node* &l,int k)
{
node* t,*q;
if(l->data==k)
{
    cout<<"deleted";
    t=l;
    l=l->next;
    delete t;
    return;
}
else
{
q=l;

while(q->next!=NULL)
if (q->next->data==k)
{
    t=q->next;
    q->next=t->next;
    delete t;
    cout<<"deleted";break;
}
else
q=q->next;
}
}
void insert(node* l,int p,int k)
{
    node* t;
    for(int i=1;i<p;i++)
    l=l->next;
    t=new node;
    t->data=k;
    t->next=l->next;
    l->next=t;
}
int count(node *l)
{
    int c=0;
    while(l!=NULL)
    {
        c++;
        l=l->next;
    }
    return c;
}
bool check_sublist(node* l1,node* l2)
{
	int flag=0;
	node * temp=l2;
	while(l1->next!=NULL)
	{
	if(l1->data==l2->data)
	{
			flag=1;
			break;
	}
	l1=l1->next;
	}
	while(l2->next!=NULL)
	{
		if(l1->data==l2->data)
		flag=1;
		else
		{
			flag=0;
			return false;
		}
		l1=l1->next;
		l2=l2->next;
		}
		if(flag==1)
		return true;
		else
		{
		check_sublist(l1,temp);
		}
}

void bubble_sort(node *l,int n)
{
    int k, temp ;
	node *p, *q ;

	k = n ;
	for ( int i = 0 ; i < k-1 ; i++ )
	{
		p = l ;
		q = p -> next ;

		for ( int j = 0 ; j < k-i-1 ; j++ )
		{
			if ( p -> data > q -> data )
			{
				temp = p -> data ;
				p -> data = q -> data ;
				q -> data = temp ;
			}
			p= p -> next ;
			q = q -> next ;
		}
	}
}


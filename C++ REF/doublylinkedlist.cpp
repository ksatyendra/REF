#include<iostream>
using namespace std;
struct dnode
{
    int data;
    dnode *right;
    dnode *left;
};
dnode *d;
void add(dnode* &l,int k)
{//node* l=t;
 if(l==NULL)
 {
     l=(new dnode);
     l->data=k;
     l->right=NULL;
     l->left=NULL;
     //cout<<"First added\n";
 }
 else
 {
     while(l->right!=NULL)
     l=l->right;
     l->right=new dnode;
     l->right->data=k;
    // cout<<"Added\n";
     l->right->right=NULL;
     l->right->left=l;
      }
}
dnode* reverse_print(dnode* l)
{
     /*if(l==NULL) return;
     reverse_print(l->right);
     if(l->right!=NULL)
     {
			l->right->left=l->right->right;
			l->right->right=l;
   	}
   	cout<<l->data<<" ";
   	if(l->left==NULL)
   	{
		l->left=l->right;
		l->right=NULL;
	}
	else if(l->right==NULL) d=l;
	/*/if(l->right!=NULL)
	{   
		dnode* temp=(reverse_print(l->right));
		cout<<temp->data<<" ";
		temp->left=temp->right;
		temp->right=l;
		if(l->left==NULL) 
		{
			cout<<l->data<<" ";
			l->right=NULL;
		}
		
		else if(l->right==NULL) d=l;
		return l;
		}
		
	return l;	
		
	/*if(l==NULL)
	return;
	dnode* t=l;
	reverse_print(l->right);
	cout<<l->data<<" ";
	l->right=t;
	t->left=l;
	*/
		
}
void print_reverse(dnode* l)
{
   if(l!=NULL)
    {
    	print_reverse(l->right);
        cout<<l->data<<" ";
    
    }
}
void print_list(dnode* l)
{
    cout<<"The list contains:";
    while(l!=NULL)
    {
        cout<<l->data<<" ";
        l=l->right;
    }
}
int search(dnode* l,int k)
{
    while(l!=NULL)
    {
    if(l->data==k)
    {
        cout<<"Element found";
        return 1;
    }
    else
    l=l->right;
    }
}
int search_recursive(dnode *l,int k)
{
    if(l==NULL)
    return 0;
    if(l->data==k)
    {   cout<<"Found..";
        return 1;}
    else
    {
    return(search_recursive(l->right,k));

    }
}
void delete_element(dnode* &l,int k)
{
dnode* t,*q;
if(l->data==k)
{
    cout<<"deleted";
    t=l;
    l->right->left=NULL;
    l=l->right;
    delete t;
    return;
}
else
{
q=l;

while(q->right!=NULL)
if (q->right->data==k)
{
    t=q->right;
    q->right=t->right;
    t->right->left=q;
    delete t;

    cout<<"deleted";break;
}
else
q=q->right;
}
}
int count(dnode *l);
void insert(dnode* l,int p,int k)
{
    dnode* t;
    if(p==(count(l)+1))
    add(l,k);
    else
    {for(int i=1;i<p-1;i++)
    l=l->right;
    t=new dnode;
    t->data=k;
    t->right=l->right;
    l->right->left=t;
    l->right=t;
    t->left=l;}
}
int count(dnode *l)
{
    int c=0;
    while(l!=NULL)
    {
        c++;
        l=l->right;
    }
    return c;
}
void bubble_sort(dnode *l,int n)
{
    int k, temp ;
	dnode *p, *q ;

	k = n ;
	for ( int i = 0 ; i < k-1 ; i++ )
	{
		p = l ;
		q = p -> right ;

		for ( int j = 0 ; j < k-i-1 ; j++ )
		{
			if ( p -> data > q -> data )
			{
				temp = p -> data ;
				p -> data = q -> data ;
				q -> data = temp ;
			}
			p= p -> right ;
			q = q -> right ;
		}
	}
}


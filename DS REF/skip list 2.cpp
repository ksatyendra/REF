/*This Program takes input from a file...*/
#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
struct node
{
	int data;
	node *right;
	node *down;
};
void add(node* &l,int k)
{
 if(l==NULL)
 {
     l=(new node);
     l->data=k;
     l->right=NULL;
     l->down=NULL;

 }
 else
 {
     while(l->right!=NULL)
     l=l->right;
     l->right=new (node);
     l->right->data=k;
     l->right->right=NULL;
     l->right->down=NULL;
 }
}
int count(node *l)
{
    int c=0;
    while(l!=NULL)
    {
        c++;
        l=l->right;
    }
    return c;
}
void create(node* l,node* &ul)
{	
	static int i=1;
	node *temp=NULL,*cl=NULL;
	while(l!=NULL)
	{	
		if(temp==NULL)
		{
		temp=new node;
		temp->data=l->data;
		temp->right=NULL;
		temp->down=l;
		cl=temp;
		l=l->right->right;
		}
		else
		{
		temp->right=new node;
		temp->right->data=l->data;
		temp->right->right=NULL;
		temp->right->down=l;
		if(l->right!=NULL)
		l=l->right->right;
		else
		break;
		}
	}
	i++;
		if(count(cl)==2)
		{ 	ul=cl;
			return;
		}
	create(cl,ul);

}
void traverse(node* b)//checking the node links are created properly
{	if(b!=NULL)
	{	
	cout<<b->data<<endl;
	traverse(b->right);
	traverse(b->down);
	}
}
bool search(node* b,int k)
{	if(b!=NULL)
	{
	if(b->data==k)
	return true;
	if(b->right!=NULL)
	{if(k>b->data&&k<b->right->data)
	return(search(b->down,k));}
	else
	return(search(b->down,k));
	 if(k>b->right->data||k==b->right->data)
	return(search(b->right,k));
	}
	return false;
}
int main()
{
	int n,count=0,i;
	node *t=NULL,*head=NULL,*uplevel;
	ofstream of("inputnumbers.txt");
	for(i=1;i<=50;i++)
	of<<i<<" ";
	of.close();
	ifstream in("inputnumbers.txt");
	in>>n;
	while(!in.eof())
	{

        if(t==NULL)
        {add(t,n);
        count++;
        head=t;
        }
        else
        {add(t,n);count++;}
        in>>n;
	}
	in.close();
	ofstream outstream("skiplist.txt");	
	create(head,uplevel);
	int k;
	for(int i=0;i<10;i++)
	{
	cout<<"enter the element to be searched : ";
    cin>>k;
	if(search(uplevel,k))
	cout<<k<<" FOUND!!!!!!!!!!!!!!!!\n";
	else
	cout<<k<<" NOT FOUND!!!!!!!!!!!!!!!\n";
	}
	outstream.close();	
	return 0;
}

#include<iostream>
#include<cstdlib>
#include"queuetemplate.cpp"
using namespace std;
struct node
{
	int k1,k2;
	node *left,*mid,*right;
	node();
};
node::node()
{
	k1=k2=-1;
	left=right=mid=NULL;
}
void insert(node* &b,int k)
{
	if(b==NULL)
	{
		b=new node;
		b->k1=k;
	}
	else if(b->k2==-1)
	{
		b->k2=k;
		if(b->k1>b->k2)
		swap(b->k1,b->k2);
	}
	else if(k<b->k1)
	insert(b->left,k);
	else if(k>b->k1&&k<b->k2)
	insert(b->mid,k);
	else if(k>b->k2)
	insert(b->right,k);
}
int findmax(node *b)
{
	if(b->right==NULL)
	{
                    if(b->k2!=-1)
	                  return(b->k2);
	                  else
                   	return(b->k1);
	}
	else
	                  return(findmax(b->right));
}

int findmin(node *b)
{
	if(b->left==NULL)
	return(b->k1);
	else
	return(findmax(b->left));
}
void delete_no(node* &b,int k)
{
	if(b==NULL)
	return;
	else if(k<b->k1)
	delete_no(b->left,k);
	else if(k>b->k1&&k<b->k2)
	delete_no(b->mid,k);
	else if(k>b->k2)
	delete_no(b->right,k);
	if(b->k1==k)
	{
			if(b->k2==-1)
			{
				node* temp=b;
				b=NULL;
				delete temp;
			}
		
			else if(b->mid!=NULL)
			{
			b->k1=findmin(b->mid);
			delete_no(b->mid,b->k1);
			}
			else if(b->right!=NULL)
			{
			b->k1=b->k2;
			b->k2=findmax(b->right);
			delete_no(b->right,b->k2);	
				}
			else if(b->k2!=-1)
			{
				b->k1=b->k2;
				b->k2=-1;
			}
	}
	else if(b->k2==k)
	{	
		if(b->right!=NULL)
		{
		b->k2=findmin(b->right);
		delete_no(b->right,b->k2);
		}
		else if(b->mid!=NULL)
		{
		b->k2=b->k1;
		b->k1=findmax(b->mid);
		delete_no(b->mid,b->k1);
		}
		else if(b->left!=NULL)
		{
		b->k2=b->k1;
		b->k1=findmax(b->left);
		delete_no(b->left,b->k1);
		}
		else
		b->k2=-1;
	}
}
void print(node *b)
{
	if(b!=NULL)
	{
		print(b->left);
		cout<<b->k1<<" ";
		print(b->mid);
		if(b->k2!=-1)
		cout<<b->k2<<" ";
		print(b->right);			
	}
}
void print_level_order(node *root)
{
	if(root==NULL)
	return;
	queue<node*> q(20);
	node *temp;
	q.enqueue(root);
	q.enqueue(NULL);
	
	while(!q.empty())
	{
		temp=q.dequeue();
		if(temp!=NULL)
		{
		cout<<temp->k1<<" ";
		if(temp->k2!=-1)
		cout<<temp->k2<<" ";
		if(temp->left!=NULL) q.enqueue(temp->left);
		if(temp->mid!=NULL) q.enqueue(temp->mid);
		if(temp->right!=NULL) q.enqueue(temp->right);
		}
		else
		 if (!q.empty())
            {	cout<<endl;
				q.enqueue(NULL);
			}            
	}
	cout<<endl;
}
bool search(node* b,int k)
{
	if(b==NULL)
	return false;
	if(k==b->k1||k==b->k2)
	return true;
	else if(k<b->k1)
	return search(b->left,k);
	else if(k>b->k1&&k<b->k2)
	return search(b->mid,k);
	else if(k>b->k2)
	return search(b->right,k);
}
int main()
{
	cout<<"Menu:\n";
    cout<<"1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\n";
	node *m=NULL;
	int num,choice;
	cout<<"Enter the numbers: ";
	cin>>num;
	while(num!=-1)
	{
		insert(m,num);
		cin>>num;
	}
	while(1)
	{	cout<<"Enter choice: ";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter number: ";
			cin>>num;
			insert(m,num);
		}
		if(choice==2)
		//print(m);
		print_level_order(m);
		if(choice==3)
		{
		cout<<"Enter the no to be delete: ";
		cin>>num;
		delete_no(m,num);
		//print(m);
		print_level_order(m);
		}
		if(choice==4)
		{
		cout<<"Enter the no. to be search: ";
		cin>>num;
		if(search(m,num))
		cout<<"Number found!!! :)\n";
		else
		cout<<"Number not found:(\n";
		}
	}
	return 0;		
}

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
	int tag;
	node* down;
	int hvalue;
};
class nodestack
{
	public:
	node* c[500];
	int size;
	int top;
	nodestack()
	{
		top=-1;
		size=500;
	}
	void push(node* ch)
	{
		top++;
		c[top]=ch;
	}
	node* pop()
	{
		return c[top--];	
	}
		
	
   node*	peek()
	{
		return c[top];
	}
	int isempty()
	{
		if(top==-1)
		return 1;
		else
		return 0;
	}
	
};
void post(node* root,int val)
{

	if(root==NULL)
	return;
	post(root->left,val);
	post(root->right,val);

	if(root->data==val)
	root->data+=1000;
	//cout<<root->data<<" ";
	
}

void deletefront(node** head,int n)
{
	int i;
for(i=0;i<n;i++)
{
	if(head==NULL)
return ;
}

for( i=0;i<n;i++)
{
	node*  temp=head[i];
	node* prev=head[i];
	temp=temp->down;
	if(prev->data>999)
	{
	while(temp!=NULL)
	{
		prev->data=temp->data;
		if(temp->down!=NULL)
		prev=prev->down;
		temp=temp->down;
	}
	prev->down=NULL;
	}
}
	
}


int vun(node* root)
{
	if(root->left==NULL && root->right==NULL)
	return root->data;
	else
	{
		int t1=vun(root->left);
		int t2=vun(root->right);
		if(t1>t2)
		root->data=t2;
		else
		root->data=t1;
		return root->data;
	}
}
void showlist(node* head[],int index)
{
	node* temp=head[index];
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->down;
	}
}
int main()
{
	node** head;
	nodestack s1,s2;
	int oper,sum=0;
	int n,num,i,j,f=0;
	cout<<"how many list you want to enter\n";
	cin>>n;
	int k=n;
	head=new node*[n];
	for(i=0;i<n;i++)
	head[i]=NULL;

	for(i=0;i<n;i++)
	{
		cout<<"enter the numbers in list "<<i+1;
		cin>>num;
		for(j=0;j<num;j++)
		{sum++;
			cout<<"enter value\n";
			cin>>oper;
			node* temp=new node;
			temp->tag=1;temp->left=NULL;temp->right=NULL;temp->data=oper;
			temp->hvalue=i;
			node* temp4=head[i];
			if(head[i]==NULL)
			{
				temp->down=head[i];
				head[i]=temp;
			}
			else
		
		{
			
					while(temp4->down!=NULL)
				{
				temp4=temp4->down;
				}
			    temp4->down=temp;
			     temp->down=NULL;
			
		}
		
	}
		s1.push(head[i]);
	}
//cout<<"sum="<<sum<<endl;
	while(n>pow(2,f))
	{
		f++;
	}
	
/*	for(i=0;i<n;i++)
	{
		cout<<endl;
		showlist(head,i);
		cout<<endl;
	}
	*/
//	cout<<"f="<<f<<endl;

	for(int j=0;j<f;j++)
	{
		 
	   while(!s1.isempty())
	   {
	   		if(s1.top==0)
		{
		s2.push(s1.pop());
		}
		else
		{
		
		node* temp1=s1.pop();
		 node* temp2=s1.pop();
		node* temp=new node;
	
		if(temp1->data>temp2->data)
		temp->data=temp2->data;
		else
		temp->data=temp1->data;
		temp->tag=0;
		temp->hvalue=100;
		
		temp->left=temp1;
		temp->right=temp2;
		s2.push(temp);
	  }
	}
	while(!s2.isempty())
	{
		s1.push(s2.pop());
	}
}

node* root=s1.pop();
cout<<root->data<<" ";
for(i=0;i<sum-1;i++)
{

post(root,root->data);

deletefront(head,n);
vun(root);
cout<<root->data<<" ";
}

	


}

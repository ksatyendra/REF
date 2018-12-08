#include<iostream>
#include<cstdlib>
#include<cstring>
#include"queuetemplate.cpp"
using namespace std;
struct btnode
{
	btnode *lchild;
	char data;
	btnode *rchild;
};
btnode *reconstruct(char *in,char *pre,int no_nodes)
{
	char temppre[100],tempin[100];
	int i,j;
	btnode *temp,*left,*right;
	if(no_nodes==0)
	return NULL;
	temp = new btnode ;
	temp -> data = pre[0] ;
	temp -> lchild = NULL ;
	temp -> rchild = NULL ;
	if(no_nodes==1)
	return temp;
	for (i=0;in[i]!= pre[0];i++);
	if ( i > 0 )
	{
		for ( j = 0 ; j < i  ; j++ )
			tempin[j] = in[j] ;

		for ( j = 0 ; j < i  ; j++ )
			temppre[j] = pre[j + 1] ;
	}
	left=reconstruct(tempin,temppre,no_nodes-i-1);
	temp->lchild=left;
	if ( i < no_nodes - 1 )
	{
		for ( j = i ; j < no_nodes - 1 ; j++ )
		{
			tempin[j - i] = in[j + 1] ;
			temppre[j - i] = pre[j + 1] ;
		}
	}

	right = reconstruct ( tempin, temppre, no_nodes - i - 1 ) ;
	temp -> rchild = right;

	return temp ;
}
void print_level_order(btnode *root)
{	if(root==NULL)
	return;
	queue<btnode*> q(20);
	btnode *temp;
	q.enqueue(root);
	q.enqueue(NULL);
	
	while(!q.empty())
	{
		temp=q.dequeue();
		if(temp!=NULL)
		{
		cout<<temp->data<<" ";
		if(temp->lchild!=NULL) q.enqueue(temp->lchild);
		if(temp->rchild!=NULL) q.enqueue(temp->rchild);
		}
		else
		 if (!q.empty())
            {	cout<<endl;
				q.enqueue(NULL);
			}
             
              
	}
}
void printinorder(btnode *b)
{
	if(b!=NULL)
	{
	printinorder(b->lchild);
	cout<<b->data<<" ";
	printinorder(b->rchild);
	}
}
void preorder(btnode *b)
{
	if(b!=NULL)
	{
	
	cout<<b->data<<" ";
	preorder(b->lchild);
	preorder(b->rchild);
	}
}
int main()
{
	char inorder[100],preorder[100];
	cout<<"Enter inorder : \n";
	cin>>inorder;
	cout<<"Enter preorder: \n";
	cin>>preorder;
	int nodes_no=strlen(inorder);
	btnode *b;
	b=reconstruct(inorder,preorder,nodes_no);
	print_level_order(b);
	//printinorder(b);
	return 0;
	
}

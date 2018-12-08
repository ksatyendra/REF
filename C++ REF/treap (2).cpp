#include<iostream>
using namespace std;
#include"queuetemplate.cpp"
#include<cstdlib>
struct thnode
{
        int priority;
        char key;
        thnode *lchild,*rchild,*parent;
        thnode(char y,int x)
        {
        priority =x;
        key= y;
        lchild=rchild=parent=NULL;
        }
        thnode()
        {lchild=rchild=parent=NULL;}
};
void rotate_right(thnode* &k1)
{
thnode* k2=k1->lchild;
k1->lchild=k2->rchild;
k2->rchild=k1;
k1=k2;
}
void rotate_left(thnode* &k1)
{
thnode* k2=k1->rchild;
k1->rchild=k2->lchild;
k2->lchild=k1;
k1=k2;
}
void insert(thnode *&b,char k,int prior)
{
if(b==NULL)
b=new thnode(k,prior);
else if(k<b->key)
{
	insert(b->lchild,k,prior);
	if(b->lchild->priority<b->priority)
	rotate_right(b);
}
else if(k>b->key)
{
	insert(b->rchild,k,prior);
	if(b->rchild->priority<b->priority)
	rotate_left(b);
}
}
void print_level_order(thnode *root)

{	if(root==NULL)

	return;

	queue<thnode*> q(20);

	thnode *temp,*l,*r;

	q.enqueue(root);

	q.enqueue(NULL);

	while(!q.empty())

	{

		temp=q.dequeue();

		if(temp!=NULL)

		{

		cout<<temp->key<<" "<<temp->priority;
		if(temp->lchild!=NULL) q.enqueue(temp->lchild);

		if(temp->rchild!=NULL) q.enqueue(temp->rchild);

		}

		else

		 if (!q.empty())
		{
            		cout<<endl;
            		q.enqueue(NULL);
		}
	}
}

int main()
{
	thnode *b=NULL;
	cout<<"Menu:\n1.Insert\n2.Delete\n3.Print\n4.Exit\n";
	int choice,i,num;
	char c;
	while(1)
	{
		cout<<"Enter Choice: ";
		cin>>choice;
		if(choice==1)
		{
		cout<<"Enter character and number: ";
		cin>>c>>num;
		insert(b,c,num);
		}
		if(choice==3)
		print_level_order(b);
		if(choice==4)
		exit(1);
	}
	return 0;
}


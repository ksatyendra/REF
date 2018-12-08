#include<iostream>
#include<stdlib.h>

using namespace std;
int max(int ar[], int n);
struct gtnode
{
    int data;
    int cc;
    gtnode **nextChild;
};
typedef gtnode* gtptr;
struct lnode
{
    gtptr data;
    lnode *next;
};
typedef lnode * lptr;
lptr newNode(gtptr k)
{
	lptr t = new lnode;
	t->data = k;
	t->next = NULL;
	return t;
}
void push_back(lptr &L,gtptr T)
{
	if( L == NULL)
	{
		L = newNode(T);
	}
	else
	{
		lptr temp = L;
		while(temp->next)
			temp = temp->next;
		temp->next = newNode(T);
	}
}
void display(lptr L)
{
    cout<<"\n-------Printing List-------\n\n";
	while(L!= NULL)
	{
	    cout<<"  "<<L->data->data;
		L = L->next;
	}
	cout<<"\n";
}
gtptr new_gtnode()
{
    int k;
    gtnode *temp;
    temp = new gtnode;
    cout<<"\nEnter Node Data  : "; cin>>k;
    temp->data = k;
    cout<<"\nEnter no. of Child of Parent ( 0 for null) : "<<k<<" : "; cin>>temp->cc;
    temp->nextChild = new gtnode* [temp->cc];
    for(int i=0; i<temp->cc; i++)
        temp->nextChild[i] = NULL;
    return temp;
}
gtptr createTree(gtptr root)
{
	if(root == '\0')
	{
		root = new_gtnode();
	}
    for(int i=0; i< root->cc; i++)
    {
        cout<<"\nEnter "<<i+1<<" child details of parent "<<root->data<<" : ";
        root->nextChild[i] = createTree(root->nextChild[i]);
    }
    return root;
}

void printTree(gtptr T,int ht, lptr l)
{
	if(!T)
		return;
    if( ht == 1)
    {
		push_back(l,T);
    }
    else
    for(int i=0; i< T->cc; i++)
    {
        printTree(T->nextChild[i],ht-1,l);
    }
}

int height(gtptr root)
{
    if(!root)
        return -1;
    else
    {
        int i,ar[10];
        for(i = 0; i < root->cc; i++)
        {
            ar[i] = height(root->nextChild[i]);
        }
        int m = max(ar, root->cc);
        return (1+m);
    }
}

int main()
{
    gtptr root='\0'; int i=0; lptr l[10];
    root = createTree(root);
    int ht = height(root);
    cout<<"\nheight : "<<ht<<"\n";
    for(i=1; i<=ht; i++)
		printTree(root, i, l[i-1]);
	cout<<"\nEnter Level to display : " ; cin>>i;
	display(l[i]);
    return 0;
}

int max(int ar[], int n)
{
    int i,m = 0;
    for(i=0; i< n; i++)
        if(ar[i] > m)
        m = ar[i];
    return m;
}


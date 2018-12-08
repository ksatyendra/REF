#include<iostream>
using namespace std;
struct node
{
 int data;
 node *next;
};
node *newNode(int data)
{
    node *new_node;
    new_node = new node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(node** head, int k)
{
    node* new_node = newNode(k);
    new_node->next = (*head);
    (*head)    = new_node;
}
void display(node *L)
{
	cout<<"\nList is :\n\t";
	while(L!= NULL)
    {
        cout<<L->data<<"  ";
    	L = L->next;
    }
}
void input(node *L)
{
	node *t;
	int k;
	char ch='y';
	while(ch=='y')
	{
		cout<<"Enter no. : ";  cin>>k;
	    t = new node;
	    t->next = NULL;
		t->data = k;
		L->next = t;
		L = L->next;
		cout<<"\nWanna Continue press y.... ";
		cin>>ch;
    }
}
void setHead(node **L)
{
    node *t;
    t = *L;
    t = t->next;
    *L = t;
}
void searchItem(node *L,int k)
{
    int flag = 0;
    while(L != NULL )
    {
        if(L->data == k)
        {
            cout<<"\nFound....!!\n";
            flag = 1;
        }
        L = L->next;
    }
    if(flag==0)
        cout<<"\nNot Found...!!\n";
}
void removeItem(node *L,int k)
{
    while(L->next->data != k )
    {
        L = L->next;
    }
	L->next=L->next->next;
}

int main()
{
	int n;
	node *L1 = new node; char ch='y';
	cout<<"Enter 1st List \n";
	input(L1);
	setHead(&L1);
	display(L1);
	while(ch=='y')
    {
        cout<<"\nSearch Item : ";  cin>>n;
        searchItem(L1,n);
        removeItem(L1,n);
        push(&L1,n);
        display(L1);
        cout<<"\nWanna Continue...press y...";
        cin>>ch;
    }
	return 0;
}

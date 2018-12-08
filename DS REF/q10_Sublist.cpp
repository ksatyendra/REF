#include<iostream>
using namespace std;
struct node
{
 int data;
 node *next;
};

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
int searchItem(node *L,int k)
{
    while(L->next != NULL )
    {
        if(L->data == k)
            return 1;
        L = L->next;
    }
    return 0;
}

int subList(node *L1,node *L2)
{
    node *temp1 = L1,*temp2 = L2; int flag;
    for( ; temp2->next!=NULL ; temp2 = temp2->next)
    {
        flag = 0;
        if(searchItem(L1,temp2->data))
            flag = 1;
    }
    return flag;
}
int main()
{
	int ch=0;
	node *L1 = new node; node *L2 = new node;
	cout<<"Enter 1st List \n";
	input(L1);
	setHead(&L1);
	display(L1);
	cout<<"\nEnter 2st List \n";
	input(L2);
	setHead(&L2);
	display(L2);
	if(subList(L1,L2))
        cout<<"\nList 2 is Subset of List 1 \n\n";
    else
        cout<<"\nList 2 is NOT a Subset of List 1 \n\n";

	return 0;
}

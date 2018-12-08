
#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int bin;
    int data;
    node *next;
};
node *head;
void input(node *L)
{
    int b,d; char ch='y'; node *t;
    while(ch=='y')
    {
        cout<<"\nEnter Bin no. : "; cin>>b;
        cout<<"Enter Data : ";  cin>>d;
        if(L==NULL)
        {
            L = new node;
            L->bin = b;
            L->data = d;
            L->next = NULL;
            head = L;
            cout<<"\nn\n";
        }
        else
        {
            t = new node;
            t->bin  = b;
            t->data = d;
            t->next = NULL;
            L->next = t;
            L = L->next;
        }
        cout<<"\nWanna Continue....press y...."; cin>>ch;
    }
}
void display(node *L)
{
    L = head;
    cout<<"\n----------List is---------\n\n";
    while(L!=NULL)
    {
        cout<<"("<<L->bin<<","<<L->data<<")"<< "  ";
        L = L->next;
    }
    cout<<"\n\n";
}
int sizeL(node *L)
{
    L = head; int size = 0;
    while(L!=NULL)
    {
        size++;
        L = L->next;
    }
    return size;
}
void swap(int &a,int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
void sort(node *L)
{
    int size;
    size = sizeL(L);
    cout<<size;
    size-=1;
    L = head;
	int i,j,p,temp;
	for(i=0;i<size;i++)
    {
	   node *t2 = L;
	   for(j=0; j<size; j++,t2 = t2->next)
       {
	     if(t2->bin > t2->next->bin)
	     {
	        swap(t2->data,t2->next->data);
	        swap(t2->bin,t2->next->bin);
	     }
	     else if(t2->bin == t2->next->bin)
         {
            if(t2->data > t2->next->data)
            {
                swap(t2->data,t2->next->data);
                swap(t2->bin,t2->next->bin);
            }
         }
	   }
	}
}
int main()
{
    node *L=NULL;
    input(L);
    display(L);
    sort(L);
    display(L);
    return 0;
}

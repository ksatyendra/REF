#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<ctype.h>
#define MAX 50
using namespace std;
struct dnode
{
    dnode *left;
    int data;
    dnode *right;
};
struct queue
{
    float element[MAX];
    int front;
    int rear;
    int size;
    queue(){ front = -1; rear = -1; }
    void create();
    void enqueue(float);
    float dequeue();
    int isFull();
    int isEmpty();
    void display();
};
class Stack
{
	char* data[MAX];
	int top;
	int size;
   public:
    Stack(){ top = -1; }
    void push(char*);
	char* pop();
	int isEmpty();
	int isFull();
	void display();
};

union u
{
    dnode *dnext;
    Stack *st;
    queue *qu;
};
struct node
{
    int data;
    u *lnext;
    node *next;
};
node *head; dnode *root;
//function declaration
void addAfter(dnode *L,int X,int k);
void create(dnode *L);
void addFront(dnode **L,int k);
void display(dnode *L);
//Stack Operation
void Stack::display()
{
    int t = top;
    cout<<"\nStacks Elements Are....\n";
    while(t!=0)
    {
        cout<<"\n"<<data[t--];
    }
    cout<<"\n";
}
void Stack::push(char* k)
{
	if(isFull())
	{
		cout<<"\nStack Overflow..!!";
	}
	else
        strcpy(data[++top],k);
}
char* Stack::pop()
{
	if(isEmpty())
	{
		cout<<"\nStack is Empty..!!";
	}
	else
		return data[top--];
}
int Stack::isEmpty()
{
	if(top==-1)
	    return 1;
	else
		return 0;
}
int Stack::isFull()
{
	if(MAX == top+1)
		return 1;
	else
		return 0;
}
void queue::create()
{
    float k; char ch;
    cout<<"Enter Size of Queue : "; cin>>size;
    do
    {
        cout<<"\nEnter element : ";  cin>>k;
        if(front == -1)
        {
            element[++front] = k;
            ++rear;
        }
        else
            element[++rear] = k;
        cout<<"\nWanna Continue...press y...";
        cin>>ch;
    }while(size!=rear && ch=='y');
}
int queue::isFull()
{
    if((rear+1)%size == front)
        return 1;
    return 0;
}
int queue::isEmpty()
{
    if(rear == -1 && front == -1)
        return 1;
    return 0;
}
void queue::enqueue(float k)
{
    if(isFull())
        cout<<"\nQueue is Full..!!";
    else
    {
        if(front == -1)
        {
            element[++front] = k;
            element[++rear] = k;
        }
        else
        {
            rear = (rear+1)%size;
            element[rear] = k;
        }
    }
}
float queue::dequeue()
{
    float t;
    if(isEmpty())
    {
        cout<<"\nQueue is Empty..!!";
        return -1;
    }
    else
    {
        if(front == rear)
        {
            t = element[front];
            front = -1; rear = -1;
        }
        else
        {
            t = element[front];
            front = (front+1)%size;
        }
    }
    return t;
}
void queue::display()
{
    cout<<"\nElements of Queue Are.....\n\n\t";
    for(int i = front; i<=rear ; (i==size)?i=0:i++ )
        cout<<" "<<element[i];
    cout<<"\n";
}
void display(dnode *L)
{
    L = head;
    cout<<"\n-------Printing List-------\n\n";
	while(L!= NULL)
	{
	    cout<<"  "<<L->data;
		L = L->right;
	}
}
void addFront(dnode *L,int k)
{
    L = head;
    dnode *T;
    T = new dnode;
    T->data = k;
    T->right = L;
    L->left = T;
    T->left = NULL;
    head = T;
}
void create(dnode *L)
{
    dnode *t;  char ch='y'; int k;
    while(ch=='y')
    {
        cout<<"\nEnter data : "; cin>>k;
        if(L == NULL)
        {
            L = new dnode;
            L->data = k;
            L->right = NULL;
            L->left = NULL;
            head = L;
        }
        else
        {
            t = new dnode;
            t->data = k;
            t->right = NULL;
            t->left = L;
            L->right = t;
            L = L->right;
        }
        cout<<"Wanna Continue...press y...."; cin>>ch;
    }
}
void addAfter(dnode *L,int X,int k)
{
    dnode *T;  L = head;
    while(L->data != X)
        L = L->right;
    T = new dnode;
    T->data = k;
    T->right = L->right;
    L->right->left = T;
    T->left = L;
    L->right = T;
}
int strtype(char str[])
{
    int i;
    for( i=0; str[i]!='\0'; i++)
    {
        if(isalpha(str[i]))
            return 2;
        else
        {
            if(str[i]=='.')
                return 3;
        }
    }
    return 1;
}
int main()
{
    char str[25];  char ch='y'; node *L; dnode *DL; Stack S; queue Q;
    while(ch=='y')
    {
        cout<<"Enter any Number or String : "; cin>>str;
        switch(strtype(str))
        {
            case 1:
                if(L==NULL)
                {
                }
                L = new node;
                L->data = 1;
                DL = new node;
                L->lnext->dnext = DL;
                DL->data = atoi(str);
                DL->left = L->lnext->dnext;
                DL->right =  NULL;
                break;
            case 2:

                break;
            case 3:

                break;
            default:
                cout<<"\nInvalid choice...";
                break;
        }
        cout<<"\nWanna Continue,.....press y...";  cin>>ch;
    }
    return 0;
}

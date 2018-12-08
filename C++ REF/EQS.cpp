#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX 50
using namespace std;
class Stack
{
	int element[MAX];
	int top;
	int size;
   public:
    Stack(){ top = -1; }
    void push(int);
	int pop();
	int isEmpty();
	int isFull();
	void display();
};
void Stack::display()
{
    int t = top;
    cout<<"\nStacks Elements Are....\n";
    while(t!=0)
    {
        cout<<" "<<element[t--];
    }
    cout<<"\n";
}
void Stack::push(int k)
{
	if(isFull())
	{
		cout<<"\nStack Overflow..!!";
	}
	else
        element[++top] = k;
}
int Stack::pop()
{
	if(isEmpty())
	{
		cout<<"\nStack is Empty..!!";
	}
	else
		return element[top--];
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
struct queue
{
    char* element[MAX];
    int front;
    int rear;
    int size;
    queue(){ front = -1; rear = -1; }
    void create();
    void enqueue(char* k);
    char* dequeue();
    int isFull();
    int isEmpty();
    void display();
};
void queue::create()
{
    char* k; char ch;
    cout<<"Enter Size of Queue : "; cin>>size;
    do
    {
        cout<<"\nEnter postfix expression : ";  cin>>k;
        if(front == -1)
        {
            strcpy(element[++front],k);
            ++rear;
        }
        else
        {
            exit(1);
            strcpy(element[++front],k);
        }
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
void queue::enqueue(char* k)
{
    if(isFull())
        cout<<"\nQueue is Full..!!";
    else
    {
        if(front == -1)
        {
            strcpy(element[++front],k);
            ++rear;
        }
        else
        {
            rear = (rear+1)%size;
            strcpy(element[rear],k);
        }
    }
}
char* queue::dequeue()
{
    char* t;
    if(isEmpty())
    {
        cout<<"\nQueue is Empty..!!";
    }
    else
    {
        if(front == rear)
        {
            strcpy(t, element[front]);
            front = -1; rear = -1;
        }
        else
        {
            strcpy(t, element[front]);
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
int main()
{
    Stack elem,res; queue Q;
    Q.create();
    Q.display();
    return 0;

}

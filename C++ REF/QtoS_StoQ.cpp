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
    int element[MAX];
    int front;
    int rear;
    int size;
    queue(){ front = -1; rear = -1; }
    void create();
    void enqueue(int k);
    int dequeue();
    int isFull();
    int isEmpty();
    void display();
};
void queue::create()
{
    int k; char ch;
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
void queue::enqueue(int k)
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
int queue::dequeue()
{
    int t;
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
int main()
{
    int ch; Stack s; queue Q; int choice,k;
    cout<<"\n1. Fill Stack with Queue";
    cout<<"\n2. Fill queue with Stack";
    cout<<"\nSelect Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            do
            {
                cout<<"\n 1. Create Queue.";
                cout<<"\n 2. Enqueue";
                cout<<"\n 3. Filling Stack and Dequeue Queue";
                cout<<"\n 4. Display";
                cout<<"\n 5. Exit";
                cout<<"\nSelect choice : "; cin>>choice;
                switch(choice)
                {
                case 1:
                    Q.create();
                    Q.display();
                    break;
                case 2:
                    cout<<"\nEnter Element : ";  cin>>k;
                    Q.enqueue(k);
                    Q.display();
                    break;
                case 3:
                    k = Q.dequeue();
                    cout<<"\nDequeue Element is : "<<k<<"\n";
                    s.push(k);
                    break;
                case 4:
                    Q.display();
                    s.display();
                    break;
                case 5:
                    cout<<"\nQuitting.....";
                    exit(1);
                default:
                    cout<<"\nInvalid Choice..!!";
                    break;
                }
            }while(choice!=5);
            break;
        case 2:
            do
            {
                cout<<"\n 1. Push";
                cout<<"\n 2. Pop Stack and Filing Queue";
                cout<<"\n 3. Display";
                cout<<"\n 4. Exit";
                cout<<"\nSelect choice : "; cin>>choice;
                switch(choice)
                {
                case 1:
                    cout<<"\nEnter Element : ";  cin>>k;
                    s.push(k);
                    break;
                case 2:
                    k = s.pop();
                    cout<<"\npoped Element is : "<<k<<"\n";
                    Q.enqueue(k);
                    break;
                case 3:
                    Q.display();
                    cout<<"\n";
                    s.display();
                    break;
                case 4:
                    cout<<"\nQuitting.....";
                    exit(1);
                default:
                    cout<<"\nInvalid Choice..!!";
                    break;
                }
            }while(choice!=4);
            break;
        case 3:
            cout<<"\nQuitting......";
            exit(2);
        default:
            cout<<"\nInvalid Choice...";

        }
	return 0;
}

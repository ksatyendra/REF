#include<iostream>
#include<stdlib.h>
#define MAX 50
using namespace std;

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
    cout<<"\nMembers of Queue Are.....\n\n\t";
    for(int i = front; i<=rear ; (i==size)?i=0:i++ )
        cout<<" "<<element[i];
    cout<<"\n";
}
int main()
{
    queue Q; int choice,k;
    do
    {
        cout<<"\n 1. Create Queue.";
        cout<<"\n 2. Enqueue";
        cout<<"\n 3. Dequeue";
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
                break;
            case 4:
                Q.display();
                break;
            case 5:
                cout<<"\nQuitting.....";
                exit(1);
            default:
                cout<<"\nInvalid Choice..!!";
                break;
        }
    }while(choice!=5);
    return 0;
}

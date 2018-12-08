#include<iostream>
#include<stdlib.h>
#define MAX 50
using namespace std;
int count = 0;
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
        count++;
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
            element[front] = NULL;
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
    queue Q,temp; int i,j,a,b;
    cout<<"\nCreate Queue....\n";
    Q.create();
    Q.display();
    cout<<"\nNo. of Elements in Queue : "<<count<<"\n\n";
    for(i=0; i<count; i++)
    {
        a = Q.dequeue();
        for(j = 0; j<count-1; j++)
        {
            b = Q.dequeue();
            if(a < b)
                Q.enqueue(b);
            else
            {
                Q.enqueue(a);
                a = b;
            }
        }
        Q.enqueue(a);
    }
    cout<<"\nAfter Sorting....Queue is....\n";
    Q.display();
    cout<<"\n\n";
    return 0;
}

#include<iostream>
#include<stdlib.h>
#define MAX 25
using namespace std;

class stack
{
    int top;
    int elem[MAX];
    public:
        stack(){ top = -1; }
        void Push(int k);
        int pop();
        int topelem();
        int isFull();
        int isEmpty();
        void display();
};
void stack::display()
{
    int t = top;
    cout<<"\nStack elements Are....\n";
    while(t>=0)
        cout<<"  "<<elem[t--];
}
void stack::Push(int k)
{
    if(isFull())
        cout<<"\nStack Overflow..!!";
    else
        elem[++top] = k;
}
int stack::pop()
{
    if(isEmpty())
        cout<<"\nStack is Empty..!!";
    else
        return elem[top--];
}
int stack::topelem()
{
    if(isEmpty())
        cout<<"\nStack is Empty..!!";
    else
        return elem[top];
}
int stack::isFull()
{
    if(MAX==top+1)
        return 1;
    return 0;
}
int stack::isEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}

int main()
{
    int i,j,size; stack s1,s2; int k; char ch = 'y';
    cout<<"\nCreate Stack....\n";
    while(ch=='y')
    {
        cout<<"\nEnter Data : "; cin>>k;
        s1.Push(k);
        cout<<"Wanna Continue....press y....";
        cin>>ch;
    }
    s1.display();
    while(!s1.isEmpty())
    {
        int tmp = s1.pop();
        while(!s2.isEmpty() && s2.topelem() > tmp)
        {
            s1.Push(s2.pop());
        }
        s2.Push(tmp);
    }
    cout<<"\nAfter Sorting Stack is.....\n";
    s2.display();
    return 0;
}

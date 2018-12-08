#include<iostream>
using namespace std;
class stack
{   public:
            stack();
             int top;
             int size;
             int *elements;
             void push(int);
             int pop();
             stack(int);
};
void stack::push(int x)
{
     if(top==size-1)
     cout<<"Queue Full...";
     else
     elements[++top]=x;
}
int stack::pop()
{
    if(top==-1)
               {
                cout<<"Queue Empty..";
                return(-1);
                }
                else
                return(elements[top--]);
}
stack::stack()
{           top=-1;
            cout<<"Enter the size: ";
            cin>>size;
            elements=new int[size];
}
stack::stack(int x)
{
                 top=-1;
                 size=x;
                 elements=new int[size];
}
class queue
{          
           public:
          // int rear,front;
           stack a,b;
           void enqueue(int);
           int dequeue();
};
void queue::enqueue(int x)
{
     
     while(b.top!=-1)
     {a.push(b.pop());}
     a.push(x);
     cout<<x<<" element added to queue..\n";
     if(a.top>0)
     while(a.top!=-1)
     {b.push(a.pop());}
}
int queue::dequeue()
{
    if(a.top==0)
    cout<<a.pop()<<" element deleted..\n";
    else
                   cout<< b.pop()<<" element deleted from queue..\n";

}
     int main()
      {
          queue q;
          int i,j;
          char ch;
          while(1)
          {
          if(q.b.top!=q.b.size-1)
          {                      cout<<"Enter the element: ";
                                 cin>>i;
                                 q.enqueue(i);
          }
          else
          cout<<"Queue is full...\n";
          cout<<"Do you want to dequeue? Press y or n: ";
          cin>>ch;
          if(ch=='y')
          {
          j=q.dequeue();
          }
          cout<<"Do you want Stop? Press y or n: ";
          cin>>ch;
          if(ch=='y')
          break;
          else
          continue;
          }
          system("pause");
          return(0);
      }

#include<iostream>
using namespace std;
class stack
{   public:
            //stack();
             int top;
             int size;
             int *elements;
             void push(int);
             int pop();
             //stack(int);
             void initialize();
};
void stack::push(int x)
{
     if(top==size-1)
     cout<<"Stack Full...";
     else
     elements[++top]=x;
}
int stack::pop()
{
    if(top==-1)
               {
                cout<<"Stack Empty..";
                return(-1);
                }
                else
                return(elements[top--]);
}
/*stack::stack()
{           top=-1;
            cout<<"Enter the size of stack: ";
            cin>>size;
            elements=new int[size];
}
stack::stack(int x)
{
                 top=-1;
                 size=x;
                 elements=new int[size];
}*/
void stack::initialize()
{    top=-1;
    cout<<"Enter the size of stack: ";
            cin>>size;
            elements=new int[size];
} 
class queue
{          
           public:
           int rear,front;
           int n;
           stack *array;
           queue();
           void enqueue(stack);
           stack dequeue();
           
};
queue::queue()
{
              cout<<"Enter the maxm number of stacks in the queue: ";
              cin>>n;
              array=new stack[n];
}
void queue::enqueue(stack x)
{
     if(front==(rear+1)%n)
           cout<<"Queue Full..\n";
           else
           {
               if(front==-1)
               front=0;
               rear=(rear+1)%n;
               array[rear]=x;
           }
}
stack queue::dequeue()
      {
          stack t;
          if(front==-1)
          cout<<"Queue is empty..\n";
          else
          {
              if(front==rear)
              {
                             t=array[front];
                             front=-1;rear=-1;
              }
              else
              {              t=array[front];
                             front=(front+1)%n;
                              
              }return (t);
          }
          
         return (t);
      }
void display(stack x)
{
     cout<<"The elements in the stack are: \n";
     while(x.top!=-1)
     cout<<x.pop()<<" ";
}
 int main()
 {
           queue q;
           int i,j;
          char ch;
          while(1)
                  {
                  cout<<"Do you want to enqueue a stack in queue.press y or n: ";
                  cin>>ch;
                  if (ch=='y')
                  {       stack temp;
                  
                  temp.initialize();
                  cout<<"Enter the elements in stacks: ";
                  for(j=0;j<temp.size;j++)
                                          { 
                                            cin>>i;
                  
                                          temp.push(i);
                                          }
                                          q.enqueue(temp);
                  }
                  
          cout<<"Do you want to dequeue? Press y or n: ";
          cin>>ch;
          if(ch=='y')
          {
          stack s=q.dequeue();
          cout<<s.pop()<<" ";
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

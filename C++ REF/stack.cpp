#include<iostream>
using namespace std;
//const int size=10;
class stack
{
      public:
            stack();
             int top;
             int size;
             int *elements;
             void push(int);
             int pop();
             //stack(int);
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
stack::stack()
{           top=-1;
            cout<<"Enter the size of stack: ";
            cin>>size;
            elements=new int[size];
}
/*stack::stack(int x)
{size=x;}*/
int main()
{
    stack s;
    int i=0;
    char c;
    while(i<s.size)
    {
                   cout<<"Enter the element token number:\n ";
                   cin>>i;
                   s.push(i);
                   cout<<"Do you want to take out token number..Press y or n: ";
                   cin>>c;
                   if(c=='y')
                   cout<<s.pop();
                   cout<<"Exit the Program..press y or n: ";
                   cin>>c;
                   if(c=='y')
                   exit(-1);    
    }
    system("pause");
    return(0);
}
                   
                      

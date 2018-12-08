#include<iostream>
#include<string>
using namespace std;
const int size=20;
class stack
{
      public:
            stack();
             int top;
             char array[size];
             int a[size];
             void push(int);
             void push(char);
             char popchar();
             int popint();
             //stack(int);
};
int priority(char);
void stack::push(int x)
{
     if(top==size-1)
     cout<<"Stack Full...";
     else
     a[++top]=x;
}
void stack::push(char x)
{
     if(top==size-1)
     cout<<"Stack Full...";
     else
     array[++top]=x;
}
char stack::popchar()
{
    if(top==-1)
               {
                cout<<"Stack Empty..";
                }
                else
                return(array[top--]);
}
int stack::popint()
{
    if(top==-1)
               {
                cout<<"Stack Empty..";
                
                }
                else
                return(a[top--]);
}
stack::stack()
{           top=-1;
}
int priority(char x)
{
                  if(x=='/'||x=='*')
                  return 4;
                 // if(x=='*')
                 //  return (3);
                  if(x=='+'||x=='-')
                  return (2);
                  //if(x=='-')
                  //return 1;
}

#include<iostream>
using namespace std;
const int size=20;
class stack
{
      public:
             char c[size];
             int top;
             void push(char x);
             char pop();
             stack();
             char value()
             {return(c[top]);}
};
void stack::push(char x)
 { if(top==size-1)
     cout<<"Stack Full...Enter small expresion";
     else
     c[++top]=x;
}
char stack::pop()
{
    if(top==-1)
               {
                cout<<"Stack Empty..";
                return(-1);
                }
                else
                return(c[top--]);
}
stack::stack()
{           top=-1;
}
int main()
{
    string exp;
    int i,j;
    cout<<" \nInput the balanced expression: \n";
    cin>>exp;
    stack s;
    for(j=0;j<exp.length();j++)
    {
                              
                            
                              if(exp[j]=='['||exp[j]=='{'||exp[j]=='(') 
                              
                              s.push(exp[j]);
                            
                         
                               if(exp[j]==']')
                                {  if(s.value()=='[') s.pop();}
                               else if(exp[j]=='}')
                                  { if(s.value()=='{') s.pop();}
                                 else if(exp[j]==')')
                                  {if(s.value()=='(') s.pop();}
                                    
    }
    
system("pause");
return(0); 
}

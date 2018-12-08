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
                  if(x=='/')
                  return 4;
                  if(x=='*')
                  return (3);
                  if(x=='-')
                  return (2);
                  if(x=='+')
                  return 1;
}

int evaluate(string c)
{
    int sum,t1=0,t2,t3,i;
    char ch;
    stack a,b;
   for(i=0;i<c.length();i++)
    {
            while(c[i]>=48&&c[i]<=57)
            {
            t1=10*t1+(int)c[i]-48;
               i++;
            }

            a.push(t1);
            t1=0;

            if(c[i]=='*'||c[i]=='/'||c[i]=='+'||c[i]=='-')
            {

                if(b.top==-1)
                b.push(c[i]);
                else
                if(priority(c[i])>=priority(b.array[b.top]))
                {
                b.push(c[i]);
                }
                else
                {   while(b.top!=-1)
                    {
                    if(priority(c[i])<=priority(b.array[b.top]))
                    {


                    ch=b.popchar();
                    t2=a.popint();
                    cout<<t2<<" ";
                    t3=a.popint();
                    cout<<t3<<" ";
                    switch(ch)
                    {
                              case '*':sum=t3*t2;break;
                              case '/':sum=t3/t2;break;
                              case '+':sum=t3+t2;break;
                              case '-':sum=t3-t2;break;
                              case '%':sum=t3%t2;break;
                    }
                    a.push(sum);
                    cout<<sum<<" ";
                    }
                    else break;
                    }
                    b.push(c[i]);
                }
            }
    }
                   while(b.top!=-1)
                   {
                   ch=b.popchar();
                    t2=a.popint();
                   cout<<t2<<" ";
                    t3=a.popint();
                    cout<<t3<<" ";
                    switch(ch)
                    {
                              case '*':sum=t3*t2;break;
                              case '/':sum=t3/t2;break;
                              case '+':sum=t3+t2;break;
                              case '-':sum=t3-t2;break;
                              case '%':sum=t3%t2;break;
                    }
                   a.push(sum);
                    }
    return sum;

}
int main()
{
    string s;
    cout<<"Enter the expression for evaluation: ";
    cin>>s;
    cout<<"The value is: "<<evaluate(s)<<endl;
//system("pause");
return 0;
}

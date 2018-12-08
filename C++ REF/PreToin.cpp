#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<string>
#define MAX 50
using namespace std;
class stack
{
    string s[MAX];
    int top;
   public:
       stack(){ top = -1; }
       void push(string k)
       {
           if(isFull())
           {
               cout<<"Stack Overflow..!!"; exit(1);
           }
           s[++top] = k;
       }
       void push(char k)
       {
           if(isFull())
           {
               cout<<"Stack Overflow..!!"; exit(1);
           }
           s[++top] = k;
       }
       string pop()
       {
           if(isEmpty())
           {
               cout<<"Stack is Empty..!!";
               exit(2);
           }
           return s[top--];
       }
       string topelem()
       {
           if(isEmpty())
           {
               cout<<"Stack is Empty..!!";
               exit(2);
           }
           return s[top];
       }
       int isFull()
       {
           if( top+1 == MAX )
              return 1;
           return 0;
       }
       int isEmpty()
       {
            if(top==-1)
              return 1;
            return 0;
       }
};

int main()
{
    stack op; char prefx[MAX],infx[MAX]; string temp;
    cout<<"Enter Prefix Expression : ";
       cin>>prefx;
    strrev(prefx);
    int i,j=0;
    for( i=0 ; prefx[i]!='\0' ; i++ )
    {
        if(isalnum(prefx[i]))
        {
            op.push(prefx[i]);
        }
        else
        {
            temp = ')'+op.pop() + prefx[i] + op.pop() + '(';
            op.push(temp);
        }
    }
    temp = op.topelem();
    int p = temp.length();
    while(p!=0)
    {
        infx[j++]= temp[--p];
    }
    infx[j]='\0';
    cout<<"\nInfix Expression : "<<infx;
    return 0;
}

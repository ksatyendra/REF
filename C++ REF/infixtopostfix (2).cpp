#include<iostream>
#include"stackheader.cpp"
using namespace std;
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
void convert(char *c)
{
   int i;
    stack op;
   for(i=0;c[i]!='\0';i++)
    {
            while(c[i]>=48&&c[i]<=57)
            {
            cout<<c[i];
            i++;
            }
            if(c[i]=='*'||c[i]=='/'||c[i]=='+'||c[i]=='-')
            {

                if(op.top==-1)
                op.push(c[i]);
                else
                if(priority(c[i])>=priority(op.elements[op.top]))
                {
                op.push(c[i]);
               // cout<<"in ";
                }
                else
                {   while(op.top!=-1)

                    {

                                     if(priority(c[i])<=priority(op.elements[op.top]))
                                    cout<<op.pop();
                                    else
                                     break;

                                     }
                    op.push(c[i]);
                }
            }
    }
     while(op.top!=-1)
                    {
                       //cout<<"in ";
                        //if(priority(c[i])>=priority(op.elements[op.top]))
                                    cout<<op.pop();
                                                       }


}
int main()
{
    char exp[50];
    cout<<"Enter the expression for evaluation to postfix: ";
    cin>>exp;
    cout<<"The expression in postfix form is: ";
    convert(exp);
 system("pause");
    return 0;
}


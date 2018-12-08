#include<iostream>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
int priority(char c)
{
                  /*if(x=='/')
                  return 4;
                 if(x=='*')
                   return (3);
                  if(x=='+')
                  return (2);
                  if(x=='-')
                  return 1;*/
                  	if ( c == '$' )
		return 3 ;
	if ( c == '*' || c == '/' || c == '%' )
		return 2 ;
	else
	{
		if ( c == '+' || c == '-' )
			return 1 ;
		else
			return 0 ;
	}
}
string convert(char *c)
{
   int i;
    stack<char> op;
    char ch;
    string s;
   for(i=strlen(c)-1;i>=0;i--)
    {
            if(c[i]>=48&&c[i]<=57)
             s=c[i]+s;
             //cout<<c[i];
            if(c[i]=='*'||c[i]=='/'||c[i]=='+'||c[i]=='-')
            {
                //cout<<"in2"<<" ";

                if(!op.empty())
                op.push(c[i]);//cout<<"in3"<<" ";}

                else
                if(priority(c[i])>=priority(op.top()))
                {
                op.push(c[i]);
                }
                else
                {
                    //cout<<"in3"<<" ";
                    ch=op.top();
                    op.pop();
                    s=ch+s;
                    //cout<<s<<" ";
                                op.push(c[i]);
                }
            }
    }
    while(!s.empty())
    {
        ch=op.top();
      op.pop();
        s=ch+s;
    }
return s;
}
int valuation(string post)
{
    int count=0;  
    stack<int> s1;
    stack<char> s2;
    for(int i=0;i<post.length();i++)
    {
      if(post[i]=="*"||post=="/"||post=="+"||post=="-")
 
        s2.push(post[i]);
       else
       {
          s1.push(int(post[i]));
          count++;
          if(count==2)
          {
            int op1=s1.top();
            s1.pop();
            int op2=s1.top();
            s1.pop();
            char c=s2.top();
            s2.pop();
            switch(c)
	           {
	             	case '*':s1.push(op1*op2);break;
		            case '/':s1.push(op1/op2);break;
		              case '+':s1.push(op1+op2);break;
	                 	case '-':s1.push(op1-op2);break;
	            }
            }
        }
      }
      
}           
int main()
{
    char exp[50];
    string st;
    cout<<"Enter the expression for evaluation to prefix: ";
    cin>>exp;
    cout<<"The expression in prefix form is: ";
    st=convert(exp);
    cout<<st;
   // cout<<st[st.length()];
    system("pause");
    return 0;
}


#include<iostream>
#include"stackheader.cpp"
#include<cstdlib>
using namespace std;
int evaluate(char *s)
{
    int result,i;
    stack a;
    int n1,n2,n3;
    for(i=0;s[i]!='\0';i++)
    {
         if ( s[i] == ' ' || s[i] == '\t' )
			i++ ;
		if( isdigit ( s[i] ) )
		{

			n1 = (int)s[i]-48;
			cout<<n1<<" ";
		    a.push(n1);
		}
		else
		{

			n2 = a.pop( ) ;
			n3 = a.pop( ) ;
			switch ( s[i] )
			{
				case '+' :
					  result = n3 + n2 ;
					  break ;

				case '-' :
					  result = n3 - n2 ;
					  break ;

				case '/' :
					  result = n3 / n2 ;
					  break ;

				case '*' :
					  result = n3 * n2 ;
					  break ;

				case '%' :
					  result = n3 % n2 ;
					  break ;

				//case '$' :
				//	 result = pow ( n2 , n1 ) ;
					 // break ;

				default :
					  cout << "Unknown operator" ;
					  exit ( 1 ) ;
			}

			a.push (result) ;
		}
    }
return(a.pop());
}
int main()
{
    char ch[50];
    cout<<"Enter the postfix expression for evaluation: ";
    cin>>ch;
    cout<<"The value is: "<<evaluate(ch)<<endl;
     system("pause");
}

# include <iostream.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <conio.h>

void main()
{
char arr[30],a[30],b[30];
int i=0,j=0,k=-1;

cout<<"Enter Infix To Convert Prefix:-    ";

cin >>arr;

strrev(arr);

int l=strlen(arr);

while(i<l)
{
 if(isalnum(arr[i]))
 {
  a[j]=arr[i];
 }
 else

 {if(arr[i]=='^')
   b[++k]='^';
  
  else if(arr[i]=='*')
  {while(b[k]=='^')
   {a[j]=b[k--];j++;}
    b[++k]='*';
  }
   else if(arr[i]=='/')
   {while(b[k]=='^')
    {a[j]=b[k--];j++;}
    b[++k]='/';
   }
   else if(arr[i]=='%')
   {while(b[k]=='^')
    {a[j]=b[k--];j++;}
    b[++k]='%';
   }
   else if(arr[i]=='+')
   {while((b[k]=='^')||(b[k]=='/')||(b[k]=='*'))
    {a[j]=b[k--];j++;}
    b[++k]='+';
   }
   else if(arr[i]=='-')
   {while((b[k]=='^')||(b[k]=='/')||(b[k]=='*'))
    {a[j]=b[k--];j++;}
    b[++k]='-';
   }
   else if(arr[i]==')')
    b[++k]=')';
   else if(arr[i]=='(')
   {
    while(b[k]!=')')
    {a[j]=b[k--];j++;}
    b[k]='\0';
    k--;
    }
   j--;
  }
 j++;
 i++;
}
while(b[k]!='\0')
{
 a[j]=b[k];
 j++;
 k--;
}
k=j-1;
while(k>=0)
{
 cout<<a[k];
k--;
}
cout << endl; 
}

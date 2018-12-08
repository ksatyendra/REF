#include<iostream>
#include<ctype.h>
using namespace std;
class listnode
{
   char data;
   listnode *next;
   friend class stack;
   public:
      listnode()
      {
	  next=NULL;
      }
};
class stack
{
   listnode *top;
   char  post[100];
   char in[100];
   float num[20];
   int count;
   int j;
   public:
       stack()
       {
	   j=0;
	   top=NULL;
	   count=0;
	   for(int i=0;i<20;i++)
	      num[i]=0;
       }
       void push(char c)
       {
	  listnode *temp;
	  temp=new listnode;
	  temp->data=c;
	  temp->next=top;
	  top=temp;
       }
       char pop()
       {
	  listnode *temp=top;
	  char c=temp->data;
	  top=top->next;
	  delete  temp;
	  return c;
       }
       void accept()
       {
	  cout<<"\nEnter the infix expression:";
	  cin>>in;
       }
       void convert()
       {
	    int i=0;
	    char tmp;
	    while(in[i]!='\0')
	    {
		if(!isdigit(in[i]))
		{
		   if(in[i]==')')
		   {
		       while(top->data!='(')
			   post[j++]=pop();
		       tmp=pop();
		   }
		   else if(in[i]=='(')
		      push(in[i]);
		   else
		   {
		     if(top!=NULL)
		     {
			 tmp=top->data;
			 while(islesseq(tmp,in[i]) && top!=NULL)
			 {
			    post[j++]=pop();
			    if(top)
			      tmp=top->data;
			 }
		     }
		     push(in[i]);
		   }
		   i++;
		}
		else
		{
		      post[j++]='c';
		      while(isdigit(in[i]))
		      {
			  num[count]=num[count]*10+in[i]-'0';
			  i++;
		      }
		      count++;
		}
	   }
	   while(top)
	   {
	      post[j++]=pop();
	   }
       }
       void print()
       {
	    int count=0;
	    for(int i=0;i<j;i++)
	    {
		 if(post[i]=='c')
		      cout<<num[count++]<<" ";
		 else
		      cout<<post[i]<<" ";
	    }
       }
       int islesseq(char t1,char t2)
       {
	    if(t1==t2)
	       return 1;
	    else
	    {
		if(t2=='*' || t2=='/')
		{
		    if(t1=='$' || t1=='*' || t1=='/')
		       return 1;
		}
		else if(t2=='+' || t2=='-')
		{
		   if(t1!='(')
		     return 1;
		}
	    }
	    return 0;
       }
};
int main()
{
   stack s;
   s.accept();
   s.convert();
   s.print();
}






















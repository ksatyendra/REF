#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
struct o
{
 int d;
 o *l;
}*s,*e,*q,*w;
void push(int w)
{
 o *t=new o;
 t->d=w;
 t->l=NULL;
 if(s==NULL)
 s=e=t;
 else
 e->l=t,e=e->l;
}
void pus(int m)
{
 o *t=new o;
 t->d=m;
 t->l=NULL;
 if(q==NULL)
 q=w=t;
 else
 w->l=t,w=w->l;
}
int pop()
{
 int m;
 if(s->l==NULL)
 {
  m=s->d,s=NULL;
  return m;
 }
 for(e=s;e->l->l!=NULL;e=e->l);
 m=e->l->d,e->l=NULL;
 return m;
}
int po()
{
 int m;
 if(q->l==NULL)
 {
  m=q->d,q=NULL;
  return m;
 }
 for(w=q;w->l->l!=NULL;w=w->l);
 m=w->l->d,w->l=NULL;
 return m;
}
void cnvrt()
{
 char k[50],s[50];
 int h=-1,i=0,j=0;
 cout<<"Enter Text :\n";
 cin.getline(k,50);
 for(;k[i]!='\0'&&k[i-1]!='\0';i++)
 {
  for(;k[i]!=' '&&k[i]!='\0';i++)
  {
   if((int)k[i]<48)
   {
    if((k[i]=='+'||k[i]=='-')&&(w->d==42||w->d==47))
    {
     while(j!=45&&j!=43)
      j=po(),s[++h]=(char)j;
     pus((int)k[i]);
    }
    else if(k[i]==')'&&w->d==40)
     j=po();
    else
     pus((int)k[i]);
   }
   else
    s[++h]=k[i];
  }
 }
 while(s!=NULL)
 s[++h]=po();
 s[++h]='\0';
 cout<<"\nANSWER IS THIS :\n\n";
 for(i=0;s[i]!='\0';i++)
  cout<<s[i];
}
void exp()
{
 cout<<"\n\nEnter expression :\n";
 int i=0,m1,m2,f=0,x=0;
 char k[50];
 cin.getline(k,50);
 for(;k[i]!='\0'&&k[i-1]!='\0';i++)
 {
  for(f=0,x=0;k[i]!=' '&&k[i]!='\0';i++)
  {
   if((int)k[i]<48)
   {
    m1=pop();
    m2=pop();
    switch((int)k[i])
    {
     case 43:push(m1+m2);
      break;
     case 45:push(-m1+m2);
      break;
     case 42:push(m1*m2);
      break;
     default :push(m2/m1);
    }
   }
   else
    x=x*10+((int)k[i]-48),f=1;
  }
  if(f==1)
   push(x);
 }
 cout<<"\n\nANSWER IS "<<s->d<<".\n\n";
}
void main()
{
 clrscr();
 cnvrt();
 getch();
}
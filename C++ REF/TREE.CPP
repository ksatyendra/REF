#include<iostream.h>
#include<conio.h>
#include<limits.h>
int h=INT_MIN;
struct o
{
 o *l;
 int v;
 o *r;
}*s,*e;
void cr(o *e,o *x)
{
 if(x->v<=e->v)
 {
  if(e->l==NULL)
   e->l=x;
  else
   cr(e->l,x);
 }
 else
 {
  if(e->r==NULL)
   e->r=x;
  else
   cr(e->r,x);
 }
}
void create()
{
 int i,n;
 cout<<"Enter no. of elements : ";
 cin>>n;
 cout<<"\nEnter elements : ";
 for(i=0;i<n;i++)
 {
  o *x=new o;
  cin>>x->v;
  x->l=NULL;
  x->r=NULL;
  if(s==NULL)
   e=s=x;
  else
   cr(s,x);
 }
}
void pre(o *e)
{
 cout<<e->v<<" ";
 if(e->l!=NULL)
  pre(e->l);
 if(e->r!=NULL)
  pre(e->r);
}
void in(o *e)
{
 if(e->l!=NULL)
  in(e->l);
 cout<<e->v<<" ";
 if(e->r!=NULL)
  in(e->r);
}
void post(o *e)
{
 if(e->l!=NULL)
  post(e->l);
 if(e->r!=NULL)
  post(e->r);
 cout<<e->v<<" ";
}
void ins()
{
 o *x=new o;
 x->l=NULL;
 x->r=NULL;
 cout<<"\nEnter element to insert : ";
 cin>>x->v;
 cr(s,x);
}
void ht(o *e,int k)
{
 if(e->l)
  ht(e->l,k+1);
 else
  if(h<k)
   h=k;
 if(e->r)
  ht(e->r,k+1);
 else
  if(h<k)
   h=k;
}
void d(o *e,o *x)
{
 if(x->v<e->v)
  d(e->l,x);
 else if(x->v>e->v)
  d(e->r,x);
 else
  e->v=0;
}
void del()
{
 o *x=new o;
 cout<<"Enter element to delete : ";
 cin>>x->v;
 d(s,x);
}
void tr(o *e,int k)
{
 if(e)
 {
  tr(e->r,k+1);
  cout<<endl;
  for(int i=0;i<k;cout<<"     ",i++);
  cout<<e->v;
  tr(e->l,k+1);
 }
}
void main()
{
 int ch=1;
 clrscr();
 create();
 while(ch!=0)
 {
  cout<<"\n\nEnter choice  [ ** 1 for insetion ** 2 for deletion ** 3 for preorder traversal ** 4 for inorder traversal ** 5 for postorder traversal ** 6 to show tree ** 7 to find height and depth ** 0 to terminate the program **]  :";
  cin>>ch;
  if(ch==0)
   break;
  if(ch==3)
  {
   cout<<"\nElements are after preorder traversal:\n";
   pre(s);
  }
  if(ch==4)
  {
   cout<<"\nElements are after inorder traversal:\n";
   in(s);
  }
  if(ch==5)
  {
   cout<<"\nElements are after postorder traversal:\n";
   post(s);
  }
  if(ch==1)
   ins();
  if(ch==2)
   del();
  if(ch==6)
  {
   cout<<"\nTree is :\n";
   tr(s,1);
  }
  if(ch==7)
  {
   ht(s,1);
   cout<<"\nHeigt is "<<h<<" and Depth is "<<h-1<<" .";
  }
 }
}
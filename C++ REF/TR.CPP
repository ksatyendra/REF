#include<iostream.h>
#include<conio.h>
#include<limits.h>
int h=INT_MIN;
struct o { o *l; int v; o *r; }*s,*e;
void cr(o *e,o *x)
{
 if(e->l==NULL && x->v<=e->v)  e->l=x;
 else if(e->r==NULL && x->v>e->v)  e->r=x;
 else  x->v<=e->v?cr(e->l,x):cr(e->r,x);
}
void create()
{
 int i,n;
 cout<<"Enter no. of elements : "; cin>>n;
 cout<<"\nEnter elements : ";
 for(i=0;i<n;i++)
 {
  o *x=new o;  cin>>x->v;  x->l=NULL;  x->r=NULL;
  if(s==NULL)   e=s=x;
  else   cr(s,x);
 }
}
void pre(o *e)
{
 cout<<e->v<<" ";
 if(e->l!=NULL)  pre(e->l);
 if(e->r!=NULL)  pre(e->r);
}
void in(o *e)
{ if(e!=NULL) {  in(e->l);  cout<<e->v<<" ";  in(e->r); } }
void post(o *e)
{
 if(e->l!=NULL)  post(e->l);
 if(e->r!=NULL)  post(e->r);
 cout<<e->v<<" ";
}
void ht(o *e,int k)
{
 if(e->l)  ht(e->l,k+1);
 else  if(h<k)   h=k;
 if(e->r)  ht(e->r,k+1);
 else  if(h<k)   h=k;
}
void ins()
{
 o *x=new o; x->l=NULL; x->r=NULL; cout<<"\nEnter element to insert : "; cin>>x->v; cr(s,x);
}
void d(o *e,o *x)
{
 if(x->v<e->v)  d(e->l,x);
 else if(x->v>e->v)  d(e->r,x);
 else  e->v=0;
}
void del()
{
 o *cur,*par; int j; cout<<"\nEnter no. to delete : "; cin>>j;
 for(e=s;e;)
 {
  if(e->v==j)  break;
  else  {   par=e;   e->v>j?e=e->l:e=e->r;   continue;  }
 }
 cur=e;
 if( !(cur->l) && !(cur->r) )
 {
  if(cur==s)  {   s=NULL;   return;  }
  par->v<j?par->r=NULL:par->l=NULL;  cur=NULL;  return;
 }
 if(!(cur->l))
 {
  if(cur==s)  {   s=s->r;   return;  }
  par->v<j?par->r=cur->r:par->l=cur->r;  cur=NULL;  return;
 }
 if(!(cur->r))
 {
  if(cur==s)  {   s=s->l;   return;  }
  par->v<j?par->r=cur->l:par->l=cur->l;  cur=NULL;  return;
 }
 for(par=e,e=e->l;e->r;par=e,e=e->r);
 cur->v=e->v; par==cur?par->l=e->l:par->r=e->l; e=NULL; return;
}
void tr(o *e,int k)
{
 if(e)
 {
  tr(e->r,k+1);  cout<<endl;
  for(int i=0;i<k;cout<<"     ",i++);
  cout<<e->v;  tr(e->l,k+1);
 }
}
int main()
{
 int ch=1; create();
 while(ch!=0)
 {
  cout<<"\n\nEnter choice  [ ** 1 for insetion ** 2 for deletion ** 3 for preorder traversal ** 4 for inorder traversal ** 5 for postorder traversal ** 6 to show tree ** 7 to find height and depth ** 0 to terminate the program **]  :";
  cin>>ch;
  if(ch==0)   break;
  if(ch==3)  {   cout<<"\nElements are after preorder traversal:\n";   pre(s);  }
  if(ch==4)  {   cout<<"\nElements are after inorder traversal:\n";   in(s);  }
  if(ch==5)  {   cout<<"\nElements are after postorder traversal:\n";   post(s);  }
  if(ch==1)  ins();
  if(ch==2)  del();
  if(ch==6)  {   cout<<"\nTree is :\n";   tr(s,1);  }
  if(ch==7)  {   ht(s,1);   cout<<"\nHeigt is "<<h<<" and Depth is "<<(h-1)<<" .";  }
 }
 return 0;
}
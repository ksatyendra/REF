#include<iostream>
#include<cmath>
using namespace  std;
struct node
{
       int data;
       node *next;
       };
void add(node *&l,int k)
{
     if(l==NULL)
     {
               l=(node*)new(node);
               l->data=k;
               l->next=NULL;
              // cout<<l->data;
               }
     else
     {
         while(l->next!=NULL)
         l=l->next;
         l->next=(node*)new(node);
         l->next->data=k;
         l->next->next=NULL;
         }
         }
void print(node *l)
{
     if(l==NULL)
     cout<<"\nLinked List is Empty.";
     cout<<"\nLinked List:- ";
     while(l!=NULL)
     {
                   cout<<l->data<<" ";
                   l=l->next;
                   }
                   }
int main()
{
    node *r[10],*m=NULL;int i,n;
    for(i=0;i<10;i++)r[i]=NULL;
    cout<<"Enter size:-";
    cin>>n;
    int a[n],j,k,d,ln,max;
    cout<<"\nEnter numbers:-";
    for(i=0;i<n;i++)
    {
    cin>>a[i];
    if(i==0) max=a[i];
    else
    {if(a[i]>max)
    max=a[i];}}//cout<<"\t"<<max;
    for(ln=0;max>0;ln++)
    max=max/10;//cout<<"\t"<<ln;
    for(j=0;j<ln;j++)
    {
     for(i=0;i<n;i++)
     {//cout<<" "<<(10^j)<<" ";cout<<"  "<<(a[i]/(10^j))<<"  ";
     d=(a[i]/(int) pow(10,j))%10;//cout<<"\tremainder="<<d;
     m=r[d];
     if(m==NULL){add(m,a[i]);r[d]=m;}
     else add(m,a[i]);
     }
     for(i=0;i<n;){
     for(k=0;k<10;k++){
      while(r[k]!=NULL)
      {a[i++]=r[k]->data;//cout<<"\ta="<<r[k]->data;
       r[k]=r[k]->next;}
       }}
    }
     cout<<"\nSorted number:-";
       for(i=0;i<n;i++)
       cout<<a[i]<<" ";
//system("pause");
}










#include<iostream>
#include<cstdlib>
using namespace std;
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
     else{
     cout<<"\nLinked List:- ";
     while(l!=NULL)
     {
          cout<<l->data<<" ";
          l=l->next;
          }}}
int searchkeep(node *&l,int k)
{
    node *s=l,*t=NULL;
    while(l!=NULL)
    {
                  if(l->next->data==k)
                  {
                                cout<<"\nElement found:- ";
                                t=l->next;
                                l->next=t->next;
                                t->next=s;
                                l=t;
                                return(l->data);
                                }
                  else
                  l=l->next;
                  }cout<<"\nElement not found";
                  }

int main()
{
    int c,n1;
    node *n=NULL,*m=NULL;
    cout<<"Choices are given below:-";
    cout<<"\n1.Add \n2.search element\n3.Display\n4.Exit";
    do
    {
      cout<<"\nEnter your choice:- ";
      cin>>c;
      switch(c)
      {
         case 1:cout<<"\nEnter the number:- ";
                cin>>n1;
                if(n==NULL)
                {
                add(n,n1);cout<<"\nAdded";m=n;}
                else
                {add(n,n1);cout<<"\nAdded";}break;
         case 2:cout<<"\Enter number to be searched:- ";
                cin>>n1;
                searchkeep(m,n1);break;
         case 3:print(m);break;
         case 4:cout<<"\nTerminating"; exit(1);break;
         default:cout<<"\nWrong Choice";break;
         }}while(c!=4);
    //system("pause");
    }

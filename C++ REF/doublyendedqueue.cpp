#include<iostream>
#include<cstdlib>
using namespace std;
#include "doublyendedqueue.cpp"
void enqueue(dnode* &l)
{
    int choice,k;
    cout<<"Enter the choice: \n1.Adding at First\n2.Adding at Last\n ";
    cin>>choice;
    cout<<"Enter the element: ";
    cin>>k;
   // int top1,top2;
    if(l==NULL)
    {
        l=new dnode;
        l->data=k;
        l->right=NULL;
        l->left=NULL;
    }
    else
    {
        if(choice==2)
        {
            dnode* t;
            t=l;
            add(t,k);

        }
        if(choice==1)
        {
            dnode *t;
            t=new dnode;
            t->data=k;
            l->left=t;
            t->right=l;
            t->left=NULL;
            l=t;
            }
    }


}
void dequeue(dnode* l)
{
    int choice;
    cout<<"Enter the choice: \n1.Dequeing at First\n2.Dequeueing at Last\n ";
    cin>>choice;
   if(l==NULL)
   cout<<"Queue Empty...";
    if(choice==1)
    {
        dnode *t;
        t=l;
        l=l->right;
        l->left==NULL;
        cout<<t->data<<"dequeued ...\n";
        delete t;
    }
    else
    {
        dnode *t;
        while(l->right!=NULL)
        l=l->right;
        t=l->right;
        l->right=NULL;
        t->left=NULL;
        cout<<t->data<<"dequeued..\n";
        delete t;
    }
}
int main()
{
    dnode *m=NULL,*n=NULL;
    int i=0,c;
    cout<<"Menu:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
    while(1)
    {
        cout<<"Enter choice: ";
    cin>>c;
    if(c==1)
    {
        if(i==0)
        {
            enqueue(m);
            n=m;
        }
        else
        enqueue(m);
        i++;
    }
    if(c==2)
    dequeue(n);
    if(c==3)
    print_list(n);
    if(c==4)
    exit(1);
    }
    return 0;
}

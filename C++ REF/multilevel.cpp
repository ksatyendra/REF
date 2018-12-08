#include<iostream>
using namespace std;
//#include"linkedlist.cpp"
struct node
{
    char data;
    node *sublist;
    node *next;

};
int index=0;
int array[20];
int multilevel(node* set,char *c)
{    int size=0;
        static int i=0;
        while(c[i]!='\0')
        {   //cout<<"in "<<i;
            if(c[i]==')')
            {   i++;
                array[index++]=size;
                return size;
            }
           else if(c[i]=='(')
               {
                i++;
               size=multilevel(set->sublist,c);
               }
              else{
                set=new node;
               set->data=c[i];
               set->sublist=NULL;
               size++;
               cout<<set->next->data<<" ";
              set->next->next=NULL;
               i++;}

        }
}
void display(node *n)
{
    while(n->next!=NULL)
    {   cout<<"check In ";
        while(n->next->sublist==NULL)
    {   cout<<" In ";
        cout<<n->next->data;
    }
    int spaces=0;
    for(int i=0;i<10;i++)
    spaces+=array[i];
    for(int i=0;i<spaces;i++)
    cout<<" ";
    n=n->next;
    }
}
int main()
{
    char exp[50];
    int i;
    node *s;
    cout<<"Enter the set expresion: ";
    cin>>exp;
    s=new node;
    multilevel(s,exp);
    cout<<"The set: \n";
    //for(i=0;i<10;i++)
    //cout<<array[i]<<" ";
    display(s);
    return 0;
}

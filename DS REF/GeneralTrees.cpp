#include<iostream>
using namespace std;
struct node {
            char ch;
            node *down,*right;
            node(char t='\0')
            {
                      ch=t;
                      down=right=NULL;
            }
            };
typedef node* PTR;
void crt(PTR &t,char ch)
{
     //PTR tree=t;
     char c;
     cout<<"Enter "<<ch<<"'s children one-by-one:";
     cin>>c;
     while(c!='o')
     {
                  PTR l=t;
                  if(l!=NULL)
                  {
                  for(;l->right!=NULL;l=l->right,cout<<l->ch);
                  l->right=new node(c);
                  l->right->right=l->right->down=NULL;
                  crt(l->right->down,c);
                  }
                  else
                  {
                  t=new node(c);
                  t->right=t->down=NULL;
                  crt(t->down,c);
                  }
                  cout<<"Enter "<<ch<<"'s next child:";
                  cin>>c;
     }
}
void prn(PTR t)
{
     PTR tree=t;
     for(;t!=NULL;t=t->right)
     cout<<t->ch<<" ";
     cout<<endl;
     for(;tree!=NULL;tree=tree->right,cout<<" ")
     prn(tree->down);
}
int main()
{
    PTR s=NULL,t=s;
    char ch;
    cin>>ch;
    s=t=new node(ch);
    s->right=s->down=NULL;
    crt(s->down,ch);
    s=t;
    //while(s!=NULL)
    //{
    //              cout<<s->ch;
    //              s=s->right;
    //}
    prn(s);
    cin.get();
    cin.get();
    return 0;
}

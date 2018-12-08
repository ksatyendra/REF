#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct dnode
{
    dnode *left;
    float data;
    dnode *right;
};
struct lnode
{
    int data;
    lnode *lnext;
};
struct stk
{
    char data[10];
    stk *snext;
};
union unn
{
    dnode *d;
    lnode*L;
    stk *s;
};
struct node
{
    int tag;
    unn u;
    node *next;
};
dnode *NewDnode(float data)
{
    dnode *np;
    np=new dnode;
        np->data=data;
    np->right=NULL;
    np->left=NULL;
    return np;
}
node *NewNode(int tag)
{
    node *np;
    np=new node;
    np->tag=tag;
    np->next=NULL;
    return np;
}
lnode *NewLnode(int data)
{
    lnode *np;
    np=new lnode;
    np->data=data;
    np->lnext=NULL;
    return np;
}
stk *NewStk(char data[])
{
    stk*np;
    np=new stk;
    strcpy(np->data,data);
    np->snext=NULL;
}
int isstring(char ch[])
{
    int i;
    i=(int)ch[0];
    if(i>=48&&i<=56)
        return 0;
        else
        return 1;
}
int isinteger(char ch[])
{
    int i,flag=1;
    i=(int)ch[0];

    if(i>=48&&i<=56)
    {
        for(int j=0;j<strlen(ch);j++)
        {
            if(ch[j]=='.')
                {flag=0;break;}

        }
    }
    if(flag)
    return 1;
        else
            return 0;
}
void display(node *st)
{

    while(st!=NULL)
    {
      if(st->tag==1)
      {
          cout<<st->tag<<".Integers";
          if(st->u.L!=NULL)
          while(st->u.L!=NULL)
          {
              cout<<"-->"<<st->u.L->data;
              st->u.L=st->u.L->lnext;
          }
           cout<<endl;
      }

      else if(st->tag==2)
      {

          cout<<st->tag<<".String";
          if(st->u.s!=NULL)
          while(st->u.s!=NULL)
          {
              cout<<"->"<<st->u.s->data;
              st->u.s=st->u.s->snext;
          }
          cout<<endl;
      }

      else if(st->tag==3)
      {
          cout<<st->tag<<".float";
          if(st->u.d!=NULL
             )
          while(st->u.d!=NULL)
          {
          cout<<"<-->"<<st->u.d->data;
          st->u.d=st->u.d->right;
          }
          cout<<endl;
      }
      st=st->next;
    }
}
int main()
{
    char c='y';
    //stk *shead,*ns,*q;
    stk *ns,*b;
    node *start,*p,*q,*newNode;

    start=p=NULL;
     for(int i=1;i<=3;i++)
    {
        newNode=NewNode(i);
        if(start==NULL)
        {
            start=p=newNode;
        }
        else{
            p->next=newNode;
            p=newNode;
        }
    }
    q=start;
    while(q!=NULL)
    {
        if(q->tag==1)
           {q->u.L=new lnode;q->u.L=NULL;}
        else if(q->tag==2)
            {q->u.s=new stk;q->u.s=NULL;}
        else if(q->tag==3)
        {q->u.d=new dnode;q->u.d=NULL;}
        q=q->next;
           }
    q=start;
//    newNode=NewNode(i)
      while(c=='y'||c=='Y')
      {

    cout<<"Input data :";
    char ch[20];
    cin>>ch;
    if(isstring(ch))
    {
        while(q->tag!=2)
            q=q->next;


          ns=NewStk(ch);

          if(q->u.s==NULL)
           {

            q->u.s=ns;}

          else
          {
              b=q->u.s;
              q->u.s=ns;
              ns->snext=b;
          }


    }
    q=start;
    lnode *ln;
    if(isinteger(ch)&&(!isstring(ch)))
    {
       while(q->tag!=1)
        q=q->next;
        int i;
        i=atoi(ch);
       ln=NewLnode(i);
       if(q->u.L==NULL)
        q->u.L=ln;
       else{
        while(q->u.L->lnext!=NULL)
        {
            q->u.L=q->u.L->lnext;
        }
        q->u.L->lnext=ln;
       }
    }
    q=start;
    dnode *dn;
    if(!isinteger(ch)&&!isstring(ch))
    {
        while(q->tag!=3)
            q=q->next;
         float f;

         f=atof(ch);

        dn=NewDnode(f);
        if(q->u.d==NULL)
            {q->u.d=dn;


               }
        else
        {

            while(q->u.d->right!=NULL)
            {
                q->u.d=q->u.d->right;
            }
            q->u.d->right=dn;
            dn->left=q->u.d;
        }
    }

    cout<<"Want to enter more data<y/n>:";

    cin>>c;
      }
      display(start);
      return 0;
}

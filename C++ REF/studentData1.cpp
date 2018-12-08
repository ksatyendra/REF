#include<iostream>
using namespace std;
struct snode;
struct cnode;
struct link;
union unn1
{
    snode *snext;
    link *rnext;
};
union unn2
{
    cnode *cnext;
    link *dnext;
};
struct link
{
  //int tag1,tag2;
  unn2 u2;
  unn1 u1;

};
 struct snode
{
    int rno;
   // snode *snext;
    link *lnext;

};
struct cnode
{
    int cno;
    char grade;
   // cnode *cnext;
    link *lnext;
};

int main()
{
    int n,cn,sn;
    cout<<"Enter total no. of students:";cin>>n;
    snode *s[n];
    cnode *c[6];
    for(int i=0;i<n;i++)
        s[i]=new snode;
    for(int i=0;i<6;i++)
    {
        c[i]=new cnode;
        c[i]->lnext=NULL;
    }
    cout<<"Enter data of students\n";
    for(int i=0;i<n;i++)
    {
        char ch='y';
       cout<<"Enter Roll no.:";
       cin>>sn;
       s[i]->rno=sn;
       s[i]->lnext=NULL;
       link *q;
       while(ch=='y')
       {
       cout<<"Enter course no.<=5:";
       cin>>cn;
       q = new link;
       if(c[cn]->lnext==NULL)
       {
         if(s[i]->lnext==NULL)
         {
             s[i]->lnext=q;
             c[cn]->lnext=q;
         }
         else
         {
            s[i]->lnext->u1.rnext=q;
            c[cn]->lnext=q;
            s[i]->lnext=q;
         }
       }
       else
       {

          if(s[i]->lnext==NULL)
         {s[i]->lnext=q;
           c[cn]->lnext=q;}
         else{
                s[i]->lnext->u1.rnext=q;
            c[cn]->lnext->u2.dnext=q;
                  s[i]->lnext=q;
                  c[cn]->lnext=q;

         }
       }
       cout<<"Wanna add more <y/n>:";
       cin>>ch;
       }
    }
    for(int i=0;i<6;i++)
    {
        if(c[i]->lnext==NULL)
            continue;
        else

       {c[i]->lnext->u2.cnext=c[i];}
    }
    for(int i=0;i<n;i++)
    {
         s[i]->lnext->u1.snext=s[i];

    }

    //Displaying......
    int choice,r;link *p,*q;
      p=new link;
    cout<<"press\n1.to know about particular student\n2.to know about courses\n";
    cin>>choice;
    if(choice==1)
    {
        cout<<"ENTER THE ROLL NO. OF STUDENT:";
        cin>>r;
        cout<<"Student is registered fr :";

        do
        {
            p=s[r]->lnext;
            q=p;
            /*while(!q->u2.dnext)
            {
                q=q->u2.dnext;cout<<"fuck";
            }*/
            cout<<q->u2.cnext->cno;
        }while(p->u1.snext!=s[r]);
    }
    return 0;
}








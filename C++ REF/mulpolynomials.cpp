#include<iostream>
using namespace std;
struct lnode
{
       float c;
       int e;
       lnode* next;
       lnode(float coeff,int exp)
       {
                   c=coeff;
                   e=exp;
                   next=NULL;
       }
};
void insert(lnode* &l,float c,int e)
{
     lnode* t=l;
     if(l==NULL)
     {
     l=new lnode(c,e);
     return;
     }
     else
     if(e<l->e)
     {
               insert(l->next,c,e);
               return;
     }
     else
     if(e==l->e)
     {
                l->c+=c;
                return;
     }
     l=new lnode(c,e);
     l->next=t;
}
void mul(lnode* &l,lnode* l1,lnode* l2)
  {
        lnode *t=l2;
        if(l1==NULL||l2==NULL)
        return;
        else
        {
        while(l1!=NULL)
        {
                       l2=t;
                       while(l2!=NULL)
                       {
                                      insert(l,l1->c*l2->c,l1->e+l2->e);
                                      l2=l2->next;
                       }
                       l1=l1->next;
        }
        }
  }
void display(lnode *l)
{
 lnode *temp = l;
	int f = 0;
	while ( temp != NULL )
	{
		if ( f != 0 )
		{
				if ( temp -> c> 0 )
				cout << " + " ;
			else
				cout << " " ;
		}
		if ( temp -> e != 0 )
			cout << temp -> c << "x^" << temp -> e ;
		else
			cout << temp -> c ;
		temp = temp -> next ;
		f = 1 ;
	}
	cout<<endl;
}                  
int main()
{   lnode *l1=NULL,*l2=NULL,*l3=NULL;
    cout<<"Enter the Ist polynomial as coeff and exponent in order: ";
    float num1;
    int flag=1,num2;
    while(flag!=0)
    {
        cin>>num1>>num2;
        insert(l1,num1,num2);
        cout<<"Add- 0 or 1: ";
        cin>>flag;
    }
    cout<<"Enter the 2nd polynomial as coeff and exponent in order: ";
    flag=1;
    while(flag!=0)
    {
        cin>>num1>>num2;
        insert(l2,num1,num2);
        cout<<"Add- 0 or 1: ";
        cin>>flag;
    }
    	  display(l1) ;
    	  	  display(l2) ;
    mul(l3,l1,l2);
    cout << "\nResultant polynomial: " ;
	  display(l3) ;
	  system("pause");
   }
    

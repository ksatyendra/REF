#include<iostream>
#include<cstring>
using namespace std;
class addnum
{
    struct node
    {
    int num;
    node *next;
    }*p;
    public:
    addnum();
    void append(int n1);
    void addbeg(int n1);
    void display();
    int count();
    void add_numbers(addnum &l1,addnum &l2);
};
addnum::addnum()
{
    p=NULL;
}
void addnum::append(int n1)
{
    node *t,*x;
    t=p;
    if(t==NULL)
    {
        t=new node;
        p=t;
    }
    else
       {

        while(t->next!=NULL)
        t=t->next;
        t->next=new node();
        t=t->next;
    }
    t->num=n1;
    t->next=NULL;

}
void addnum::addbeg(int n1)
{
    node *temp ;

	// add new node
	temp = new node ;

	temp -> num = n1;
	temp -> next = p ;
	p = temp ;
}
void addnum::display()
{
   node *temp = p ;
	// traverse the entire linked list
	while ( temp != NULL )
	{

        cout<<temp->num;
        temp=temp->next;
	}
	cout<<endl;
}
/*
void addnum::add_numbers(addnum &l1,addnum &l2)
{
    node *z;
    int credit=0;
    if ( l1.p == NULL && l2.p == NULL )
		return ;
    node *t1,*t2;
    t1=l1.p;
    t2=l2.p;
    while(t1!=NULL&&t2!=NULL)
    {
        if ( p == NULL )
		{
			p = new node ;
			z = p ;
		}
		else
		{
		    z->next=new node;
		    z=z->next;
		}

        z->num=(t1->num+t2->num+credit)%10;
        credit=(t1->num+t2->num)/10;
        cout<<credit;
        t1=t1->next;
        t2=t2->next;



    }
    if(t1==NULL&&t2==NULL)
    {
       cout<<"in ";
        z->next=new node;
        z->next->num=credit;

    }
    z->next->next=NULL;
}*/
void addnum::add_numbers(addnum &l1,addnum &l2)
{
    addnum z;
    int credit=0;
    if ( l1.p == NULL && l2.p == NULL )
		return ;
    node *t1,*t2;
    t1=l1.p;
    t2=l2.p;
    while(t1!=NULL&&t2!=NULL)
    {
        z.addbeg((t1->num+t2->num+credit)%10);
        credit=(t1->num+t2->num)/10;
        //cout<<credit;
        t1=t1->next;
        t2=t2->next;
    }
        if(t1==NULL&&t2==NULL&&credit!=0)
        z.addbeg(credit);
        z.display();
}
int main()
{
    addnum x1,x2,x3;
    int i=0,k=0;
    char n1[200],n2[200];
    cout<<"Enter first number: ";
    cin>>n1;
    cout<<"Enter second number: ";
    cin>>n2;
    //if(strlen(n1)>strlen(n2))
    int s1=strlen(n1);
    int s2=strlen(n2);
    int max;
    if(s1>s2)
    {
    while(s1>s2)
    {
        x1.addbeg(n1[i]-48);
        x2.addbeg(0);
        s1--;i++;
    }
    while(s1>0)
    {
       x1.addbeg(n1[i]-48);i++;
       x2.addbeg(n2[k]-48);k++;
       s1--;
    }
    }
    else
    {
    while(s2>s1)
    {
        x2.addbeg(n2[i]-48);
        x1.addbeg(0);
        s2--;i++;
    }
    while(s2>0)
    {
       x2.addbeg(n2[i]-48);i++;
       x1.addbeg(n1[k]-48);k++;
       s2--;
    }
    }
    //for(int i=0;n1[i]!='\0';i++)
   // x1.addbeg(n1[i]-48);
  //
   // for(int i=0;n2[i]!='\0';i++)
  //  x2.addbeg(n2[i]-48);

    //

     //x1.display();
     //x2.display();
    cout<<"The sum is: ";
    x3.add_numbers(x1,x2);
    //x3.display();
// system("pause");
       return 0;
}

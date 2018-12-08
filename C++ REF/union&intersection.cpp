#include<iostream>
#include<cstring>
using namespace std;
class ll
{
    struct node
    {
    int num;
    node *next;
    }*p;
    public:
    ll();
    void append(int n1);
    void addbeg(int n1);
    void display();
    int search(int);
    int count();
    void intersection(ll&,ll&);
    void union_of_lists(ll&,ll&);
};
ll::ll()
{
    p=NULL;
}
void ll::append(int n1)
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
void ll::addbeg(int n1)
{
    node *temp ;

	// add new node
	temp = new node ;

	temp -> num = n1;
	temp -> next = p ;
	p = temp ;
}
void ll::display()
{
   node *temp = p ;
	// traverse the entire linked list
	while ( temp != NULL )
	{

        cout<<temp->num<<" ";
        temp=temp->next;
	}
	cout<<endl;
}
void ll::intersection(ll& l1,ll& l2)
{
    ll z;
    node *t1,*t2;
    if ( l1.p == NULL || l2.p == NULL )
		return ;
    t1=l1.p;
    t2=l2.p;
    for(int i=0;t1!=NULL;i++,t1=t1->next,t2=l2.p)
    while(t2!=NULL)
    {
        if(t1->num==t2->num)
        z.append(t1->num);
        t2=t2->next;
    }
    z.display();
}
void ll::union_of_lists(ll& l1,ll& l2)
{
    ll z;
    node *t1,*t2;
    if ( l1.p == NULL || l2.p == NULL )
		return ;
    t1=l1.p;
    t2=l2.p;
    //t3=z.p;
    while(t2!=NULL)
    {
        z.append(t2->num);
         t2=t2->next;
    }
   // cout<<z.p->num;
   t2=l2.p;
    while(t1!=NULL)
    {   while(t2!=NULL)
        if(t1->num==t2->num)
            break;
        else
        {
           t2=t2->next;
        }
        if(t2==NULL)
        z.append(t1->num);
        t2=l2.p;
        t1=t1->next;
    }
    z.display();
}
int main()
{
    ll a1,a2;
    int num;
    cout<<"Enter the elements in list 1 and add -1 at the end: ";
    while(1)
    {
        //cout<<"Enter element: ";
        cin>>num;
        if(num==-1) break;
        a1.append(num);
    }
    cout<<"Enter the elements in list 2 and add -1 at the end: ";
    while(1)
    {
        //cout<<"Enter element: ";
        cin>>num;
        if(num==-1) break;
        a2.append(num);
    }
    cout<<"The common elements in both lists are: ";
    a1.intersection(a1,a2);
    cout<<"The union of elements in both lists are: ";
    a1.union_of_lists(a1,a2);

    return 0;
}

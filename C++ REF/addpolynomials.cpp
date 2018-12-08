#include<iostream>
using namespace std;
class addp
{
    struct node
    {
    int coeff,exp;
    node *next;
    }*p;
    public:
    addp();
    void append(int n1,int n2);
    void display();
    int count();
    void add_poly(addp &l1,addp &l2);
    void mul_poly(addp &l1,addp & l2);
};
addp::addp()
{
    p=NULL;
}
void addp::append(int n1,int n2)
{
    node* t;
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
    t->coeff=n1;
    t->exp=n2;
    t->next=NULL;
}
void addp::display()
{
   node *temp = p ;
    int flag=0;
	cout << endl ;
	// traverse the entire linked list
	while ( temp != NULL )
	{
		if ( flag !=0 )
		{
			// display sign of a term
			if ( temp -> coeff > 0 )
				cout << " + " ;
			else
				cout << " " ;
		}
		if ( temp -> exp != 0 )
			cout << temp -> coeff << "x^" << temp -> exp ;
		else
			cout << temp -> coeff ;
		temp = temp -> next;
		flag = 1 ;
	}
	cout<<endl;
}
void addp::add_poly(addp &l1,addp &l2)
{
    node *z;
    if ( l1.p == NULL && l2.p == NULL )
		return ;
    node *temp1,*temp2;
    temp1=l1.p;
    temp2=l2.p;
    while(temp1!=NULL&&temp2!=NULL)
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
			if ( temp1 -> exp < temp2 -> exp )
		{
			z -> coeff = temp2 -> coeff ;
			z -> exp = temp2 -> exp ;

			// go to the next node
			temp2 = temp2 -> next ;
		}
		else
		{
			if ( temp1 -> exp > temp2 -> exp )
			{
				z -> coeff = temp1 -> coeff ;
				z -> exp = temp1 -> exp ;

				// go to the next node
				temp1 = temp1 -> next;
			}
			else
			{
				// add the coefficients, when exponents are equal
				if ( temp1 -> exp == temp2 -> exp )
				{
					// assigning the added coefficient
					z -> coeff = temp1 -> coeff + temp2 -> coeff ;
					z -> exp = temp1 -> exp ;

					// go to the next node
					temp1 = temp1 -> next ;
					temp2 = temp2 -> next ;
				}
			}
		}
	}

	// assign remaining terms of the
	// first polynomial to the result
	while ( temp1 != NULL )
	{
		if ( p == NULL )
		{
			p = new node ;
			z = p ;
		}
		else
		{
			z -> next = new node ;
			z = z -> next ;
		}

		// assign coefficient and exponent
		z -> coeff = temp1 -> coeff ;
		z -> exp = temp1 -> exp ;

		// go to the next node
		temp1 = temp1 -> next ;
	}

	// assign remaining terms of
	// second polynomial to the result
	while ( temp2 != NULL )
	{
		if ( p == NULL )
		{
			p = new node ;
			z = p ;
		}
		else
		{
			z -> next = new  node ;
			z = z -> next ;
		}

		// assign coefficient and exponent
		z -> coeff = temp2 -> coeff ;
		z -> exp = temp2 -> exp ;

		// go to the next node
		temp2 = temp2 -> next ;
	}

	// assign NULL at end of resulting linked list
	z -> next = NULL ;
}
void addp::mul_poly(addp &l1,addp & l2)
{

}
int main()
{
    addp p1,p2;
    cout<<"Enter the Ist polynomial as coeff and exponent in order: ";
    int flag=1,num1,num2;
    while(flag!=0)
    {
        cin>>num1>>num2;
        p1.append(num1,num2);
        cout<<"Add- 0 or 1: ";
        cin>>flag;
    }
    cout<<"Enter the 2nd polynomial as coeff and exponent in order: ";
    flag=1;
    while(flag!=0)
    {
        cin>>num1>>num2;
        p2.append(num1,num2);
        cout<<"Add- 0 or 1: ";
        cin>>flag;
    }
    addp p3 ;
	p3.add_poly( p1, p2 ) ;
    cout << "\nResultant polynomial: " ;
	p3.display( ) ;

}

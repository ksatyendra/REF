#include<iostream>
using namespace std;
union union1
{
	int cno;
	int rno;
};
struct rnode
{
	int tag;
	union1 u;
	rnode *next;
	rnode *down;
};
int main()
{
	rnode *r,*r1;
	r=new rnode;
	r->down='\0';
	r->next='\0';
	int ns,nc,n,i;
	cout<<"Enter Number of student : ";
	cin>>ns;
	cout<<"Enter Number of Courses : ";
	cin>>nc;
	for(int j=0;j<ns;j++)
	{
		rnode *t1;
		t1=new rnode;
		cout<<"Enter Student Roll No. : ";
		cin>>t1->u.rno;
		t1->down='\0';
		t1->next='\0';
		t1->tag=1;
			rnode *r1=r;
			while(r1->down!='\0')
			r1=r1->down;
			r1->down=t1;
    }
    for(int j=0;j<nc;j++)
	{
		rnode *t2;
		t2=new rnode;
		cout<<"Enter Courses Number : ";
		cin>>t2->u.cno;
		t2->down='\0';
		t2->next='\0';
		t2->tag=2;
			rnode *r1=r;
			while(r1->next!='\0')
			r1=r1->next;
			r1->next=t2;
    }
    rnode *s=r->down;

    while(s!='\0')
	{
		int m,k=0;
		rnode *l='\0';
		cout<<"Enter No of registered courses for Roll No. : "<<s->u.rno<<"\n";
		cin>>n;
		 for(i=0;i<n;i++)
		 {
		 	rnode *c=r->next;
		 	cout<<"Enter courses No. : ";
		 	cin>>m;
			while(c->u.cno!=m)
			c=c->next;
			rnode *t;
			t=new rnode;
			t->next='\0';
			t->down='\0';
			if(l=='\0'&&i!=n-1)
			{
				l=t;
				s->next=t;
				if(c->down=='\0')
				    {
				    	c->down=t;
				    }
				else
				{
					rnode *q=c->down;
					while(q->down!='\0')
					q=q->down;
					q->down=t;
				}
			}
			else if(i!=n-1)
			{
		     	l->next=t;
				if(c->down=='\0')
				    {
		     	    	c->down=t;
				    }
				else
				{
					rnode *q=c->down;
					while(q->down!='\0')
					q=q->down;
					q->down=t;
				}
				l=t;
			}
			else if(i==n-1)
			{
			    if(l!='\0')
			    l->next=t;
			    else
			    {
			    	l=s->next=t;
			    }
			    if(c->down=='\0')
				    {
		     	    	c->down=t;
				    }
				else
				{
					rnode *q=c->down;
					while(q->down!='\0')
					q=q->down;
					q->down=t;
				}
				t->next=s;
				s=s->down;
			}
		 }
    }
    rnode *c=r->next;
    while(c!='\0')
    {
    	rnode *q;
    	q=c->down;
    	while(q&&q->down!='\0')
    	{
    	 q=q->down;
        }
    	q->down=c;
    	c=c->next;
    }
    c=r->next;
    s=r->down;
    cout<<"\n\nRoll NO.\tCourses";
    while(s!='\0')
    {
    	rnode *q;
    	cout<<"\n"<<s->u.rno<<"\t: ";
    	q=s->next;
    	while(q->next!=s)
    	{
    	    rnode *p;
    	    p=q;
    	       while(p->u.cno==0)
    	       p=p->down;
    	       cout<<p->u.cno<<"\t";
    	    q=q->next;
        }
        while(q->u.cno==0)
        q=q->down;
        cout<<q->u.cno<<"\t";
        s=s->down;
    }
    return 0;
}

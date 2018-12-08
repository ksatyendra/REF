#include<iostream>
using namespace std;
struct rnode;
struct snode;
struct cnode;
union union1
{
    rnode *next;
	snode *end;
};
union union2
{
	rnode *down;
	cnode *lowest;
};
struct rnode
{
	union1 u1;
	int tag2;
	union2 u2;
};
struct snode
{
	int rno;
	rnode *next;
	snode *sdown;
};
struct cnode
{
	int cno;
	rnode *down;
	cnode *cnext;
};


int main()
{
	int nc,ns,rno,n,i=0;
	cout<<"Enter Number of student : ";
	cin>>ns;
	cout<<"Enter Number of Courses : ";
	cin>>nc;
	snode *s='\0';
	cnode *c='\0';
	rnode *r='\0';
	int a[nc];
    for(int j=0;j<ns;j++)
	{
		snode *t1;
		t1=new snode;
		cout<<"Enter Student Roll No. : ";
		cin>>t1->rno;
		t1->sdown='\0';
		t1->next='\0';
		if(s=='\0')
		 s=t1;
		else
		{
			snode *s1=s;
			while(s1->sdown!='\0')
			s1=s1->sdown;
			s1->sdown=t1;
		}
    }
	for(int j=0;j<nc;j++)
	{
		cnode *t2;
		t2=new cnode;
		cout<<"Enter Courses Number : ";
		cin>>t2->cno;
		t2->down='\0';
		t2->cnext='\0';
		if(c=='\0')
		c=t2;
		else
		{
			cnode *c1=c;
			while(c->cnext!='\0')
			c=c->cnext;
			c->cnext=t2;
			c=c1;
		}
    }
    cnode *c2=c;
    snode *s2=s;
    while(s!='\0')
	{
		int m,k=0;
		cout<<"Enter No of registered courses for Roll No. : "<<s->rno<<"\n";
		cin>>n;
		 for(i=0;i<n;i++)
		 {
		 	c=c2;
		 	cout<<"Enter courses No. : ";
		 	cin>>m;
			while(c->cno!=m)
			c=c->cnext;
			rnode *t;
			t=new rnode;
			t->tag2=1;
			t->u1.next='\0';
			t->u2.down='\0';
			if(r=='\0'&&i!=n-1)
			{
				r=t;
				s->next=t;
				if(c->down=='\0')
				    {
				    	c->down=t;
				    }
				else
				{
					rnode *q=c->down;
					while(q->u2.down!='\0')
					q=q->u2.down;
					q->u2.down=t;
				}
			}
			else if(i!=n-1)
			{
		     	r->u1.next=t;
				if(c->down=='\0')
				    {
		     	    	c->down=t;
				    }
				else
				{
					rnode *q=c->down;
					while(q->u2.down!='\0')
					q=q->u2.down;
					q->u2.down=t;
				}
				r=t;
			}
			else if(i==n-1)
			{
			    if(r!='\0')
			    r->u1.next=t;
			    else
			    {
			    	r=s->next=t;
			    }
			    if(c->down=='\0')
				    {
		     	    	c->down=t;
				    }
				else
				{
					rnode *q=c->down;
					while(q->u2.down!='\0')
					q=q->u2.down;
					q->u2.down=t;
				}
				t->u1.end=s;
				s=s->sdown;
				r='\0';
			}
		 }
    }
    s=s2;
    c=c2;
    while(c!='\0')
    {
    	rnode *q;
    	q=c->down;
    	while(q&&q->u2.down!='\0')
    	{
    	 q=q->u2.down;
        }
    	q->u2.lowest=c;
    	q->tag2=0;
    	c=c->cnext;
    }
    c=c2;
    cout<<"\n\nRoll NO.\tCourses";
    while(s!='\0')
    {
    	rnode *q;
    	cout<<"\n"<<s->rno<<"\t: ";
    	q=s->next;
    	while(q->u1.end!=s)
    	{
    	    rnode *p;
    	    p=q;
    	       while(p->tag2!=0)
    	       p=p->u2.down;
    	       cout<<p->u2.lowest->cno<<"\t";
    	    q=q->u1.next;
        }
        while(q->tag2!=0)
        q=q->u2.down;
        cout<<q->u2.lowest->cno<<"\t";
        s=s->sdown;
    }
    return 0;
}



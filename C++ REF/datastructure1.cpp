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
};
struct cnode
{
	int cno;
	rnode *down;
};


int main()
{
	int nc,ns,rno,n,i=0;
	cout<<"Enter Number of student : ";
	cin>>ns;
	cout<<"Enter Number of Courses : ";
	cin>>nc;
	snode *s[ns];
	cnode *c[nc],*c1[nc];
	rnode *r[100];
    for(int j=0;j<ns;j++)
	{
		s[j]=new snode;
		cout<<"Enter Student Roll No. : ";
		cin>>s[j]->rno;
		s[j]->next='\0';
    }
	for(int j=0;j<nc;j++)
	{
		c[j]=new cnode;
		cout<<"Enter Courses Number : ";
		cin>>c[j]->cno;
		c[j]->down='\0';
    }
    for(int j=0;j<ns;j++)
	{
		int m,k=0;
		r[j]='\0';
		cout<<"Enter No of registered courses for Roll No. : "<<s[j]->rno<<"\n";
		cin>>n;
		 for(i=0;i<n;i++)
		 {
		 	k=0;
		 	cout<<"Enter courses No. : ";
		 	cin>>m;
		    while(c[k]->cno!=m&&k<nc)
			k++;
			rnode *t;
			t=new rnode;
			t->tag2=1;
			t->u1.next='\0';
			t->u2.down='\0';
			if(r[j]=='\0'&&i!=n-1)
			{
				r[j]=t;
				s[j]->next=t;
				if(c[k]->down=='\0')
				    {
				    	c[k]->down=t;
				    }
				else
				{
					rnode *q=c[k]->down;
					while(q->u2.down!='\0')
					q=q->u2.down;
					q->u2.down=t;
				}
			}
			else if(i!=n-1)
			{
		     	r[j]->u1.next=t;
				if(c[k]->down=='\0')
				    {
		     	    	c[k]->down=t;
				    }
				else
				{
					rnode *q=c[k]->down;
					while(q->u2.down!='\0')
					q=q->u2.down;
					q->u2.down=t;
				}
				r[j]=t;
			}
			else if(i==n-1)
			{
			    if(r[j]!='\0')
			    r[j]->u1.next=t;
			    else
			    {
			    	r[j]=s[j]->next=t;
			    }
			    if(c[k]->down=='\0')
				    {
		     	    	c[k]->down=t;
				    }
				else
				{
					rnode *q=c[k]->down;
					while(q->u2.down!='\0')
					q=q->u2.down;
					q->u2.down=t;
				}
				t->u1.end=s[j];
			}
		 }
    }

    for(i=0;i<nc;i++)
    {
    	rnode *q;
    	q=c[i]->down;
    	while(q&&q->u2.down!='\0')
    	{
    	 q=q->u2.down;
        }
    	q->u2.lowest=c[i];
    	q->tag2=0;
    }

    cout<<"\n\nRoll NO.\tCourses";
    for(i=0;i<ns;i++)
    {
    	rnode *q;
    	cout<<"\n"<<s[i]->rno<<"\t: ";
    	q=s[i]->next;
    	while(q->u1.end!=s[i])
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
    }
    return 0;
}



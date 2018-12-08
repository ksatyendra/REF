#include<iostream>
#include<string.h>
class B2Node
{
	int count;
	int elem[4];
	B2Node *b2[5];
	friend class B2Tree;
	public:
		B2Node();
};
B2Node::B2Node()
{
	count=0;
   for(int i=0;i<4;i++)
   {
   	elem[i]=99999999;
   	b2[i]=NULL;
   }
   b2[4]=NULL;
}
class B2Tree
{
	B2Node *root;
	public:
		B2Tree()
		{
			root=NULL;
		}
		void insertion(int);
		void display();
		void display(B2Node *);
		void indis(B2Node *);
		void disk(B2Node *);
		void add(int,B2Node *,B2Node *);
		void insert(int,B2Node *,B2Node *);
		int redist(B2Node *,int);
		void overflow(int,B2Node *,B2Node *);
		int split(int,B2Node *,B2Node *,B2Node *&);
		void left_shift(int,B2Node *);
		void remove(int ch);
		void underflow(B2Node *t);
		void combine(int,B2Node *);
		B2Node* search(int);
		void search_node(int,B2Node *,B2Node *&);
		B2Node* get_parent(int,B2Node *);
		void search_node(B2Node *,int &i);

};
void dis(int i)
{
	cout<<"\n dis is : "<<i<<flush;
}
void B2Tree::disk(B2Node *t)
{
	if(t==NULL)
	{
		cout<<"\n NULL in disk ";
		return;
	}
	cout<<"\n in disk";
	for(int i=0;i<4;i++)
		cout<<"   "<<t->elem[i]<<flush;
}
void ge()
{
	char ch;
	cout<<"\n press enter ";
	cin.get(ch);
}
void B2Tree::insertion(int ch)
{
	B2Node *p=NULL;
	search_node(ch,root,p);
	if(p==NULL)
	{
		p=new B2Node;
		root=p;
	}
	add(ch,NULL,p);
}
void B2Tree::search_node(int ch,B2Node *q,B2Node *&p)
{
	if(q==NULL)
		return;
	int i=0;
	p=q;
	while(i<4&&q->elem[i]<ch)
		i++;
	search_node(ch,q->b2[i],p);
}
void B2Tree::insert(int l,B2Node *q,B2Node *p)
{
	int i=0;
	while(p->elem[i]!=99999999)
		i++;
	while(i>0&&p->elem[i-1]>l)
	{
		p->elem[i]=p->elem[i-1];
		p->b2[i+1]=p->b2[i];
		i--;
	}
	p->elem[i]=l;
	p->b2[i+1]=q;
	p->count++;
}
B2Node* B2Tree::get_parent(int ch,B2Node *t)
{
	int i;
	if(t==root)
		return root;
	B2Node *k=root;
	while(k!=NULL)
	{
		for(i=0;i<5;i++)
			if(k->b2[i]==t)
				return k;
		i=0;
		while(i<4&&k->elem[i]<ch)
			i++;
		k=k->b2[i];
	}
   return NULL;
}
void B2Tree::add(int ch,B2Node *q,B2Node *p)
{
	if(p->count<4)
		insert(ch,q,p);
	else
		overflow(ch,q,p);
}
void B2Tree::overflow(int ch,B2Node *q,B2Node *p)
{
	B2Node *r,*m;
	int fl=0;
	if(p!=root&&p->b2[0]==NULL)
		fl=redist(p,ch);
	if(fl)
		return;
	int mid=split(ch,q,p,m);
	if(p==root)
	{
		B2Node *k=new B2Node;
		k->b2[0]=p;
		k->b2[1]=m;
		k->elem[0]=mid;
		k->count=1;
		root=k;
	}
	else
	{
		r=get_parent(ch,p);
		add(mid,m,r);
	}
}
void left_shift(int,int[]);
int max(int a,int b)
{
	if(a>b)
		return a;
	else
	 	return b;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int B2Tree::redist(B2Node *p,int ch)
{
	B2Node *r=get_parent(ch,p);
	int l=0,flag=0;
	while(r->b2[l]!=p)
		++l;
	B2Node *k=r->b2[l+1];;
	if(l>0&&r->b2[l-1]->count<4)
	{
		flag=1;
		insert(r->elem[l-1],NULL,r->b2[l-1]);
		r->elem[l-1]=min(p->elem[0],ch);
		if(r->elem[l-1]!=ch)
		{
			left_shift(0,p);
			insert(ch,NULL,p);
		}
	}
	else if(l<4&&k!=NULL&&k->count<4)
	{
		flag=1;
		insert(r->elem[l],NULL,k);
		r->elem[l]=max(p->elem[3],ch);
		ch=min(p->elem[3],ch);
		p->elem[3]=99999999;
		insert(ch,NULL,p);
	}
	return flag;
}
void B2Tree::left_shift(int i,B2Node *p)
{
	while(i<3)
	{
		p->elem[i]=p->elem[i+1];
		p->b2[i+1]=p->b2[i+2];
		i++;
	}
	p->elem[3]=99999999;
	p->b2[4]=NULL;
}
int B2Tree::split(int ch,B2Node *q,B2Node *p,B2Node *&m)
{
	int a[5],i;
	B2Node *b[6];
	m=new B2Node;
	for(i=0;i<4;i++)
	{
		a[i]=p->elem[i];
		b[i]=p->b2[i];
	}
	b[i]=p->b2[i];
	while(i>0&&a[i-1]>ch)
	{
		a[i]=a[i-1];
		b[i+1]=b[i];
		i--;
	}
	a[i]=ch;
	b[i+1]=q;
	m->elem[0]=a[3];
	m->b2[0]=b[3];
	m->elem[1]=a[4];
	m->b2[1]=b[4];
	m->b2[2]=b[5];
	p->elem[0]=a[0];
	p->b2[0]=b[0];
	p->elem[1]=a[1];
	p->b2[1]=b[1];
	p->b2[2]=b[2];
	p->elem[2]=99999999;
	p->elem[3]=99999999;
	p->b2[3]=NULL;
	p->b2[4]=NULL;
	p->count=2;
	m->count=2;
	return a[2];
}
void B2Tree::remove(int ch)
{
	int i=0,j;
	B2Node *p=search(ch);
	if(p==NULL)
	{
		cout<<"\n This element is not present ";
		return;
	}
	while(p->elem[i]!=ch)
		i++;
	if(p->b2[0]==NULL)
		left_shift(i,p);
	else
	{
		//dis(1);
		B2Node *q=p->b2[i];
		while(q->b2[0]!=NULL)
			q=q->b2[q->count];
		j=q->count-1;
		p->elem[i]=q->elem[j];
		q->elem[j]=99999999;
		p=q;
		//dis(2);
	}
	p->count--;
	if(p->count<2)
		underflow(p);
	//dis(100);
	cout<<"\n "<<ch<<" has been Removed from the Tree ";
}
void B2Tree::underflow(B2Node *p)
{
	//dis(3);
	int l=0,k=0,flag=1;
  	B2Node *r;
	if(p==root)
	{disk(root);
		if(p->count==0)
		{
			root=p->b2[0];
			disk(root);
			delete p;
		}
		return;
	}
	else if(p->b2[0]==NULL)
	{
		//dis(4);
		r=get_parent(p->elem[0],p);dis(41);
		while(r->b2[l]!=p)
			l++;
		B2Node *q=r->b2[l+1];
		cout<<"\n l is : "<<l;
		disk(q);
		//dis(42);
		if(l>0&&r->b2[l-1]->count>2)
		{
			flag=0;
			insert(r->elem[l-1],NULL,p);
			k=--(r->b2[l-1]->count);
			r->elem[l-1]=r->b2[l-1]->elem[k];
			r->b2[l-1]->elem[k]=99999999;
		}
		else if(l<4&&q!=NULL&&q->count>2)
		{
			flag=0;
			insert(r->elem[l],NULL,p);
			r->elem[l]=r->b2[l+1]->elem[0];
			left_shift(0,r->b2[l+1]);
			r->b2[l+1]->count--;
		}
	}
	if(flag)
	{
		//dis(5);
		r=get_parent(p->elem[0],p);
		l=0;
		while(r->b2[l]!=p)
			l++;
		if(r->b2[l+1]!=NULL)
		{	combine(l,r);dis(6);}
		else
		{	combine(l-1,r);dis(7);}
		if(r->count<2)
		{//dis(200);
			underflow(r);}
		//dis(8);
	}
}
void B2Tree::combine(int x,B2Node *r)
{
	int i=r->b2[x]->count;
	r->b2[x]->elem[i++]=r->elem[x];
	r->b2[x]->b2[i]=r->b2[x+1]->b2[0];
	r->b2[x]->elem[i++]=r->b2[x+1]->elem[0];
	r->b2[x]->b2[i]=r->b2[x+1]->b2[1];dis(9);
	if(i==3)
	{dis(10);
		r->b2[x]->elem[i++]=r->b2[x+1]->elem[1];
		r->b2[x]->b2[i]=r->b2[x+1]->b2[2];
	}dis(11);
	r->b2[x]->count=4;
	delete r->b2[x+1];
	r->b2[x+1]=NULL;
	disk(r->b2[x]);
	left_shift(x,r);dis(12);
	r->count--;
}
B2Node* B2Tree::search(int ch)
{
	B2Node *t=root;
	while(t!=NULL)
	{
		int i=0;
		while(t->elem[i]<ch)
			i++;
		if(t->elem[i]==ch)
			break;
		t=t->b2[i];
	}
	return t;
}
void find(int ch,B2Tree &b)
{
	B2Node *t=b.search(ch);
	if(t==NULL)
		cout<<"\n Such An Element is Not Present ";
	else
		cout<<"\n "<<ch<<" is Present in the Tree ";
}
void B2Tree::display()
{
	indis(root);
}
void B2Tree::display(B2Node *t)
{
	if(t==NULL)
		return;
	int i=0;
	for(;i<4;i++)
	{
		display(t->b2[i]);
		cout<<"   "<<t->elem[i]<<flush;
	}
	display(t->b2[i]);
}
void B2Tree::indis(B2Node *t)
{
	if(t==NULL)
		return;
	int i=0;
	cout<<"\n";
	for(int j=0;j<4;j++)
		if(t->elem[j]!=99999999)
			cout<<"    "<<t->elem[j]<<flush;
	for(;i<5;i++)
		indis(t->b2[i]);
}
main()
{
	int ch,x;
	B2Tree bt;
	do
	{
		cout<<"\n\n\t\t * * * MENU * * * "
		    <<"\n\t\t1.Insert  into  Tree "
		    <<"\n\t\t2.Delete An Element "
		    <<"\n\t\t3.Search for An Element "
		    <<"\n\t\t4.Display contents of Tree "
		    <<"\n\t\t5.Exit"
		    <<"\n\t\tEnter Your Choice (1-5) : ";
		cin>>ch;
		switch(ch)
		{
		case 1 :cout<<"\n Enter the Number : ";
			cin>>x;
			bt.insertion(x);
			break;
		case 2 :cout<<"\n Enter the Element ";
			cin>>x;
			bt.remove(x);
			break;
		case 3 :cout<<"\n Enter the Element to be Searched ";
			cin>>x;
			find(x,bt);
			break;
		case 4 :cout<<"\n The Tree Content's are : \n";
			bt.display();
			break;
		case 5 :cout<<"\n Thank You \n";
			break;
		default:cout<<"\n Wrong Choice ";
			break;
		}
	}while(ch!=5);
}



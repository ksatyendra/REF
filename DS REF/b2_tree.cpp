
#include<iostream.h>
#include<conio.h>
class b2tree;
class b2node
{
	int data[4];
   b2node* link[5];
   int count;
   b2node();
   friend class b2tree;
};
b2node::b2node()
{
	for(int i=0;i<4;i++)
   {
   	data[i]=0;
      link[i]=NULL;
   }
   link[4]=NULL;
   count=0;
}
class b2tree
{
	b2node* root;
   void insert(b2node* &t,int x);
   void insertion(b2node* &t,b2node* t1,int x);
   void nodesplit(b2node* &t,int x);
   void sort(int x[]);
   b2node* getparent(b2node* &t,int ch);
   int check(b2node* t,int x);
   void display(b2node* &t);
   void shift(b2node* &t,int &x);
   public:
   	b2tree();
   	void insert(int x);
      void display();

};
b2tree::b2tree()
{
	root=NULL;
}
void b2tree::display()
{
	display(root);
}
void b2tree::display(b2node* &t)
{
	if(t!=NULL)
   {
   	for(int i=0;i<5;i++)
      {
      	 if(t)
         	display(t->link[i]);
      	if(t->data[i])
         	cout<<t->data[i]<<" ";

      }
	}
   else
   	return;
}
void b2tree::insert(int x)
{
	insert(root,x);
}
void b2tree::insert(b2node*&t,int x)
{
	if(t==NULL)
   {
   	t=new b2node;
      t->data[0]=x;
      t->count++;
   }
   else
   {
   	if(x<t->data[0] && t->link[0]!=NULL)
      	insert(t->link[0],x);
      else if(x>t->data[0] && x<t->data[1] && t->link[1]!=NULL)
      	insert(t->link[1],x);
      else if(x>t->data[1] && x<t->data[2] && t->link[2]!=NULL)
      	insert(t->link[2],x);
      else if(x>t->data[2] && x<t->data[3] && t->link[3]!=NULL)
      	insert(t->link[3],x);
      else if(x>t->data[3]  && t->link[4]!=NULL)
      	insert(t->link[4],x);
      else
      	insertion(t,NULL,x);
	}
}
void b2tree::insertion(b2node* &t,b2node* t1,int x)
{
   int i=0;
   if(t->count<4)
   {
   	while(t->data[i]!=0)
   		i++;
   	while(i>0 && t->data[i]>x)
   	{
   		t->data[i]=t->data[i-1];
      	t->link[i+1]=t->link[i];
      	i--;
   	}
   	t->data[i]=x;
   	t->link[i+1]=t1;
   	t->count++;
   }
   else
   	nodesplit(t,x);
}
void b2tree::shift(b2node* &t,int &x)
{
	int a[5];
	for(int i=0;i<4;i++)
   	a[i]=t->data[i];
	a[4]=x;
   sort(a);
   x=a[2];
   t->data[0]=a[0];
   t->data[1]=a[1];
   t->data[2]=a[3];
   t->data[3]=a[4];
}
void b2tree::nodesplit(b2node* &t,int x)
{
	shift(t,x);
	b2node* t1=new b2node;
   t1->data[0]=t->data[2];
   t1->link[0]=t->link[2];
   t1->data[1]=t->data[3];
   t1->link[1]=t->link[3];
   t1->link[2]=t->link[4];
   b2node* p=getparent(t,t->data[0]);
	if(p==NULL)
   {
     	p=new b2node;
      p->data[0]=x;
      p->link[0]=t;
      p->link[1]=t1;
      p->count++;
      root=p;
   }
   else
   	insertion(p,t1,x);
   t->data[2]=0;
   t->data[3]=0;
}
template<class etype>
void swap(etype& x,etype& y)
{
	etype temp;
   temp=x;
   x=y;
   y=temp;
}
void b2tree::sort(int x[5])
{
	 int min=0,j;
    for(int i=0;i<5;i++)
    {
		for(j=i;j<5;j++)
      	if(x[min]>x[j])
         		min=j;
         swap(x[i],x[min]);
      
    }
}
typedef b2node* ptr;
ptr b2tree::getparent(b2node* &t,int ch)
{
	int i;
	if(t==root)
		return NULL;
	b2node *k=root;
	while(k!=NULL)
	{
		for(i=0;i<5;i++)
			if(k->link[i]==t)
				return k;
		i=0;
		while(i<4&&k->data[i]<ch)
			i++;
		k=k->link[i];
	}
   return NULL;
}

int b2tree::check(b2node* t,int x)
{
	for(int i=0;i<4;i++)
   	if(t->data[i]==x)
      	return 1;
   return 0;
}
int main()
{
	b2tree t;
   int n;
   do
   {
   	cout<<"\nenter the data:";
      cin>>n;
      t.insert(n);
      cout<<"\ndo u want to continue:";
      cin>>n;
   }while(n);
   t.display();
	getch();
	return 0;
}








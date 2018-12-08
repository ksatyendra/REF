#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
struct node
{
	int data;
	node *next;
	node* *n;
};
void add(node* &l,int k)
{
 if(l==NULL)
 {
     l=(new node);
     l->data=k;
     l->next=NULL;
     l->n=NULL;
 
 }
 else
 {
     while(l->next!=NULL)
     l=l->next;
     l->next=new (node);
     l->next->data=k;
     l->next->next=NULL;
     l->next->n=NULL;
 }
}
void print_list(node* l)
{
    cout<<"The list contains:";
    while(l!=NULL)
    {
        cout<<l->data<<" ";
        l=l->next;
    }
    cout<<endl;
}
node* location(node *l,int k)
{
	for(int i=1;i<k && l!=NULL;i++)
	l=l->next;
	return (l);
}
void create(node *t,int size)
{	//cout<<"t->data="<<t->data<<endl;
	if(size==0)
	{
	  t->n=new node*[1];
      t->n[0]=NULL;
      return;
    }
	int s=floor((log(size)/log(2)));
	//cout<<"s="<<s;
	t->n=new node*[s+1];
	int temp_size=size;
	for(int i=0;temp_size>0&&i<s;i++)
	{
		t->n[i]=location(t,ceil(temp_size/2));
		//cout<<"n[]="<<t->n[i]->data<<endl;
		temp_size/=2;
	}
	t->n[s]=NULL;
	for(int i=0;i<s-1;i++)
	{
	create(t->n[i],size/2);
	size/=2;
	}
}
bool search(node *t,int k)
{	
	int i;
	
	if(t->n==NULL||t->next==NULL)
	{
		if(t->data==k) return true;
		return false;
	}
	for(i=0;t->n[i]!=NULL;)
	{
	if(t->data==k)
	return true;
	if(t->n[i]->data==k)
	return true;
	if(t->n[i]->data<k)
	return(search(t->n[i],k));
	else
	i++;
	}
	if(t->n[i]==NULL)
	if(k==t->next->data)
	return true;
	else
	return false;
}
void print_list2(node* l,ofstream &out)
{
    //cout<<"The list contains:";
    while(l!=NULL)
    {
        out<<l->data<<" :: ";
        if(l->n==NULL)
        {
			l=l->next;
			out<<endl;
			continue;
		}
        for(int i=0;l->n[i]!=NULL;i++)
        out<<l->n[i]->data<<" , ";
        out<<endl;
        l=l->next;
    }
}
int main()
{
//	cout<<"Enter the numbers in the list and add -1 at the end: ";
	int n,count=0,i;
	node *t=NULL,*head=NULL;
	ofstream of("file.txt");
	for(i=1;i<=100;i++)
	of<<i<<" ";
	of.close();
	ifstream in("file.txt");
	in>>n;
	while(!in.eof())
	{
		
        if(t==NULL)
        {add(t,n);
        count++;
        head=t;
        }
        else
        {add(t,n);count++;}
        in>>n;
	}
//	print_list(head);
	in.close();
	ofstream outstream("skiplist.txt");
	create(head,count);
	print_list2(head,outstream);
	outstream.close();
	int k;
	for(int i=0;i<50;i++)
	{
	//cout<<"enter the element to be searched : ";
    //cin>>k;
	if(search(head,i))
	cout<<i<<" FOUND!!!!!!!!!!!!!!!!\n";
	else
	cout<<i<<" NOT FOUND!!!!!!!!!!!!!!!\n";
	}
	return 0;
}

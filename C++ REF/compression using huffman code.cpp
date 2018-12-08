#include<iostream>
#include<fstream>
#include"queuetemplate.cpp"
using namespace std;
struct data
{
	char c;
	int freq;
};
struct node
{
	data d;
	node *left;
	node *right;
	node();
};
node::node()
{
	left=right=NULL;
}
void print_level_order(node *root)
{	if(root==NULL)
	return;
	queue<node*> q(20);
	node *temp;
	q.enqueue(root);
	q.enqueue(NULL);
	
	while(!q.empty())
	{
		temp=q.dequeue();
		if(temp!=NULL)
		{
		cout<<(temp->d).c<<(temp->d).freq<<" ";
		if(temp->left!=NULL) q.enqueue(temp->left);
		if(temp->right!=NULL) q.enqueue(temp->right);
		}
		else
		 if (!q.empty())
            {	cout<<endl;
				q.enqueue(NULL);
			}
             
              
	}
}
void selection_sort(node** &s,int n)
{
	int i,j,min,pos;
	for(i=0;i<n-1;i++)//arranges the array in descending order
    {
    	    min=(s[i]->d).freq;
			for(j=i+1;j<n;j++)
        	{
                    if((s[j]->d).freq>min)
					{
                       min=(s[j]->d).freq;          
                       pos=j;
                       swap(s[i],s[pos]);
                     }
                                        
		    }
	
	}
}
void create_tree(node* &b,node** &s,int size)
{
	if(size==1)
	return;
	else
	{
		node *t=new node;
		b=t;
		t->left=s[size-1];
		t->right=s[size-2];
		(t->d).c='T';
		(t->d).freq=(s[size-1]->d).freq+(s[size-2]->d).freq;
		size--;
		s[size-1]=t;
		selection_sort(s,size);
		create_tree(b,s,size);
			
	}
}
string code(node* b,char ch,string s)
{
	string s1,s2;
	if((b->d).c!='T')
	{
	if((b->d).c==ch)
	return s;
	else
	return "";
	}
	s1=code(b->left,ch,s+'0');
	s2=code(b->right,ch,s+'1');
	if(s1!="")
	return s1;
	if(s2!="")
	return s2;
	return "";	
}

int main()
{
	char ch,*file;
	file=new char[10];
	int i,n=0,no_freq,array[256];
	for(i=0;i<256;i++)
	array[i]=0;
	//cout<<"Enter filename: ";
	//cin>>file;
	ifstream in("datafile.txt");
	in.get(ch);
	while(!in.eof())
	{
	int x=(int)ch;
//	cout<<ch<<" "<<x<<endl;
	array[x]++;
	in.get(ch);
	}
	in.close();
	for(i=0;i<256;i++)
	{
		if(array[i]!=0)
		n++;	
	}
	data s[n];
	for(int j=0,i=0;j<256;j++)
	{
		if(array[j]!=0)
		{
			s[i].c=(char)j;
			s[i].freq=array[j];
			i++;
		}
	}
	node **tree=new node*[n];
	for(i=0;i<n;i++)
	{
		tree[i]=new node;
		(tree[i]->d).c=s[i].c;
		(tree[i]->d).freq=s[i].freq;
	}
	selection_sort(tree,n);
	node *huftree=NULL;
	int size=n;
	create_tree(huftree,tree,n);
	print_level_order(huftree);
	string st;
	ofstream out("compressedfile.bin",ios::binary);
	ifstream input("datafile.txt");
	input.get(ch);
	while(!input.eof())
	{
	out<<(code(huftree,ch,st));
	input.get(ch);
	st="";
	}	
	input.close();
	out.close();

}

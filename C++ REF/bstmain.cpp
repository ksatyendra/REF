#include<iostream>
#include"bstheader.cpp"
#include<cstdlib>
using namespace std;
int main()
{
    int flag,num,i,pos,choice;
    bstnode *m=NULL,*n=NULL,*tree=NULL;
     /*cout<<"Menu:\n";
    cout<<"1.Insert\n2.Delete\n3.Display Pre Order\n4.Findmax\n5.Findmin\n6.Find a number\n7.Print level order\n8.Exit\n9.Print like Tree\n10.Height\n";
   while(1)
    {
    cout<<"Enter your choice: ";
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter element: ";
        cin>>num;
        if(m==NULL)
        {insert(m,num);
        n=m;
        }
        else
        insert(m,num);
    }
    if(choice==2)
    {
        cout<<"Enter element to be deleted: ";
        cin>>num;
        delete_node(n,num);
    }
    if(choice==3)
    {
        inorder(n);
        cout<<endl;
    }
     if(choice==4)
     {
			cout<<"The maximum number is: "<<findmax(n)<<endl;
     }
      if(choice==5)
      {
         cout<<"The minimum number is: "<< findmin(n)<<endl;
      }
    if(choice==6)
    {
		cout<<"Enter element to be searched: ";
    	cin>>num;
		find(n,num);
	}
    if(choice==7)
    print_level_order(n);
	if(choice==8)
    exit(1);
    if(choice==9)
    {print_like_tree(n);
    spaces_id(n);}
    if(choice==10)
    cout<<"The height of root node is " <<height(n)<<endl;
    if(choice==11)
    balanced_tree(n);
	}
	*/
	cout<<"ENter the numbers";
	cin>>num;
	while(num!=-1)
	{
		insert(tree,num);
		cin>>num;
		}
		cout<<"Enter x: ";
		cin>>num;
		
	m=new bstnode;
	m->data=num;
	m->lchild=NULL;
	m->rchild=NULL;
	n=new bstnode;
	n->data=num;
	n->lchild=NULL;
	n->rchild=NULL;
//	inorder(tree);

	cout<<endl;
	bstnode* temp1=m;
	bstnode *temp2=n;
	construct(tree,m,n);
	
	inorder(temp1);
	cout<<endl;
	inorder(temp2);
	
  return 0;
}

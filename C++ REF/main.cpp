#include<iostream>
#include"binarytreeheader.cpp"
#include<cstdlib>
using namespace std;
int main()
{
    int flag,num,i=0,pos,choice;
    char c;
    btnode *m=NULL,*n=NULL;
    cout<<"Menu:\n";
    cout<<"1.Insert\n2.Print Inorder Iterative\n3.Print Postorder Iterative"
	<<"\n4.Print Postorder\n5.Print Inorder\n6.Print preorder\n7.Print Preorder iterative\n8.exit\n9.Print\n";
	while(1)
    {
    cout<<"Enter your choice: ";
    cin>>choice;
    if(choice==1)
    {	if(i==0)
    	{cout<<"Enter root node value: ";
    	cin>>c;
		i++;}
    	else
        {cout<<"Enter element: ";
        cin>>c;}
        if(m==NULL)
        {insert(m,c);
        n=m;
        }
        else
        insert(m,c);
    }
    if(choice==5)
    //print_level_order(n);
    inorder(n);
    if(choice==6)
    preorder(n);
	if(choice==7)
    print_preorder(n);
    if(choice==8)
	exit(1);
	if(choice==2)
	print_inorder(n);
	if(choice==3)
	print_postorder(n);
	if(choice==4)
	postorder(n);
	if(choice==9)
	{
    cout<<"Enter traversal : 1-Inorder\n2-Preorder\n3-Postorder\n";
    cin>>num;
    switch(num)
    {
      case 1:printf(n,1,0,0);break;
      case 2:printf(n,0,1,0);break;
      case 3:printf(n,0,0,1);break;
    }
  }
    }
  return 0;
}

#include<iostream>
#include"binarysearchtree.cpp"
#include<cstdlib>
using namespace std;
int main()
{
    int flag,num,i,pos,choice;
    bstnode *m=NULL,*n=NULL;
    cout<<"Menu:\n";
    cout<<"1.Insert\n2.Delete\n3.Display Pre Order\n4.Findmax\n5.Findmin\n6.Find a number\n7.Print level order\n8.Exit\n";
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
    }
  return 0;
}

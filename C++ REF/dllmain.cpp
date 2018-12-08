#include<iostream>
#include"doublylinkedlist.cpp"
#include<cstdlib>
using namespace std;
int main()
{
    int flag,num,i,pos,choice;
    dnode *m=NULL,*n=NULL;cout<<"Menu:\n";
    cout<<"1.Add\n2.Delete\n3.Display\n4.Search\n5.Sort\n6.Count\n7.Exit\n8.Insert\n";
    while(1)
    {
        cout<<"Enter your choice: ";
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter element: ";
        cin>>num;
        if(m==NULL)
        {add(m,num);
        n=m;
        }
        else
        add(m,num);
    }
    if(choice==3)
    {
        print_list(n);
    }
    if(choice==2)
    {
        cout<<"Enter element to be deleted: ";
        cin>>num;
        delete_element(n,num);
    }

     if(choice==8)
     {
         cout<<"Enter element to be inserted and position: ";
        cin>>num>>pos;
        //i=search(n,num);
        insert(n,pos,num);
     }

      if(choice==5)
      {
          bubble_sort(n,count(n));
      }
       if(choice==6)
       cout<<"The number of elements is: "<<count(n);
       if(choice==7)
       exit(1);
       if(choice==9)
       {
       reverse_print(n);
       n=d;}
	//print_reverse(n);
    }
  return 0;

}

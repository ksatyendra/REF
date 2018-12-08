#include<iostream>
#include"linkedlist.cpp"
#include<cstdlib>
using namespace std;
int main()
{
    int flag,num,i,pos,choice;
    node *m=NULL,*n=NULL,*p=NULL,*q=NULL;
    /*cout<<"Enter the elements and add -1 at the end: ";
    while(1)
    {
        //cout<<"Enter element: ";
        cin>>num;
        if(num==-1) break;
        if(m==NULL)
        {add(m,num);
        n=m;
        }
        else
        add(m,num);
    }

    cout<<"Delete-Press 1 or 0: ";
    cin>>flag;
    if(flag==1)
    {
        cout<<"Enter element: ";
        cin>>num;
        delete_element(n,num);
    }
    cout<<"Search-Press 1 or 0: ";
    cin>>flag;
    if(flag==1)
    {
        cout<<"Enter element: ";
        cin>>num;
        i=search(n,num);
    }
    cout<<"Display-Press 1 or 0: ";
    cin>>flag;
    if(flag==1)
    print_list(n);

    cout<<"Insert-Press 1 or 0";
    cin>>flag;
    if(flag==1)
    {cout<<"Enter element and position: ";
        cin>>num>>pos;
        insert(n,pos,num);
    }
    print_list(n);
    */
    cout<<"Menu:\n";
    cout<<"1.Add\n2.Delete\n3.Display\n4.Search\n5.Sort\n6.Count\n7.Exit\n";
    while(1)
    {
        cout<<"Enter your choice: ";
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter element: ";
        cin>>num;
        if(p==NULL)
        {add(p,num);
        q=p;
        }
        else
        add(p,num);
    }
    if(choice==2)
    {
        cout<<"Enter element to be deleted: ";
        cin>>num;
        delete_element(q,num);
    }
    if(choice==3)
    {
        print_list(q);
    }
     if(choice==4)
     {
         cout<<"Enter element: ";
        cin>>num;
        //i=search(n,num);
        i=search_recursive(q,num);
     }
      if(choice==5)
      {
          bubble_sort(q,count(q));
      }
       if(choice==6)
       cout<<"The number of elements is: "<<count(q);
       if(choice==7)
       //exit(1);
       break;
    }
    cout<<"Menu:\n";
    cout<<"1.Add\n2.Delete\n3.Display\n4.Search\n5.Sort\n6.Count\n7.Exit\n";
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
    if(choice==2)
    {
        cout<<"Enter element to be deleted: ";
        cin>>num;
        delete_element(n,num);
    }
    if(choice==3)
    {
        print_list(n);
    }
     if(choice==4)
     {
         cout<<"Enter element: ";
        cin>>num;
        //i=search(n,num);
        i=search_recursive(n,num);
     }
      if(choice==5)
      {
          bubble_sort(n,count(n));
      }
       if(choice==6)
       cout<<"The number of elements is: "<<count(n);
       if(choice==7)
       //exit(1);
       break;
    }
    if(check_sublist(q,n))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
  return 0;
}

#include<iostream>
#include<fstream>
using namespace std;
int binary_search(int a[],int l,int u,int key)
{
    int mid;
    if(l<u)
    {
           mid=(l+u)/2;
           if(a[mid]==key)
           {
                          cout<<"number Found";
           return(1);
           }
    
    else
    if(key<a[mid])
    return(binary_search(a,l,mid-1,key));
    if(key>a[mid])
    return(binary_search(a,mid+1,u,key));
}
    return(0);

}
int linear_search(int a[],int size,int key)
{
    static int i=0;
    if(i<size)
    {
              if(a[i]==key)
              {
                           cout<<"no.found";
              return(1);
              }
              else
              {
                  i++;
                  linear_search(a,size,key);
              }
    
    }        
    return(0);
}      
           
int main()
{   int size,i,key;
    cout<<"ENTER THE NUMBERS YOU WANT TO ENTeR";
                 cin>>size;
    int a[size];
    cout<<"Enter The Numbers";
    for( i=0;i<size;i++)
    cin>>a[i];
    cout<<"Enter the number to be find";
    cin>>key;
    //binary_search(a,0,size-1,key);
    linear_search(a,size,key);
     system("pause");
    return(0);
}   

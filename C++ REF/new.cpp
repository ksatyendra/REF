#include<iostream>
#include<cstring>
using namespace std;
void readarray(int a[],int &size)
{
     cout<<"Enter The size of array";
     cin>>size;
     cout<<"Enter The ElemeNts\n";
     for(int i=0;i<size;i++)
     cin>>a[i];
}
void printarray(const int a[],int size)
{
     for(int i=0;i<size;i++)
     cout<<a[i]<<"\t";
}
void swap(int& x,int&y)
{
     int t;
     t=x;
     x=y;
     y=t;
}    
void bubblesort(int *a,int size)
{
     int i,j;
     for(i=0;i<size;i++)
         for(j=0;j<size-i-1;j++)
         if(a[j]>a[j+1])
         swap(a[j],a[j+1]);

}
int min_position(int a[],int l,int u)
{
     int p=l,min=a[l],i;
     for(i=l+1;i<u;i++)
     {
                        if(a[i]<min)
                        {
                                    min=a[i];
                                    p=i;
                        }
     }
     return(p);
}
void selectionsort(int a[],int size)
{
     int i,min_pos;
     for(i=0;i<size;i++)
     {
                        min_pos=min_position(a,i,size);
                        swap(a[i],a[min_pos]);
     }
}
int main()
{
    int *a,i,size;
cout<<"Enter size";
cin>>size;
a=new int[size];
for(i=0;i<size;i++)
cin>>a[i];
    bubblesort(a,size);
    printarray(a,size);
    
    
    system("pause");
    return(0);
}

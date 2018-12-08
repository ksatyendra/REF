#include<iostream>
#include<math.h>
#include"linkedlist.cpp"
using namespace std;
void radix_sort(int *A,int size,int d)
{

    node *r[10],*m=NULL;
    int b,i,l;
    for(i=0;i<10;i++)
    r[i]=NULL;
    for( i=0;i<d;i++)
    {   //cout<<" in ";
        for(int j=0;j<size;j++)
        {
          //  cout<<"in ";
            b=(A[j]/(int)pow(10,i))%10;
            //cout<<b;
            m=r[b];
            if(m==NULL)
            {add(m,A[i]);r[b]=m;}
            else add(m,A[i]);
        }
        for(l=0;l<size;){
        for(int k=0;k<10;k++)
        {
       // cout<<"in2 ";
        while(r[k]!=NULL)
        {
            A[l++]=r[k]->data;
            r[k]=r[k]->next;
        }
        }
        }
    }
    cout<<"Sorted Array: ";
    for(i=0;i<size;i++)
    cout<<A[i]<<" ";
}
int main()
{
    int n,i,max,c=0;
    cout<<"Enter the number of numbers to be sorted: ";
    cin>>n;
    int array[n];
    cout<<"Enter the numbers: ";
    for(i=0;i<n;i++)
    {
    cin>>array[i];
    if(i==0) max=array[i];
    if(array[i]>max)
    max=array[i];
    }
    while(max>0)
    {
        max=max/10;
        c++;
    }
     radix_sort(array,n,c);
    /*node *r[10],*m=NULL;
     for(i=0;i<10;i++)
     r[i]=NULL;
    int b,l,j;
    for( i=0;i<c;i++)
    {   //cout<<" in ";
        for(j=0;j<n;j++)
        {
            //cout<<"in ";
            b=(array[j]/(int)pow(10,i))%10;
            //cout<<b;
            m=r[b];
            if(m==NULL)
            {add(m,array[i]);r[b]=m;}
            else
            add(m,array[i]);
        }
        for(j=0;j<n;)
       {

        for(int k=0;k<10;k++)
        {
        //cout<<"in2 ";
        while(r[k]!=NULL)
        {
            array[j++]=r[k]->data;
            r[k]=r[k]->next;
        }
        }
       }
    }
    cout<<"Sorted Array: ";
    for(i=0;i<n;i++)
    cout<<array[i]<<" ";*/
    system("pause");
    return 0;

}/*
int main()
{
    node *r[10],*m=NULL;int i,n;
    for(i=0;i<10;i++)r[i]=NULL;
    cout<<"Enter size:-";
    cin>>n;
    int a[n],j,k,d,ln,max;
    cout<<"\nEnter numbers:-";
    for(i=0;i<n;i++)
    {
    cin>>a[i];
    if(i==0) max=a[i];
    else
    {if(a[i]>max)
    max=a[i];}}//cout<<"\t"<<max;
    for(ln=0;max>0;ln++)
    max=max/10;//cout<<"\t"<<ln;
    for(j=0;j<ln;j++)
    {
     for(i=0;i<n;i++)
     {//cout<<" "<<(10^j)<<" ";cout<<"  "<<(a[i]/(10^j))<<"  ";
     d=(a[i]/(int) pow(10,j))%10;//cout<<"\tremainder="<<d;
     m=r[d];
     if(m==NULL){add(m,a[i]);r[d]=m;}
     else add(m,a[i]);
     }
     for(i=0;i<n;){
     for(k=0;k<10;k++){
      while(r[k]!=NULL)
      {a[i++]=r[k]->data;//cout<<"\ta="<<r[k]->data;
       r[k]=r[k]->next;}
       }}
    }
     cout<<"\nSorted number:-";
       for(i=0;i<n;i++)
       cout<<a[i]<<" ";
//system("pause");
}
*/

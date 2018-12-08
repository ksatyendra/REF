#include<iostream>
using namespace std;
int main()
{
    int a[5],t,i,j,max;
    cout<<"Enter the marks of the students";
    for(i=0;i<5;i++)  //to obtain the bar graph of the marks obtained by students
    cin>>a[i];
    
    /*for(int i=0;i<4;i++)
    {
            for(int j=0;j<4-i;j++)
            if(a[j]>a[j+1])
            {
                           t=a[j];
                           a[j]=a[j+1];
                           a[j+1]=t;
                           }
                           }
                           
    
    */max=a[0];
     for(i=1;i<5;i++)
     {
      if(a[i]>max)
      max=a[i];
      }
      for(i=0;i<max;i++)
      {
            for(j=0;j<5;j++)
            {       
                    if(a[j]<=(i+1))
                    cout<<"*";
                    else
                    cout<<" ";
                    cout<<"\t";
            }
                    cout<<endl;
                           
      }
system("pause");
return(0);                    
}
                    
                    

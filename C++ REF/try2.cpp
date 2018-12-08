#include<iostream>
using namespace std;
int main()
{
    int a[5],t,max;
    cout<<"enter the marks of the students";
    for(int i=0;i<5;i++)  //to obtain the bar graph of the marks obtained by students
    cin>>a[i];
    
    for(int i=0;i<4;i++)
    {
            for(int j=0;j<4-i;j++)
            if(a[j]>a[j+1])
            {
                           t=a[j];
                           a[j]=a[j+1];
                           a[j+1]=t;
            }
    }
                           
    max=a[4];
    
   
    
    
            
    while(max>0)
    {
            for(int i=0;i<5;i++)
            {       
                    if(a[i]>=max)
                    cout<<"*";
                    else
                    cout<<" ";
                    cout<<"\t";
            }
            cout<<endl;
                    
    max--;
    }
    for(int i=0;i<5;i++)
    cout<<"s"<<(i+1)<<"\t";
    system("pause");
    return(0);                
   }
                    
                    

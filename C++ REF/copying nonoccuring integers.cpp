#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{   int i=0,j,k=0;
    ifstream input;
    input.open("firstfile.txt");
    ofstream output;
    output.open("mergedfile.txt");
    int num,count=0,a[50],b[50],flag=1,num2;
    input>>num;
    a[i]=num;
    while(input>>num)
    {               i++;
                    a[i]=num;
                    
    }
    count=i;
    
    for(i=0;i<=count;i++)
    cout<<a[i];
    for(i=0;i<=count;i++)
    {                    
                         for(j=i+1;j<=count;j++)
                         {
                                 if(a[j]==a[i])
                                 {flag=0;
                                 break;
                                 }
                         }
                         if(flag==1)
                         {
                                    output<<a[i]<<endl;
                                    b[k]=a[i];
                                    k++;
                         }
                         
                         flag=1;
    }
    
    ifstream input2;
    input2.open("secondfile.txt");
    while(1)
    {
            input2>>num;
            for(i=0;i<count;i++)
            {
             if(b[i]==num)
             flag=0;
            }
             if(flag!=0)
             output<<num<<endl;
             if(input2.eof())
                           break;
             flag=1;
    }
    input2.close();
    
    output.close();
    system("pause");
    return(0);
}

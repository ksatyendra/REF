#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
struct s
{
       int number;
       int count;
};
       
int main()
{
    int n,i,num,c=0,flag=1;
    ofstream output;
    output.open("integers.txt");
    cout<<"Enter the  no. of integers you want to enter: ";
    cin>>n;
    s freq[n];
    cout<<"Enter the numbers: ";
    for(i=0;i<n;i++)
    {
                    cin>>num;
                    output<<num<<endl;
    }
    for(i=0;i<n;i++)
    {
                    freq[i].number=0;
                    freq[i].count=0;
    }
    output.close();
    ifstream input;
    input.open("integers.txt");
    input>>num;
    freq[0].number=num;
    freq[0].count=1;
    i=0;
    while(input>>num)
        {           
                       for(int j=0;j<=i;j++)
                       {
                               if(freq[j].number==num)
                               {                      freq[j].number=num;
                                                      freq[j].count+=1;
                               //cout<<freq[j].count<<" ";
                               flag=0;
                               }
                       }
                       if(flag!=0)        
                           {
                           i++;
                           c++;
                           freq[i].number=num;
                           freq[i].count++;
                           cout<<freq[i].count<<" " ;
                           }
                           flag=1;
                       
    }
    for(i=0;i<=c;i++)
    {
                    if(freq[i].count>0)
                    cout<<"The frequency of integer "<<freq[i].number<<" is: "<<freq[i].count<<endl;
    }
    system("pause");
    return(0);
}      

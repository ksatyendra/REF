#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    char c;
    cout<<"Enter the string";
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
            if(s[i]>=65&&s[i]<=90)
            s[i]+=32;
    }
            cout<<endl;
            int count=0;
            for(int i=97;i<=122;i++)
            {
             c=i;
             count=0;
                               for(int j=0;j<s.length();j++)
                               {
                                       if(s[j]==i)
                                       count++;
                                       
                                }
            if(count>0)
            cout<<"count of "<<c<<"is"<<count<<endl;
            
            /*if((count!=0)&&(i==97))
            cout<<c<<"is"<<count<<endl;
            if((count!=0)&&(i==101))
            cout<<c<<"is"<<count<<endl;
            if((count!=0)&&(i==105))
            cout<<c<<"is"<<count<<endl;
            if((count!=0)&&(i==111))
            cout<<c<<"is"<<count<<endl;
            if((count!=0)&&(i==117))
            cout<<c<<"is"<<count<<endl;
            */
            }
            
                                                                        
system("pause");
    return(0);
}

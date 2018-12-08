#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    string s;
    int count=0,p,q,k;
    cout<<"Enter The String\n";
    getline(cin,s);
    for(int i=0;i<=s.length();i++)
    {cout <<i;
            if(s[i]==' ')
            {       cout<<"entered";
                     p=i+1;
                     while((s[p]!=' '))
								{
								if (s[p]>=48 && s[p]<=57)
                                {
                                            count=0;
											p++;
								}
                                else 
                                {
                                    count=1;
                                    break;
                                }
								}
					cout<<count<<endl;			
                    if(count==0)
                       {   
                           k=i+1;
                                        
                          while(s[k]!=' ')
                               {
											s[k]='x';
                                            k++;
                               }
                       }    
			}
	}
cout<<s;
system("pause");
return(0);
}                

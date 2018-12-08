//CODED BY ABHISHEK SINGH ,BTECH I/IV,A11019,BRANCH-CSE
//I HAVE CONSIDERED CASE-SENSATITIVE ANAGRAMS
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
bool isanagram(std::string s1,std::string s2)//function for sorting the two words and comparing which returns a bool value
     {
     bool b=false;
     if(s1.length()==s2.length())
     {
                                 std::sort(s1.begin(),s1.end());    //sorting from beginning to end
                                 std::sort(s2.begin(),s2.end());
                                 if(s1==s2)
                                 {
                                           b=true;
                                 }
     
     }
     return b;
     }
     
int main()
{
    int n,i,j,k,count=0;               //index variables 
                                                                                   
    cout<<"Enter the number of words you want to enter: ";
    cin>>n;
    std::string s[n+1];                          //storing the words in string array

    cout<<"Enter the words: "<<endl;
    i=0;
    while(i<=n)
    {
            std::getline(std::cin,s[i]);
            i++;
    } 
    for(i=1;i<n+1;i++)                                     //Deleting the repeated user entered words
    {                 for(j=i+1;j<n+1;j++)
                      {
                      if(s[i]==s[j])
                      {              n--;
                                     for(k=j;k<n;k++)
                                     s[k]=s[k+1];
                                     j--;
                      }
                      }
    } 
    if(n==1)
    {
            cout<<"There are same words or a single word in given input"<<endl;
            system("pause");
            exit(0);
    }
    int flag;
    ifstream in;                           //creating streams for writing into file and retriving back
    ofstream out;
    out.open("file.txt");
    int mark[n+1];
    for(i=1;i<n+1;i++)
      mark[i]=0;
    for(i=1;i<n+1;i++)                       //One by One comparison and output for anagram groups
    {       
            if(mark[i]==1)
              continue;
             flag=0;         
                      for(j=1;j<n+1;j++)
                      {
                                        
                                        if(i==j)
                                        continue;
                                        if(mark[j]==1)    //for already marked anagram
                                         continue;
                                        bool b=isanagram(s[i],s[j]);
    
                      if(b==true)
                      {         if(flag==0)
                                  {
                                           count++;
                                 out<<count<<"."<<s[i];
                                 mark[i]=1;            //marking anagram
                                 flag=1;
                                 }
                                 out<<","<<s[j];
                                 mark[j]=1;              
                      }
                      }
    if (flag==1)
    out<<endl;
    }
    if(count==0)
    {
    cout<<"There are no anagrams for these words in given input"<<endl; 
           system("pause");
            exit(0);                             //exiting the program
    }
    bool p;
    if(count>1)
    p=true;
    cout<<"There " ;
     cout<<(p ? "are ":"is ");
    cout<<count<<" anagram group";
     cout<<(p ? "s":"");                                  //Formatting Output
    cout<<(p ? ". They ":". That ");
     cout<<(p ? "are:":"is:");
     cout<<endl;
     char c;
    out.close();
    in.open("file.txt");
    while(!in.eof())
    {
                    in.get(c);
                    cout<<c;
    }
     in.close();
     
    system("pause");
    return(0);
}

    

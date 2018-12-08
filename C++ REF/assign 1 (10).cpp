#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
void WriteTofile(char t[])
{
    string s = t;
    string temp;
    ofstream fout,fout1;
    fout.open("Q10Records2.txt",ios::app);
    fout1.open("Q10Records3.txt",ios::app);
    int i;
    for(i=0; i<= s.length(); i++)
    {
        if(s[i]=='|')
            break;
    }
    temp = s.substr(0,i);
    //cout<<temp<<"\n";
    if(temp.length()>=10)
        fout<<s<<"#";
    else
        fout1<<s<<"#";
    fout.close();
    fout1.close();
}

int main()
{
    char s[30];  ifstream fin;
    ofstream fout("Q10Records2.txt");
    ofstream fout1("Q10Records3.txt");
    fout1.close();
    fout.close();
    fin.open("Q10Records.txt");
    if(!fin.is_open())
    {
        cout<<"\nError..!! in opening file..";
        exit(1);
    }
    while(!fin.eof())
    {
        fin.getline(s,30,'#');
        cout<<"\n"<<s<<"\n";
        WriteTofile(s);
    }
    fin.close();
    return 0;
}

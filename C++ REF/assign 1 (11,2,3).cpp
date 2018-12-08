#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include<string>
using namespace std;

struct student
{
    char rno[7];
    char name[20];
    char cgpa[5];
};

istream& operator >> (istream& cin, student &s)
{
    cout<<"\nEnter Roll no. : "; cin>>s.rno;
    cout<<"\nEnter Name : " ; cin.getline(s.name, 20); cin.getline(s.name, 20);
    int i;
    for(i=strlen(s.name) ; i<19; i++)
        s.name[i] = ' ';
    s.name[i] = '\0';
    cout<<"\nEnter Cgpa : "; cin>>s.cgpa;
}
ostream& operator << (ostream& cout, student &s)
{
    cout<<setw(10)<<s.rno<<setw(20)<<s.name<<setw(6)<<s.cgpa<<"\n";
}

int main()
{
    student s; char ans='y'; int i=0,n;
   ofstream fout("sample.txt");
   while(ans=='y')
   {
        cin>>s;
        fout.write((char *) &s, sizeof(s));
        cout<<"\nWanna Continue (y/n) ? ";
        cin>>ans;
   }
   fout.close();

   ifstream fin1("num.txt");
   cout<<"\nDisplaying total Records...\n\n";
   ifstream fin("sample.txt");
   while(fin1>>n)
   {
       cout<<"\n--------Showing "<<n<<" Records-----------\n";
        while(fin.read((char *)&s, sizeof(s)) && i<n)
        {
            cout<<s; i++;
        }
        if(i!=n)
        {
            cout<<"\nLess no. of records.....\n";
            break;
        }
        fin.seekg(0,ios::beg); i=0;
        cout<<"\n------------------------------------\n";
   }
   fin.close(); fin1.close();
   return 0;
}

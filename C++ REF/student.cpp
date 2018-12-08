#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct student
{
       string name,branch;
       int rno;
       double cgpa;
};
int main()
{
    student s[80];
    ifstream in;
    ofstream out;
    out.open("student.txt");
  string name,branch;
       int rno;
       double cgpa;
       char ch;
    int p=1,i=0;
    out<<"Roll No.\tName\tBranch\tC.G.P.A\n";
    do
    {
        cout<<"Enter the Roll no. of student\n";
       cin>>s[i].rno;
       out<<s[i].rno<<"\t\t";
       cout<<"Enter the name of student\n";
       cin>>s[i].name;
       out<<s[i].name<<"\t";
      cout<<"Enter the branch of student\n";
       cin>>s[i].branch;
       out<<s[i].branch<<"\t";
      cout<<"Enter the cgpa of student\n";
       cin>>s[i].cgpa;
       out<<s[i].cgpa<<endl;
    cout<<"Do you want to enter another recod:press 1 else 0\n";
    cin>>p;
    i++;
    }while(p==1);
    cout<<"The records in tabular form: "<<endl;
    out.close();
    in.open("student.txt");
    cout<<"Roll No.\tName\t\tBranch\tC.G.P.A\n";
    while(ch!='\n')
    in.get(ch);
    while(!in.eof())
    {
       in>>rno;
       cout<<rno<<"\t\t";
       in>>name;
       cout<<name<<"\t\t";

       in>>branch;
       cout<<branch<<"\t";

       in>>cgpa;
       cout<<cgpa<<endl;

    }
    in.close();
//    system("pause");
 return(0);
}





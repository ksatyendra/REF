#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class record
{
	char buffer[150];
	public:
		record()
		{
			strcpy(buffer," ");
		}
	string pack(char*,char*,char*);
	string pack(char *,char [4],char*,int);
	string pack(char *,char *);
};
string record::pack(char *name,char *no,char *cgpa)
{
	strcat(buffer,name);
	strcat(buffer,"|");
	strcat(buffer,no);
	strcat(buffer,"|");
	strcat(buffer,cgpa);
	strcat(buffer,"#");
	return buffer;
}
string record::pack(char *name,char *no)
{
	strcat(buffer,name);
	strcat(buffer,"|");
	strcat(buffer,no);
	strcat(buffer,"#");
	return buffer;
}
string record::pack(char *ename,char eno[4],char *sal,int n)
{
	char cname[21];
	char age[3];
	strcat(buffer,ename);
	strcat(buffer,"|");
	strcat(buffer,eno);
	strcat(buffer,"|");
	strcat(buffer,sal);
	strcat(buffer,"|");	
	cout<<"enter the"<<n<<" children details\n";
	for(int i=0;i<n;i++)
	{
		cout<<"enter the child"<<i+1<<"name\n";
		cin>>cname;
		cout<<"enter the child"<<i+1<<"age\n";
		cin>>age;
		strcat(buffer,cname);
		strcat(buffer,"|");
		strcat(buffer,age);
	}
		strcat(buffer,"#");
	return buffer;
}
int main()
{
	record r1,r2;
	int n1,n2,op;
	fstream file,file2;
	file2.open("rec4.txt",ios::out|ios::in);
	file.open("rec5.txt",ios::out|ios::in);
	cout<<"enter the std details for records 1\n";
	cout<<"enter no of stds\n";
	cin>>n1;	
	char name[21],no1[4],no2[4],cgpa[4];
	string a,b;
	for(int i=0;i<n1;i++)
	{
		cout<<"which format record u wanna create\n";
		cout<<"1. name,no,cgpa\n";
		cout<<"2. name,no\n";
		cin>>op;
		if(op==1)
		{
			cout<<"enter name\n";
			cin>>name;
			cout<<"enter no\n";
			cin>>no1;
			cout<<"enter cgpa";
			cin>>cgpa;
			a=r1.pack(name,no1,cgpa);
		}
		else if(op==2)
		{
			
			cout<<"enter name\n";
			cin>>name;
			cout<<"enter no\n";
			cin>>no1;
			a=r1.pack(name,no1);
		}
		file<<a;
		file2<<a;
	}
	file.seekg(0);
	file>>a;
	cout<<"----in file1----\n";
	cout<<a;
	cout<<"\n\n";
	file.close();
	int c;
	fstream file1;
	char ename[21],eno[4],sal[4];
	file1.open("D:\r4.txt",ios::out|ios::in);
	cout<<"--------------------------\n";
	cout<<"  enter the emp details\n";
	cout<<"--------------------------\n";
	cout<<"enter no of emps\n";
	cin>>n2;
	for(int i=0;i<n2;i++)
	{
		cout<<"enter ename\n";
		cin>>ename;
		cout<<"enter eno\n";
		cin>>eno;
		cout<<"enter sal\n";
		cin>>sal;
		cout<<"enter no of children\n";
		cin>>c;
		b=r2.pack(ename,eno,sal,c);
	}
	file1<<b;
	file2<<b;
	file1.seekg(0);
	file1>>b;
	cout<<"---in file 2---\n";
	cout<<b;
	cout<<"\n";
	file1.close();
	file2.seekg(0);
	file2>>a>>b;
	cout<<"merged files are\n";
	cout<<a<<b;
}
	
	




















#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class record
{
	char rno[4];
	char name[21];
	char cellno[5];
	char roomno[5];
	int tag;
	char buffer[150];
	public:
		record()
		{
			strcpy(buffer," ");
		}
	string pack(char*,char*,char*,int tag);
};
string record::pack(char *name,char *no,char *No,int tag)
{
	if(tag==1)
	{
	strcat(buffer,"1");
	strcat(buffer,name);
	strcat(buffer,"|");
	strcat(buffer,no);
	strcat(buffer,"|");
	strcat(buffer,No);
	strcat(buffer,"#");
	return buffer;
	}
	if(tag==2)
	{
	strcat(buffer,"2");
	strcat(buffer,name);
	strcat(buffer,"|");
	strcat(buffer,no);	
	strcat(buffer,"|");
	strcat(buffer,No);	
	strcat(buffer,"#");
	return buffer;
	}
}
int main()
{
	record r1;
	int n1,op;
	fstream file,file1,file2;
	file.open("rec.txt",ios::out|ios::in);
	file1.open("rec1.txt",ios::out);
	file2.open("rec2.txt",ios::out);
	cout<<"enter the std details for records 1\n";
	cout<<"enter no of stds\n";
	cin>>n1;	
	char name[21],no1[4],cgpa[4],rno[4],cno[4];
	string a;
	for(int i=0;i<n1;i++)
	{
		cout<<"which format record u wanna create\n";
		cout<<"1. name,no,cellno\n";
		cout<<"2. name,no,roomno\n";
		cin>>op;
		if(op==1)
		{
			cout<<"enter name\n";
			cin>>name;
			cout<<"enter no\n";
			cin>>no1;
			cout<<"enter cellno\n";
			cin>>cno;
			a=r1.pack(name,no1,cno,1);
		}
		else if(op==2)
		{
			cout<<"enter name\n";
			cin>>name;
			cout<<"enter no\n";
			cin>>no1;
			cout<<"enter the roomno\n";
			cin>>rno;
			a=r1.pack(name,no1,rno,2);
		}
		file<<a;
	}
	file.seekg(0);
	file>>a;
	int l=a.length();
	cout<<"----in file----\n";
	cout<<a<<"\n";
	for(int i=0;i<l;)
	{
		if(a[i]=='1')
		while(a[i]!='#')
		{
			file1<<a[i];
			i++;
		}
		else
		if(a[i]=='2')
		while(a[i]!='#')
		{
			file2<<a[i];
			i++;
		}			
		i++;
	}
	file1.close();
	file2.close();
	file1.open("rec1.txt",ios::in);
	char *line;
	cout<<"--file 1--\n";
	while(!file1.eof())
	{
		file1.getline(line,80);
		cout<<line;
	}
	cout<<"\n";	
	file2.open("rec2.txt",ios::in);
	char *line1;
	cout<<"--file 2--\n";
	while(!file2.eof())
	{
		file2.getline(line1,80);
		cout<<line1;
	}		
}

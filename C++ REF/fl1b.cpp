#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int cc=0;
class record
{
	char buffer[50];
	public:
	record()
	{
		strcpy(buffer," ");
	}
	string pack(char*,char [4],char*,int);
	void unpack();
};
string record::pack(char *ename,char eno[4],char *sal,int n)
{
	char cname[21];
	char age[3];
	strcat(buffer,ename);
	strcat(buffer,"|");
	strcat(buffer,eno);
	strcat(buffer,"|");
	strcat(buffer,sal);
	cout<<"enter the "<<n<<" children details\n";
	for(int i=0;i<n;i++)
	{
		cout<<"enter the child"<<i+1<<"name\n";
		cin>>cname;
		cout<<"enter the child"<<i+1<<"age\n";
		cin>>age;
		strcat(buffer,"|");			
		strcat(buffer,cname);
		strcat(buffer,"|");
		strcat(buffer,age);
	}
		strcat(buffer,"#");
		return buffer;
}
int main()
{
	record r1;
	char ename[21],eno[4],sal[4];
	string a;
	int n,c;
	fstream file,file1;
	file.open("r1.txt",ios::out|ios::in);
	file1.open("r2.txt",ios::out|ios::in);
	cout<<"--------------------------\n";
	cout<<"  enter the emp details\n";
	cout<<"--------------------------\n";
	cout<<"enter no of emps\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter ename\n";
		cin>>ename;
		cout<<"enter eno\n";
		cin>>eno;
		cout<<"enter sal\n";
		cin>>sal;
		cout<<"enter no of children\n";
		cin>>c;
		a=r1.pack(ename,eno,sal,c);
	}
	file<<a;
	file.seekg(0);
	file>>a;
	cout<<"----in file----\n";
	cout<<a<<"\n";
}















#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class record
{
	char buffer[50];
	public:
	string pack(char *name,char [4],char [4],int tag);
};
string record::pack(char *name,char no[4],char sal[4],int tag)
{
	if(tag==1)
	{
	strcpy(buffer,"1");
	strcat(buffer,name);
	strcat(buffer,"|");
	strcat(buffer,no);
	strcat(buffer,"|");
	strcat(buffer,sal);
	strcat(buffer,"#");
	}
	else 
	{
	strcpy(buffer,"2");
	strcat(buffer,name);
	strcat(buffer,"|");
	strcat(buffer,no);
	strcat(buffer,"|");
	strcat(buffer,sal);
	strcat(buffer,"#");
	}
	return buffer;
}
int main()
{
	record b; 
	int n,op;
	char name[10],no[4],sal[4];
	char *name1;
	string a,c;
	fstream file,file1,file2;
	file.open("srt1",ios::out|ios::in);
	file1.open("srt2",ios::out);
	file2.open("srt3",ios::out);
	cout<<" enter the record details \n";
	cout<<"--------------------------\n";
	cout<<" enter the no of persons	 \n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"1.fixed length 2.variable length\n";	
		cin>>op;
		if(op==1)
		{
		cout<<"enter name,no,sal\n";
		cin>>name>>no>>sal;
		 a=b.pack(name,no,sal,1);
		}
		else if(op==2)
		{
		cout<<"enter name,no,sal\n";
		cin>>name1>>no>>sal;
		 a=b.pack(name1,no,sal,2);
		}
		file<<a;
	}
	file.seekg(0);
	file>>a;
	cout<<"----in file----\n";
	cout<<a<<"\n";
	int l=a.length();
	for(int i=0;i<l;)
	{
		if(a[i]=='1')
		while(a[i]!='#')
		{
			file1<<a[i];
			i++;
		}
		else
		while(a[i]!='#')
		{
			file2<<a[i];
			i++;
		}			
		i++;
	}
	file1.close();
	file2.close();
	file1.open("srt2",ios::in);
	char *line;
	cout<<"--file 1--\n";
	while(!file1.eof())
	{
		file1.getline(line,80);
		cout<<line;
	}
	cout<<"\n";	
	file2.open("srt3",ios::in);
	char *line1;
	cout<<"--file 2--\n";
	while(!file2.eof())
	{
		file2.getline(line1,80);
		cout<<line1;
	}					
}









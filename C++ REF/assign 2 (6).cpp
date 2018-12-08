#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

char buffer[100];;

struct employee
{

	char* name;
	char eno[5];
	char sal[6];
};


void pack(char *a,int fno)
{
	strcat(buffer,a);
	if(fno<=2)
	strcat(buffer,"|");
	else
	strcat(buffer,"|#");
}
void flush()
{
	strcpy(buffer,"\0");
}

void unpack(char *f)
{
	int i=0;
	for(;buffer[0]!='|';i++)
	   {
	   	f[i]=buffer[0];
	   	for(int j=0;j<strlen(buffer);j++)
	   	   buffer[j]=buffer[j+1];


	   }
	   f[i++]='\0';
	for(int j=0;j<strlen(buffer);j++)
 	   	   buffer[j]=buffer[j+1];

}
void input(employee &e)
{
	string nm;
	cout<<"\n\nEnter the employee number: ";
    cin>>e.eno;
    cout<<"\n\nEnter the name: ";
    cin.get();
    getline(cin,nm,'.');
    e.name=new char(nm.length());
    strcpy(e.name,nm.c_str());
    cout<<"\n\nEnter the salary: ";
    cin>>e.sal;
}
void create(int n)
{
	ofstream fout("f1.txt");
	employee e;
	for(int i=0;i<n;i++)
	{
	   input(e);
	   pack(e.name,1);
	   pack(e.eno,2);
	   pack(e.sal,3);
	   fout<<buffer;
	   flush();
	}
	fout.close();
}
void find()
{
	ifstream fin("f1.txt");
	ofstream fout("f2.txt");
	string a;
	char c[5];
	int b;
	flush();
	while(getline(fin,a,'#'))
	{
	   	b=fin.tellg();
	   	pack(itoa(b,c,10),3);

	}
	fout<<buffer;

}

int main()
{
	int n;
	cout<<"\n\nEnter the number of employees: ";
	cin>>n;
	create(n);
	find();
	return 0;
}

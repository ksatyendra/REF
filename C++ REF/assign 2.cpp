#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#define MAX 20
using namespace std;
union addr
{
	char salary[6];
	char no_salary;
};

class Stu
{
	char rno[8];
	char name[20];
	int tag;
	addr ad;
	public:
		void add()
		{
		    char *ch;
			cout<<"Enter roll no. (max. length 6) : "; cin>>rno;
			cout<<"Enter Name (Max. 15 length) : "; cin.getline(name,15);  cin.getline(name,15);
			cout<<"Enter 1 for salary 2 for no salary : ";  cin>>tag;
			if(tag==1)
			{
				cout<<"Enter salary : "; cin>>ad.salary;
			}
			else
			{

				strcpy(ch," ");
				ad.no_salary=*ch;
			}
		}
		void pack(char *buffer)
		{
			strcpy(buffer,rno);
			strcat(buffer,"|");
			strcat(buffer,name);
			strcat(buffer,"|");
			if(tag==1)
				strcat(buffer,ad.salary);
				strcat(buffer,"|");
				strcat(buffer,"#");

		}

};
int main()
{
	ofstream fout; ifstream fin;
	Stu s[MAX]; int n,i=0; char buffer[40]; char* buf;
	fout.open("records.txt",ios::app);
	cout<<"ENter No. of Students : ";
	cin>>n;
	for(i=0; i<n; i++)
		s[i].add();
	//writing to file
	for(i=0; i<n ;i++)
	{
		s[i].pack(buffer);
		fout<<buffer;
	}
	fout.close();
	fout.open("size.txt");
	fin.open("records.txt");
	while(fin)
	{
		fin.getline(buffer,40,'#');
		fout<<fin.tellg()+1<<"  ";
	}

	fin.close();
	fout.close();
	return 0;
}

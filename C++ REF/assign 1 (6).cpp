#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<string>
#define MAX 20
using namespace std;
union addr
{
	char cellno[11];
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
			cout<<"Enter roll no. (max. length 6) : "; cin>>rno;
			cout<<"Enter Name (Max. 15 length) : "; cin.getline(name,15);  cin.getline(name,15);
			cout<<"Enter 0 for cell no : ";  cin>>tag;
			if(tag==0)
			{
				cout<<"Enter Cell no : "; cin>>ad.cellno;
			}
		}
		void pack(char *buffer)
		{
			strcpy(buffer,rno);
			strcat(buffer,"|");
			strcat(buffer,name);
			if(tag==0)
			{
				strcat(buffer,"|");
				strcat(buffer,ad.cellno);
				strcat(buffer,"#");
			}
			else
				strcat(buffer,"#");
		}
		void display()
		{
			cout<<setw(8)<<rno<<setw(20)<<name;
			if(tag==0)
				cout<<setw(12)<<ad.cellno<<endl;
		}
		char* retrno()
		{
			return rno;
		}
		char* retname()
		{
			return name;
		}
};
int main()
{
	ofstream fout; ifstream fin;
	Stu s[MAX]; int n,i=0; char buffer[40]; char* buf; string str;
	fout.open("Q6Records1.txt",ios::app);
	cout<<"ENter No. of Students : ";
	cin>>n;
	for(i=0; i<n; i++)
		s[i].add();
	//writing to file
	for(i=0; i<n ;i++)
	{
		s[i].pack(buffer);
		fout<<buffer<<"\n";
	}
	fout.close();
	fout.open("Q6Size.txt");
	fin.open("Q6Records1.txt");
	cout<<"\nWriting to file Q6Size.txt...\n\n";
	while(!fin.eof())
	{
		getline(fin,str);
		if(str.length()==0)
			break;
		fout<<str.length()<<" ";
	}
	fin.close();
	fout.close();
	return 0;
}

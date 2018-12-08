#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

void createfile()
{
	ofstream fin("1.txt");
	int n;
	cout<<"\n\nEnter the number of numbers";
	cin>>n;
	char a;
	cout<<"\n\nEnter the numbers in sorted order";
	while(n>0)
	{
		cin>>a;
		fin.put(a);
		n--;
	}
	fin.close();
	fin.open("2.txt");
	cout<<"\n\nEnter the number of numbers";
	cin>>n;
	cout<<"\n\nEnter the numbers in sorted order";
	while(n>0)
	{
		cin>>a;
		fin.put(a);
		n--;
	}
	fin.close();
}

void merge()
{
	ifstream f1("1.txt");
	ifstream f2("2.txt");
	ofstream f3("3.txt");
	char a,b;
	int i=0,j=0;
	while(!f1.eof() && !f2.eof())
	{
	    f1.seekg(i,ios::beg);
	    f2.seekg(j,ios::beg);
	    a=f1.get();
	    b=f2.get();
		if(a>=b)
		{
			 f3.put(b);
			 j++;
		}
		  
		else
		   {
		   	f3.put(a);
		   	i++;
		   }
	}
	while(!f1.eof())
	{
		f1.seekg(i,ios::beg);
		a=f1.get();
		f3.put(a);
		i++;
	}
	while(!f2.eof())
	{
		 f2.seekg(j,ios::beg);
		a=f2.get();
		f3.put(a);
		j++;
	}
}
void show()
{
	char a;
	ifstream f1("3.txt");
	while(!f1.eof())
	{
		a=f1.get();
		cout<<a<<'\n';
	}
}
int main()
{
	createfile();
	merge();
	show();
	return 0;
}

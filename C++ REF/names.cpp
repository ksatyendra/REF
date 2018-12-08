#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

void create()
{
	string a;
	int n;
	cout<<"\n\nEnter the number of strings you want to enter";
	cin>>n;
	cout<<"\n\nEnter the strings: ";
	ofstream fin("file1.txt");

	while(n>0)
	{
		cin>>a;
		fin<<a<<"\n";
		n--;
	}
	fin.close();
}
void sort()
{
	string b[20];
	ifstream fin("file1.txt");
	fin.seekg(0,ios::beg);
	int i=0;
	string a;
	while(fin>>a)
	{
		b[i]=a;
		i++;

	}
	fin.close();
	string t;
	int flag=1;
	for(int j=0;j<i;j++)
	{
		flag=j;
		for(int k=j+1;k<=i;k++)
		if(b[k].compare(b[j])<0)
		   flag=k;
		t=b[j];
		b[j]=b[flag];
		b[flag]=t;
	}
	ofstream fout("file2.txt");
	int j=0;
	while(j!=(i+1))
	{
		fout<<b[j]<<"\n";
		j++;
	}
	fout.close();
}
void show(char *a)
{
	string b;
	ifstream fin(a);
	while(fin>>b)
	{
		cout<<"\n"<<b;
	}
	fin.close();
}
int main()
{
	//create();
	cout<<"\n\nStrings before sorting: \n";
	show("file1.txt");
	sort();
	cout<<"\n\nStrings after sorting: \n";
	show("file2.txt");
	return 0;
}


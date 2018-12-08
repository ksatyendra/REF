#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<sstream>
using namespace std;
int size;
struct Stu
{
	string name;
	string rno;
	char fptr;
	char bptr;
	Stu()
	{
		name = ""; rno = "";
		fptr = bptr = '*';
	}
};
void unpack(string &s,string &field)
{
	int t = s.find("|");
	field = s.substr(0, t);
	s.erase(0, t+1);
}
ostream& operator <<(ostream& cout, Stu &s)
{
	cout<<s.rno<<"  "<<s.name<<"  "<<s.fptr<<"  "<<s.bptr<<"\n";
}
int ToInt(string s)
{
	int t;
	istringstream convert(s);
	convert>>t;
	return t;
}
int main()
{
	Stu s[10];  int k,r,i,n=0; string st,t,field1,field2;
	int size = 10;
	ifstream fin("records.txt");
	while(getline(fin, t, '#'))
	{
		unpack(t, field1);
		unpack(t, field2);
		k = ToInt(field1);
		r = k%size;
		int tmp=r;
		//cout<<"\n"<<r<<"\n";
		while(s[r].rno.length() >= 1 && n<size)
		{
			if(s[tmp].fptr != '*' && r == ToInt(s[tmp].rno)%size)
			{
				//cout<<s[t].fptr;
				tmp = s[tmp].fptr - 48;
			}
			r = (r+1)%size;
			s[tmp].fptr = r+48; //converting to integer
			n++;
		}
		if( n == size-1)
			cout<<"\nHash is Full \n";
		else if(n < size-1)
		{
			s[r].rno = field1;
			s[r].name = field2;
		}
		n=0;
	}
	fin.close();
	ofstream fout("Hash.txt");
	for(i=0; i<size; i++)
	{
		if(s[i].rno.length()>=2)
		{
			st = s[i].rno+"|"+s[i].bptr+"|"+s[i].fptr+"|#";
			fout<<st<<"\n";
			cout<<st<<"\n";
		}
	}
	fout.close();
	/*cout<<"\nEnter an id to search a record : "; cin>>n;
	fin.open("Hash.txt");
	r = n % size;  */
	return 0;
}

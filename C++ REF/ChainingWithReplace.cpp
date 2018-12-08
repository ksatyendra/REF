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
	t = ((convert>>t) ? t : -1);
	return t;
}
int main()
{
	Stu s[10],temp;  int k,r,i,n=0; string st,t,field1,field2;
	size = 10;
	ifstream fin("records.txt");
	while(getline(fin, t, '#'))
	{
		if(t.length() < 2)
			continue;
		unpack(t, field1);
		unpack(t, field2);
		k = ToInt(field1);
		r = k%size; int tmp=r;
		if(s[r].rno.length() <=1 )
		{
			s[r].rno = field1;  s[r].name = field2;
		}
		else if( r == ToInt(s[r].rno)%size )
		{
			if(s[r].fptr != '*')
			{
				while(s[r].fptr != '*')
				{
					int f = s[r].fptr - 48;
					r = f;
				}
				tmp = r;
			}
			while(s[r].rno.length()!=0 && n < size-1 )
			{
				r = (r+1)%size; n++;
			}
			if( n== size-1)
			{	cout<<"\nHash is Full !\n";  break;}
			else
			{
				s[tmp].fptr = r+48;
				s[r].bptr = tmp+48;
				s[r].name = field2; s[r].rno = field1;
			}
		}
		else if(r != ToInt(s[r].rno)%size)
		{
			n=0;
			temp.rno = s[r].rno; temp.bptr = s[r].bptr; temp.fptr = s[r].fptr;
			s[r].rno = field1;  s[r].name = field2; s[r].bptr ='*'; s[r].fptr ='*';
			while(s[r].rno.length()!=0 && n < size-1 )
			{
				r = (r+1)%size; n++;
			}
			if( n== size-1)
			{	cout<<"\nHash is Full !\n";  break;}
			else
			{
				i = temp.bptr - 48;
				s[i].fptr = r + 48;
				s[r].bptr = temp.bptr; s[r].fptr = temp.fptr;
				s[r].name = temp.name; s[r].rno = temp.rno;
			}
		}
	}
	fin.close();
	ofstream fout("Hash.txt");
	for(i=0; i<size; i++)
	{
		if(s[i].rno.length()>=1)
		{
			st = s[i].rno+"|"+s[i].bptr+"|"+s[i].fptr+"|#";
			fout<<st<<"\n";
			cout<<st<<"\n";
		}
	}
	fout.close();
	return 0;
}

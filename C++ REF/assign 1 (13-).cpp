#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<stdio.h>
#define MAX 20
using namespace std;

class Stu
{
	char rno[7];
	char name[20];
	char state[5];
	public:
		void add()
		{
			cout<<"Enter roll no. (max. length 6) : "; cin>>rno;
			cout<<"Enter Name (Max. 20 length) : "; cin.getline(name,15);  cin.getline(name,15);
			cout<<"Enter State (Max. 5 length) : "; cin>>state;
		}
		void pack(char *buffer)
		{
			strcpy(buffer,rno);
			strcat(buffer,"|");
			strcat(buffer,name);
			strcat(buffer,"|");
			strcat(buffer,state);
			strcat(buffer,"#");
		}
		void unpack(char ch[])
		{
			int i,k=0,j=0,l=0,p=0;  char str[20];
			for(i=0; i<=strlen(ch); i++)
			{
				if(ch[i]=='|' || ch[i]=='#' || ch[i]==0)
				{
					while(k!=i-l)
					{
						str[k++]=ch[j++];
					}
					str[k++]='\0';
					k=0; j=j+1;
					l=i+1;
					if(p==0)
					  strcpy(rno,str);
					else if(p==1)
						strcpy(name,str);
					else if(p==2)
						strcpy(state,str);
					p++;
				}

			}
		}
		void display()
		{
			cout<<setw(8)<<rno<<setw(20)<<name<<setw(5)<<state<<"\n";
		}
		char* retstate()
		{
			return state;
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
void sort_record(Stu s[],int n)
{
	Stu temp; int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(strcmp(s[j].retstate(),s[j+1].retstate()) > 0)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
}
void writeFile(Stu s[],int i)
{
	ofstream fout;  int j=0,k; char temp[6];
	fout.open("Q13Records2.txt");
	strcpy(temp,s[1].retstate());
	fout<<"\n_______________________\nStudent from state : "<<temp <<endl<<"^^^^^^^^^^^^^^^^^^^^^^^\n";
	for(j=1; j<i; j++)
	{
	    if(strcmp(temp,s[j].retstate())==0)
		{
			fout<<s[j].retrno()<<"  "<<s[j].retname()<<endl;
		}
		else
		{
			strcpy(temp,s[j].retstate());
			fout<<"________________________\nStudent from state : "<<temp<<endl<<"^^^^^^^^^^^^^^^^^^^^^^^^\n";
			fout<<s[j].retrno()<<"  "<<s[j].retname()<<endl;
		}
	}
	fout.close();
}
int main()
{
	ifstream fin;
	Stu s[MAX]; int n,i=0; char buffer[35];
	fin.open("Q13Records1.txt");
	if(!fin)
    {
        cout<<"\nError in opening file..!!";
        exit(1);
    }
	cout<<"\nDisplaying Data.....\n\n";
	while(!fin.eof())
	{
		fin.getline(buffer,35,'#');
		s[i].unpack(buffer);
		s[i++].display();
	}
	cout<<"After Sorting...\n";
	sort_record(s,i);
	for(n=1; n<i; n++)
	{
		s[n].display();
	}
	cout<<"\nPress any key to write into file..";
	getchar();
	writeFile(s,i);
	fin.close();
	return 0;
}

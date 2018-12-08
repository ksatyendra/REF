#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
using namespace std;
class stu
{
    char name[15];
    char rno[7];
public:
    void input()
    {
        cout<<"Enter Roll No. : "; cin>>rno;
        cout<<"Enter name : ";  cin.getline(name,15);  cin.getline(name,15);
    }
    void pack(char buf[])
    {
        strcpy(buf,rno);
        strcat(buf,"|");
        strcat(buf,name);
        strcat(buf,"#");
    }
    void unpack(char buf[])
    {
        char temp[20];
        int i,k=0,j=0,l=0,p=0;
        for(i=0; i<=strlen(buf); i++)
        {
            if(buf[i]=='|' || buf[i]=='#' || buf[i]==0)
            {
                while(k!=i-l)
                {
                    temp[k++]=buf[j++];
                }
                temp[k++]='\0';
                k=0; j=j+1;
                l=i+1;
                if(p==0)
                    strcpy(rno,temp);
                else if(p==1)
                    strcpy(name,temp);
                p++;
            }
        }
    }
    char* retrno()
    {
        return rno;
    }
    char* retname()
    {
        return name;
    }
    void display()
    {
        cout<<setw(8)<<rno<<setw(20)<<name<<"\n";
    }
};
int cmpStu(stu s1, stu s2)
{
    if(strcmp(s1.retname(),s2.retname())==0 && strcmp(s1.retrno(),s2.retrno())==0)
        return 1;
    return 0;
}
int check(int n, int p[],int x)
{
    for(int i=0; i<x; i++)
        if(p[i]==n)
            return 0;
    return 1;
}
int main()
{
    ifstream fin; ofstream fout;
	stu t,s[20]; int n,i=0,k; char buffer[25]; char ch='y';
	/*    fout.open("F1.txt");
	while(ch=='y')
    {
        t.input();
        t.pack(buffer);
        fout<<buffer;
        cout<<"\nWanna continue press y....";
        cin>>ch;
    }
    fout.close(); */
	fin.open("Q12Records1.txt");
	while(!fin.eof())
	{
		fin.getline(buffer,25,'#');
		if(strlen(buffer)>1)
		{
		    s[i].unpack(buffer);
            s[i++].display();
		}
	}
	fin.close();
    fout.open("Q12Records2.txt");
    int p[20],x=0;
	for(n=1; n<i && check(n,p,x) ; n++)
    {
        fout<<n+1;
        for(k = 0; k<i; k++)
            if(n!=k && cmpStu(s[n],s[k]))
            {
                fout<<"|"<<k+1;
                p[x++] = k;
            }
        fout<<"\n";
    }
    fout.close();
	return 0;
}

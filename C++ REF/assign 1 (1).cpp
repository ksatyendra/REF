#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>

using namespace std;

union addr
{
    char roomno[8];
    char cellno[11];
};
struct adr
{
    addr u;
    int top;
};
class stu
{
    char rno[7];
    char name[20];

public:
    int t;
    adr ad;
    void input()
    {
        cout<<"Enter Roll No. : "; cin>>rno;
        cout<<"Enter Name : "; gets(name); gets(name);
        cout<<"Enter 1 for further details : "; cin>>t;
        if(t==1)
        {
            cout<<"Enter 1 for room no. else cell no : "; cin>>ad.top;
            if(ad.top ==1)
            {
                 cout<<"Enter Room no. : ";  cin>>ad.u.roomno;
            }
            else
            {
                cout<<"Enter Cell no : "; cin>>ad.u.cellno;
            }
        }
    }
    void pack(char buffer[])
    {
        strcpy(buffer,rno);
        strcat(buffer,"|");
        strcat(buffer,name);
        if(t==1)
        {
            if(ad.top ==1)
            {
                strcat(buffer,"|");
                strcat(buffer,ad.u.roomno);
            }
            else
            {
                strcat(buffer,"|");
                strcat(buffer,ad.u.cellno);
            }
            strcat(buffer,"#");
        }
        else
            strcat(buffer,"#");
    }
    void display()
    {
        cout<<setw(8)<<rno<<setw(20)<<name;
        if(t ==1)
        {
            if(ad.top == 1)
                cout<<setw(10)<<ad.u.roomno<<endl;
            else
                cout<<setw(12)<<ad.u.cellno<<endl;
        }
        cout<<"\n";
    }
    void unpack(char buf[])
    {
        int i,k=0,j=0,l=0,p=0;  char str[20];
        for(i=0; i<=strlen(buf); i++)
        {
            if(buf[i]=='|' || buf[i]=='#' || buf[i]==0)
            {
                while(k!=i-l)
                {
                    str[k++]=buf[j++];
                }
                str[k++]='\0';
                k=0; j=j+1;
                l=i+1;
                if(p==0)
                    strcpy(rno,str);
                else if(p==1)
                    strcpy(name,str);
                else if(p==2)
                {
                    t=1;
                    if(strlen(str)==10)
                    {
                        ad.top = 0;
                        strcpy(ad.u.cellno,str);
                    }
                    else
                    {
                        ad.top = 1;
                        strcpy(ad.u.roomno,str);
                    }
                }
                p++;
            }
        }
    }
};
int main()
{
    ifstream fin,fin1; ofstream fout, fout1;
    stu t,s[20]; int n,i=0,k; char buffer[35]; char ch='y';
	fout.open("Q1Records.txt");
	while(ch=='y')
    {
        t.input();
        t.pack(buffer);
        fout<<buffer;
        cout<<"\nWanna continue press y....";
        cin>>ch;
    }
    fout.close();
	fin.open("Q1Records.txt",ios::app);
	while(!fin.eof())
	{
		fin.getline(buffer,35,'#');
		if(strlen(buffer)>1)
		{
		    s[i++].unpack(buffer);
		}
	}
	fin.close();
    cout<<"\n======================================\n";
    cout<<"\n--------Total Records of the File-----\n";
    cout<<"\n======================================\n\n";
    for(k=0;k<i; k++)
        s[k].display();
    return 0;
}


#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
union addr
{
    char cellno[10];
    char roomno[5];
};
class employe
{
   public:
    char Eno[6];
	char name[15];
	char salary[6];
	int tag;
	addr ad;
	void pack(char x[],char buf[]){
        strcat(buf,x);
        strcat(buf,"|");
    }
	void unpack(char buf[],int a[],int size)
	{
        ofstream fout; int flag=0;
        fout.open("varRec.txt");
        string ch;int k=0,j=0,i=0;
        while(i<size)
        {
            ch=buf[i];
            if(ch=="|")
            {
                cout<<endl;fout<<ch;i++;j++;
            }
            else if(j==a[k])
            {
                while(ch!="#")
                {
                    ch=buf[i];
                    if(flag==0)
                    {
                        fout<<"#";flag=1;
                    }
                    i++;
                }
                flag=0;
                cout<<"\n****************\n";j=0;k++;
            }
            else if(ch=="#")
            {
                cout<<"\n****************\n";i++;j=0;
                fout<<"#";
                k++;
            }
            else
            {
                cout<<ch;
                fout<<ch;
                i++;
            }
        }
    }
};
int main()
{
	char buf[500],recbuf[500];int i,a;
	ofstream fout;
	int n;
		cout<<"press\n 1.to add more data\n2.to make new data file\n";
	cin>>a;
	cout<<"Enter no. of employees :";
	cin>>n;
	employe e[n];

	if(a==1)
		fout.open("record.txt",ios::app);
		else
		fout.open("record.txt",ios::in);

	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Employee no. :";
		cin>>e[i].Eno;e[i].pack(e[i].Eno,buf);
       cout<<"Enter name of employe :";
       cin>>e[i].name;e[i].pack(e[i].name,buf);
       cout<<"Enter salary :";
       cin>>e[i].salary;e[i].pack(e[i].salary,buf);
       cout<<"press \n1.for cell no.\n2.for room no.\n";
       cin>>e[i].tag;
       if(e[i].tag==1)
       {
       	cout<<"Enter cell no.:";
       	cin>>e[i].ad.cellno;e[i].pack(e[i].ad.cellno,buf);
       }
       else
       {
       	cout<<"Enter room no:";
       	cin>>e[i].ad.roomno;e[i].pack(e[i].ad.roomno,buf);
       }
       strcat(buf,"#");
	}
     	fout<<buf;
     	int b[20];
     	fout.close();
     	ifstream fin1,fin2;
     	fin1.open("record.txt",ios::out);
     	fin2.open("int.txt");
     	for( i=0;!fin2.eof();i++)
     	{
     		fin2>>b[i];
     	}
     	fin2.close();
     	int j=0;char ch;
        while(!fin1.eof())
        {
        fin1.get(ch);
        recbuf[j++]=ch;
        }
        cout<<"\n#########################\n";
        employe p;
        p.unpack(recbuf,b,j);
        fin1.close();

     	return 0;
}

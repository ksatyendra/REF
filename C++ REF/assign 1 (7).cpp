#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;

struct child
{
    char name[10];
    char age[3];
};

struct Employee
{
    char id[6];
    char name[15];
    char salary[7];
    char tag;
    child *ch;
    void input();
    void pack(char buf[]);
    void display();
};
void Employee::input()
{
    cout<<"\nEnter Employee Id : "; cin>>id;
    cout<<"Enter Name : "; cin.getline(name,15);   cin.getline(name,15);
    cout<<"Enter Salary( 6 figure ) per annum : " ;  cin>>salary;
    cout<<"Enter No. of Children : "; cin>>tag;
    if(tag!='0')
    {
       int t = tag - 48;
       ch = new child [t];
       for(int i=0; i<t; i++)
       {
           cout<<"Enter "<<i+1<<" child name : "; cin>>ch[i].name;
           cout<<"Enter "<<i+1<<" child age : "; cin>>ch[i].age;
       }
    }
}
void Employee::pack(char buf[])
{
    char temp[2]; temp[0]=tag; temp[1]='\0';
    strcpy(buf,id);  strcat(buf,"|");
    strcat(buf,name);  strcat(buf,"|");
    strcat(buf,salary);  strcat(buf,"|");
    strcat(buf,temp);
    if(tag == '0')
        strcat(buf,"#");
    else
    {
        strcat(buf,"|");
        int  t = tag-48;
        for(int i=0; i<t; i++)
        {
            strcat(buf,ch[i].name);
            strcat(buf,"|");
            strcat(buf,ch[i].age);
            if(i==t-1)
                strcat(buf,"#");
            else
                strcat(buf,"|");
        }
    }
}
void Employee::display()
{
    cout<<setw(10)<<id<<setw(15)<<name<<setw(8)<<salary<<setw(4)<<tag;
    int ccount = tag - 48;
    if(ccount==0)
        cout<<"\n";
    else
    {
        for(int i=0; i<ccount; i++)
        {
            cout<<setw(10)<<ch[i].name<<setw(4)<<ch[i].age;
        }
        cout<<"\n";
    }
}
void substr(char buf[],char ch[],int &start,int end)
{
    int k =0 ;
    for(int i=start; i<end; i++)
    {
        ch[k++] = buf[i];
    }
    ch[k++] ='\0';
    start = end+1;
}

void extractData(char buf[])
{
    char ch[15],fix[25]=""; int k=0,check=0; ofstream fout("Q7Records1.txt",ios::app);
    for(int i=0; i<=strlen(buf); i++)
    {
        if(buf[i]=='|' || buf[i]=='\0')
        {
            if(check ==3 || check==4 || check==6 || check==8)
            {
                check++;
                continue;
            }
            substr(buf,ch,k,i);
            if(check<3)
                strcat(fix,ch),strcat(fix,"|");
            else
            {
                fout<<fix<<ch<<"#";
            }

            check++;
        }
    }
    fout<<"\n";
    fout.close();
}
int main()
{
    Employee e; char buf[60]; char ans='y';
    ifstream fin; ofstream fout;
   /* fout.open("Q7Records.txt",ios::app);
    while(ans == 'y')
    {
        e.input();
        e.pack(buf);
        e.display();
        fout<<buf;
        cout<<"\nWanna Continue (y/n) ? ";
        cin>>ans;
    }
    fout.close();  */
    fin.open("Q7Records.txt");
    if(!fin)
    {
        cout<<"\nError ...!! in opening file...\n\n";
        exit(2);
    }
    fout.open("Q7Records1.txt");
    fout.close();
    while(!fin.eof())
    {
        fin.getline(buf,60,'#');
        extractData(buf);

    }
    fin.close();
    return 0;
}

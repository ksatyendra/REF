#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
struct employe
{
    char name[15];
    char Eno[6];
    char child[6][15];
    int k;
};
char buf[500];
void pack(char x[],char buf[])
{
    strcat(buf,x);
    strcat(buf,"|");

}
void unpack(char rbuf[])
{
    ofstream fout;int i=0,j=0,k=0;char recbuf[100],a[20];
    fout.open("fixedEmployee.txt");char ch;
    cout<<rbuf<<"\n\n\n";

    //while(ch!="#")
   // {
        //ch=rbuf[i];

        while(j<2)
        {
           ch=rbuf[i];
            recbuf[k++]=rbuf[i++];

            cout<<recbuf<<endl;
            if(ch=='|')
                {j++;}

        }
        i++;
        //cout<<recbuf<<"\n";
          j=0;
        while(ch!='#')
        {
            ch=rbuf[i];
            a[j]=rbuf[i];j++;i++;

            if(ch=='|')
            {
               cout<<recbuf;
               cout<<a;
               fout<<recbuf;
               fout<<a;
            }

        }

          //  }


}
int main()
{

    char recbuf[100];
    int n;
    cout<<"Enter the no. of employees:";cin>>n;
    employe e[n];
    int s;
    for(int i=0;i<n;i++)
    {
    cout<<"\nEnter Employe no.:";
    cin>>e[i].Eno;pack(e[i].Eno,buf);
    cout<<"Enter name:";
    cin>>e[i].name;pack(e[i].name,buf);
    cout<<"Enter no. of childs:";
    cin>>s;
    e[i].k=s;
    for(int j=0;j<s;j++)
    {
    cout<<"Enter name of child:";
    cin>>e[i].child[j];pack(e[i].child[j],buf);
    }
    strcat(buf,"#");
    }
    ofstream fout;
    fout.open("employe.txt");
    fout<<buf;
    fout.close();
    ifstream fin;int j=0;char ch;string t;
    fin.open("employe.txt",ios::in);
         while(fin)
        {
            /*fin.get(ch);
            t=ch;
            recbuf[j]=ch;
            j++;*/
            fin.getline(recbuf,100,'#');
            if(fin)
            strcat(recbuf,"#");
        unpack(recbuf);


        }

        return 0;
}

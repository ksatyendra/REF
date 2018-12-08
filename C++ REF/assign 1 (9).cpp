#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>

using namespace std;

int getMarks(char buf[])
{
    char marks[3];
    int j=0, k=0;
    while(buf[k]!='|')
        k++;
    for(int i=k+1; buf[i]!='\0'; i++)
        marks[j++] = buf[i];
    marks[j] = '\0';
    k = atoi(marks);
    return k;
}
void getRno(char buf[],char rno[])
{
    int k=0;
    while(buf[k]!='|')
    {
        rno[k] = buf[k++];
    }
    rno[k] = '\0';
}
int main()
{
    ifstream fin1("Q9Records1.txt"); ifstream fin2("Q9Records2.txt"); ifstream fin3("Q9Records3.txt");
    ofstream fout("Q9Records.txt"); int a,b,c,k;
    char buf1[10],buf2[10],buf3[10], Buf[30], rno[7];
    while(fin1.getline(buf1,10,'#')&& fin2.getline(buf2,10,'#')&&
        fin3.getline(buf3,10,'#'))
    {

        a = getMarks(buf1); b = getMarks(buf2); c = getMarks(buf3);
        k = (a+b+c)/3;
        cout<<k;
        getRno(buf1,rno);
        strcpy(Buf,rno); strcat(Buf," |");
        strcat(Buf,itoa(a,buf1,10)); strcat(Buf,"|");
        strcat(Buf,itoa(b,buf1,10)); strcat(Buf,"|");
        strcat(Buf,itoa(c,buf1,10)); strcat(Buf,"|  Avg : ");
        strcat(Buf,itoa(k,buf1,10)); strcat(Buf," #");
        fout<<Buf<<"\n";
    }
    fin1.close(); fin2.close(); fin3.close(); fout.close();
}

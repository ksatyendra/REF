#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

struct Student{
    char rollNo[7];
    char marks[7];
};

struct sStudent{
    char rollNo[7];
    int no;
    char marks[8][7];
};

void pack(ofstream& out,Student& s)
{
    out<<s.rollNo<<"|"<<s.marks<<"#";
}

void unpack(string& buffer, Student& s)
{
    char temp[16];
    int j=0;
    int tag=0;
    for(int i=0;i<buffer.length();i++)
    {
        j=0;
        while(buffer[i]!='|'&&i<buffer.length())
        {
            temp[j++] = buffer[i++];
        }
        temp[j]='\0';

        if(tag==0)
            strcpy(s.rollNo,temp);
        else if(tag==1)
            strcpy(s.marks,temp);

        tag++;
    }
}

void update(Student* s, int &count, sStudent* ss, int &c)
{
    int flag = 0;
    for(int i=0;i<count;i++)
    {
        flag = 0;
        for(int j=0;j<c;j++)
        {
            if(strcmp(ss[j].rollNo,s[i].rollNo)==0)
            {
                flag = 1;
                strcpy(ss[j].marks[ss[j].no],s[i].marks);
                ss[j].no++;
            }
        }
        if(flag==0)
        {
            strcpy(ss[c].rollNo,s[i].rollNo);
            strcpy(ss[c].marks[ss[c].no],s[i].marks);
            c++;
        }

    }

}

int main()
{
    Student a;
    ofstream out1;
    out1.open("Marks1.txt");
    ofstream out2;
    out2.open("Marks2.txt");
    ofstream out3;
    out3.open("Marks3.txt");

    char check;
    int count=0;

    cout<<"Enter student details for subject 1: \n";
    do{
        cout<<"Enter roll number: ";
        cin.getline(a.rollNo,6);
        cout<<"Enter marks in subject 1: ";
        cin.getline(a.marks,6);
        pack(out1,a);
        count++;
        cout<<"Do you want to enter more(y/n): ";
        cin>>check;
        cin.ignore();
    }while(check=='y');

    cout<<"Enter student details for subject 2: \n";
    do{
        cout<<"Enter roll number: ";
        cin.getline(a.rollNo,6);
        cout<<"Enter marks in subject 2: ";
        cin.getline(a.marks,6);
        pack(out2,a);
        count++;
        cout<<"Do you want to enter more(y/n): ";
        cin>>check;
        cin.ignore();
    }while(check=='y');

    cout<<"Enter student details for subject 3: \n";
    do{
        cout<<"Enter roll number: ";
        cin.getline(a.rollNo,6);
        cout<<"Enter marks in subject 3: ";
        cin.getline(a.marks,6);
        pack(out3,a);
        count++;
        cout<<"Do you want to enter more(y/n): ";
        cin>>check;
        cin.ignore();
    }while(check=='y');


    out1.close();
    out2.close();
    out3.close();

    ifstream in1;
    ifstream in2;
    ifstream in3;
    ofstream out4;

    out4.open("Marks4.txt");
    in1.open("Marks1.txt");
    in2.open("Marks2.txt");
    in3.open("Marks3.txt");

    string buffer;

    Student s[20];
    int c = 0;
    while(!in1.eof())
    {
        getline(in1,buffer,'#');
        if(buffer.length()<2)
            break;
        unpack(buffer,s[count]);
        count++;
    }
    while(!in2.eof())
    {
        getline(in2,buffer,'#');
        if(buffer.length()<2)
            break;
        unpack(buffer,s[count]);
        count++;
    }
    while(!in3.eof())
    {
        getline(in3,buffer,'#');
        if(buffer.length()<2)
            break;
        unpack(buffer,s[count]);
        count++;
    }

    for(int i=count;i>0;i--)
    {
        for(int j=0;j<i-1;j++)
        {
            if(strcmp(s[j].rollNo,s[j+1].rollNo)>0)
            {
                char temp[10];
                char temp2[10];
                strcpy(temp,s[j].rollNo);
                strcpy(s[j].rollNo,s[j+1].rollNo);
                strcpy(s[j+1].rollNo,temp);
                strcpy(temp2,s[j].marks);
                strcpy(s[j].marks,s[j+1].marks);
                strcpy(s[j+1].marks,temp2);
            }
        }
    }


    sStudent ss[20];
    update(s,count,ss,c);

    for(int i=0;i<c;i++)
    {
        out4<<ss[i].rollNo<<"|"<<ss[i].no;
        for(int j=0;j<ss[i].no;j++)
        {
            out4<<"|"<<ss[i].marks[j];
        }
        out4<<"#";
    }

    in1.close();
    in2.close();
    in3.close();

    return 0;
}

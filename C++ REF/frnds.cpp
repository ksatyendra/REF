//********************************************
//*********HEADER FILE USED IN THIS PROJECT***
//********************************************
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<fstream>

using namespace std;
//************CLASS*************
class Student
{
    char name[25];
	int roll_no;
	double ptr;
	char dob[20];
	char branch[10];
	public:
		Student(){}   //default constructer
		~Student(){}  // default destructur
		Student(Student & s)  //copy constructer
		{
		    strcpy(name,s.name);
		    roll_no = s.roll_no;
		    ptr = s.ptr;
		    strcpy(dob,s.dob);
		    strcpy(branch,s.branch);
		}
		void input();
		void display();
		int retroll();
		double retptr();
		char* retname();

};
void Student::input()
    {
			cout<<"\n\nEnter Name: "; cin>>name;
			cout<<"Enter Roll no.: "; cin>>roll_no;
			cout<<"Enter CGPA: "; cin>>ptr;
			cout<<"Enter DOB: "; cin>>dob;
			cout<<"Enter Branch: "; cin>>branch;
    }
void Student::display()
{
    cout<<"\n"<<setw(10)<<roll_no<<setw(15)<<name<<setw(10)<<ptr<<setw(12)<<dob<<setw(10)<<branch;
}
int Student::retroll()
{
    return roll_no;
}
double Student::retptr()
{
    return ptr;
}
char* Student::retname()
{
    return name;
}
/*++++++++++++++++++++++++++++++++++++++++++++
***********Functions USED in This Project*****
*********************************************/
void form();      //function for header
void write_record();  //function for writing a data in record
void modify_record(int);//function for modifying record
void delete_record(int);//function for deleting record
void display_all(int);// function for displaying all record
void display_record(int);//function for displaying particular record
bool compare(char , char ); //For Comparing Two Character
int islower(char );  //to convert into lowercase letter
bool ExistRollNo(int);  //to check if roll no. already exists
/*================================================
    MAIN FUNCTION USED IN THE PROJECT
=================================================*/
int main()
{
    char ch; int num;
    cout<<"\n\n\nWELCOME TO MY PROJECT\n\n";
    cout<<"\n\n\t Created By : Rajmani Arya\n\n\n";
    do
    {
        cout<<"\n\n\nMAIN MENU";
        cout<<"\n\n\t1.ADD A NEW RECORD";
        cout<<"\n\n\t2.MODIFY AN EXISTING RECORD";
        cout<<"\n\n\t3.REMOVE A RECORD";
        cout<<"\n\n\t4.SHOW A RECORD";
        cout<<"\n\n\t5.SHOW ALL RECORD";
        cout<<"\n\n\t6.Exit";
        cout<<"\n\n\tSelect Your Option(1-8) : ";
        cin>>ch;
        switch(ch)
        {
            case '1':
                write_record();
                break;
            case '2':
                cout<<"\n\nEnter Roll No. For Modify a Record : ";
                cin>>num;
                modify_record(num);
                break;
            case '3':
                cout<<"\n\nEnter Roll No. To Remove a Record : ";
                cin>>num;
                delete_record(num);
                break;
            case '4':
                cout<<"\n\nEnter Roll No. To Show a Particular Record : ";
                cin>>num;
                display_record(num);
                break;
            case '5':
                {
                    cout<<"\nSort By\n\t1. ROLL No.\n\t2. CGPA\n\t3. NAME\n\tSelect Your option(1-3) : ";
                    int choice; cin>>choice;
                    switch(choice)
                    {
                        case 1:
                            display_all(choice);
                            break;
                        case 2:
                            display_all(choice);
                            break;
                        case 3:
                            display_all(choice);
                            break;
                        default:
                            cout<<"\nWrong Choice..\n"<<"\a";
                            break;
                    }
                    break;
                }
            case '6':
                cout<<"\n\n\t Thanks For Using This Project....\n";
                break;
            default:
                cout<<"\nWrong Choice..\n"<<"\a";
                break;
        }
    }while(ch!='6');
    return 0;
}
/*===========================================================
===========:::>>>FUNCTION DEFINITIONS<<<<:::=================
=============================================================*/
bool compare(char * n1,char * n2)
{
    int i,flag;
    for(i=0; n1!='\0', n2!='\0'; i++)
    {
        if(islower(n1[i])==islower(n2[i]))
        continue;
        else if(islower(n1[i]) > islower(n2[i]))
        { return false; break; }
        else if(islower(n1[i]) < islower(n2[i]))
        { return true; break;}
    }
}

int islower(char ch)
{
	if(ch>=65 && ch<=90)
	ch=ch+32;
	return ch;
}


void form()
{
    cout<<"\n===========================================================";
    cout<<"\n   Roll No.        NAME        CGPA      D.O.B      BRANCH\n";
    cout<<"===========================================================";
}

void write_record()
{
    Student s; ofstream outFile;
    s.input();
    int n = s.retroll();
    if(ExistRollNo(n))
    {
        outFile.open("record.dat",ios::binary|ios::app);
        outFile.write((char *) &s,sizeof(s));
        outFile.close();
    }
}

void modify_record(int num)
{
    Student s; fstream file; int found = 0;
    file.open("record.dat", ios::in|ios::out|ios::binary|ios::app);
    if(!file)
    {
        cout<<"Error In Opening File...Press any Key..!!";
        return;
    }
    while((char *) &s, sizeof(s) && found==0)
    {
        if(s.retroll()==num)
        {
            cout<<"\n\nEnter New Details Of the Student\n\n";
            s.input();
            int pos = (-1)*sizeof(s);
            file.seekp(pos,ios::cur);
            file.write((char *) &s, sizeof(s));
            cout<<"\n\nRecord Updated...\n";
            found = 1;
        }
    }
    if(found == 0)
    {
        cout<<"\nRoll Number Doesn't Exist..!!";
    }
}

void delete_record(int num)
{
    Student s;  int flag = 0;
    ifstream inFile; ofstream outFile;
    inFile.open("record.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Error in Opening File...Press any Key ..!!";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0, ios::beg);
    while(inFile.read((char *) &s, sizeof(s)))
    {
        flag = 0;
        if(s.retroll()!=num)
        {
            outFile.write((char *) &s, sizeof(s));

        }
        else
            flag = 1;
    }
    inFile.close();
    outFile.close();
    remove("record.dat");
    rename("Temp.dat","record.dat");
    if(flag==1)
    {
        cout<<"\n\nRecord updated....\n";
    }
}

void display_record(int num)
{
    Student s; int flag = 0;
    ifstream inFile; ofstream outFile;
    inFile.open("record.dat",ios::binary);
    if(!inFile)
    {
        cout<<"Error in Opening File...Press any Key ..!!";
        return;
    }
    cout<<"\n\tStudent Detalis\n\n";
    form();
    while(inFile.read((char *) &s, sizeof(s)))
    {
        if(s.retroll()==num)
        {
            s.display();
            flag = 1;
        }
    }
    inFile.close();
    if(flag==0)
    {
        cout<<"\n\nRoll Number Doesn't Exist...!!";
    }
}

bool ExistRollNo(int n)
{
	int found=0;
	Student s;
	fstream File;
	File.open("record.dat",ios::binary|ios::in|ios::out);
	while(File.read((char *) &s, sizeof(s)) && found==0)
	{
		if(s.retroll()==n)
		{
		    form();
			s.display();
			cout<<"\n\nStudent Already Exists....!!!";
			found=1; break;
		}
	}
	File.close();
	if(found==0)
		return true;
    else
        return false;
}

void display_all(int choice)
{
    Student s[100],stu,temp;  int i=0; fstream file;
    cout<<"\n\n\tALL Student LIST\n\n";
    form();
    file.open("record.dat",ios::in|ios::out|ios::binary);
    if(!file)
    {
        cout<<"Error In Opening File.....Press any key\n";
        return;
    }
    file.seekg(0,ios::beg);
    while(file.read((char *) &stu, sizeof(stu)))
    {
        s[i] = stu;
        i++;
    }
    int j,n = i; i=0;
    switch(choice)
    {
        case 1:
            for(i=0;i<n-1;i++)
				{
					for(j=0;j<n-i-1;j++)
					{
						if(s[j+1].retroll()<s[j].retroll())
						{
							temp=s[j];
							s[j]=s[j+1];
							s[j+1]=temp;
						}
					}
				}
			for(i=0; i<n; i++)
			s[i].display();
			break;
        case 2:
            for(i=0;i<n-1;i++)
					{
						for(j=0;j<n-i-1;j++)
						{
							if(s[j+1].retptr()<s[j].retptr())
							{
								temp=s[j];
								s[j]=s[j+1];
								s[j+1]=temp;
							}
						}
					}
			for(i=0; i<n; i++)
			s[i].display();
			break;
        case 3:
            for(i=0;i<n;i++)
			{
				for(j=0;j<n-1-i;j++)
				{
				if(compare(s[j+1].retname(),s[j].retname()))
				{
					temp=s[j];
					s[j]=s[j+1];
					s[j+1]=temp;
				}
				}
			}
			for(i=0; i<n; i++)
			s[i].display();
			break;

    }
    file.close();
}

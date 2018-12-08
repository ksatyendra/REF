#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Child{
	string childName;
	string grade;
};

struct Employee{
	string employeeNumber;
	string employeeName;
	int numberOfChildren;
	Child children[10];
};

void output(Employee& e)
{
	cout<<"\nEmployee Number: \t"<<e.employeeNumber<<"\t\t\t\t"<<e.employeeNumber.length();
	cout<<"\nEmployee Name: \t\t"<<e.employeeName<<"\t\t\t"<<e.employeeName.length();
	cout<<"\nNumber of Children:\t"<<e.numberOfChildren;
	for(int i=0;i<e.numberOfChildren;i++)
	{
		cout<<"\nChild "<<i+1<<" name: \t\t"<<e.children[i].childName<<"\t\t\t"<<e.children[i].childName.length();
		cout<<"\nChild "<<i+1<<" class: \t\t"<<e.children[i].grade<<"\t\t\t\t"<<e.children[i].grade.length()<<endl;
	}
}

void output2(Employee& e)
{
	cout<<e.employeeNumber<<"|"<<e.employeeName<<"|"<<e.numberOfChildren<<"|"<<e.children[0].childName<<"|"<<e.children[0].grade<<"#";
}

void unpack(string& buffer, Employee& e)
{
	int i=5,j;
	while(buffer[i]==' ')
		i--;
	for(j=0;j<=i;j++)
	{
		e.employeeNumber.append(1,buffer[j]);
	}
	i = 21;
	while(buffer[i]==' ')
		i--;
	for(j=7;j<=i;j++)
	{
		e.employeeName.append(1,buffer[j]);
	}
	i = 36;
	while(buffer[i]==' ')
		i--;

	for(j=23;j<=i;j++)
	{
		e.children[0].childName.append(1,buffer[j]);
	}

	j = 0;

	for(i = 39;i<41;i++)
	{
		if(buffer[i]!=' ')
		{
			e.children[0].grade.append(1,buffer[i]);
			j++;
		}
	}
	if(e.children[0].childName.length()>0)
		e.numberOfChildren = 1;
	else
		e.numberOfChildren = 0;
}

void update(Employee* s, Employee& e, int& n)
{
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i].employeeNumber==e.employeeNumber)
		{
			if(e.numberOfChildren>0)
			{
				s[i].numberOfChildren++;
				s[i].children[s[i].numberOfChildren-1].childName = e.children[0].childName;
				s[i].children[s[i].numberOfChildren-1].grade = e.children[0].grade;
			}
			flag = 1;
		}
	}
	if(flag == 0)
	{
		s[n].employeeNumber = e.employeeNumber;
		s[n].employeeName = e.employeeName;
		s[n].numberOfChildren = e.numberOfChildren;
		s[n].children[0].childName = e.children[0].childName;
		s[n].children[0].grade = e.children[0].grade;
		n++;
	}
}

void clear(Employee &e)
{
	e.employeeName = "";
	e.employeeNumber = "";
	e.numberOfChildren = 0;
	e.children[0].childName = "";
	e.children[0].grade = "";
}

void packRepeating(ofstream& out, Employee& e)
{
	string buffer;
	buffer.append(e.employeeNumber);
	buffer.append(1,'|');
	buffer.append(e.employeeName);
	for(int i=0;i<e.numberOfChildren;i++)
	{
		buffer.append(1,'|');
		buffer.append(e.children[i].childName);
		buffer.append(1,'|');
		buffer.append(e.children[i].grade);
	}
	buffer.append(1,'#');
	out<<buffer;
}

int main()
{

	ifstream in;
	in.open("Packed.txt");
	string buffer;
	Employee emp[10];
	Employee temp;
	int i=0;
	int count = 0;
	while(!in.eof())
	{
		getline(in,buffer,'#');
		if(buffer.length()==0)
			break;
		unpack(buffer,temp);
		update(emp,temp,count);
		clear(temp);
		i++;
	}
	for(int i=0;i<count;i++)
	{
		output(emp[i]);
	}
	in.close();

	ofstream out;
	out.open("Unpacked.txt");

	for(int i=0;i<count;i++)
	{
		packRepeating(out,emp[i]);
	}

	out.close();

	return 0;
}

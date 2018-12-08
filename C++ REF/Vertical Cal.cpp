#include<iostream>
#include<iomanip>

using namespace std;

void getday(int day_code,int month,int a,int year);

void print_calendar(int month, int year,int &day_code );

char* month_name[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

char* Day[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

int day_month[2][12] ={ { 31,28,31,30,31,30,31,31,30,31,30,31},
					  { 31,29,31,30,31,30,31,31,30,31,30,31} };

int main()
{
	int month,year,day_code;
	cout<<"Enter Year : "; cin>>year;
	cout<<"Enter First Day of The Year : \n 0 for Sunday\n 1 for Monday\n and so on.....\n"; 
	cin>>day_code;
	for(month = 1 ; month<=12; month++)
	{
		cout<<"\n\n\t"<<month_name[month-1]<<"  "<<year<<"\n";
		cout<<"_________________________\n";
		print_calendar(month,year,day_code);
		cout<<"_________________________";
	}
	return 0;
}
//Function Definition

void print_calendar(int month, int year,int &day_code )
{
	int leap,a;
	leap = (year%400==0)||((year%4==0)&&(year%100!=0));
	
	for(a=0; a<7; a++)
	{
		cout<<Day[a];
		getday(day_code,month,a,year);
		cout<<"\n";
	}
	day_code = (day_code+day_month[leap][month-1])%7;
}

void getday(int day_code,int month, int a,int year)
{
	int k;
	int leap = (year%400==0)||((year%4==0)&&(year%100!=0));
	if(day_code==a)
	{
		for(k=1; k<=day_month[leap][month-1]; k+=7)
		cout<<setw(4)<<k;
	}
	else if(a<day_code)
	{
		cout<<"    ";
		for(k=8+a-day_code; k<=day_month[leap][month-1]; k+=7)
		cout<<setw(4)<<k;
	}
	else
	{
		for(k=1+a-day_code; k<=day_month[leap][month-1]; k+=7)
		cout<<setw(4)<<k;
	}
}

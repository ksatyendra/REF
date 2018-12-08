#include<iostream>
#include<iomanip>

using namespace std;

int getday(int day_code,int month,int year);

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
		cout<<"\n\t"<<month_name[month-1]<<"  "<<year<<"\n";
		print_calendar(month,year,day_code);
		cout<<"\n____________________________\n";
	}
	return 0;
}
//Function Definition

void print_calendar(int month, int year,int &day_code )
{
	int leap,a;
	leap = (year%400==0)||((year%4==0)&&(year%100!=0));
	
	cout<<"\n============================\n";
	cout<<" Sun Mon Tue Wed Thu Fri Sat\n";
	cout<<"============================\n";
	for(a=0; a<day_code;a++)
	cout<<"    ";
	for(a=1; a<=day_month[leap][month-1]; a++)
	{
		cout<<setw(4)<<a;
		if((day_code+a)%7==0)
		cout<<"\n";
	}
	day_code = (day_code+day_month[leap][month-1])%7;
}

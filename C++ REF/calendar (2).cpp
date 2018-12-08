#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int day_tbl[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},  //month days for a year
						{31,29,31,30,31,30,31,31,30,31,30,31} };  //month days for a leap year
int month_tbl[2][12] = { {0,3,3,6,1,4,6,2,5,0,3,5} ,   //month table for a year
						{6,2,3,6,1,4,6,2,5,0,3,5} };   //month table for a leap year
char *MonthTable[12] = { "January","February","March","April","May","June","July",
							"August","September","October","November","December" };
int FirstDayOfMonth(int m,int y)
{
	int i, leap ; long d;
	leap = ((y%4 == 0 && y%100 != 0)||(y%400 == 0));   // if it is leap year then leap = 1 else leap = 0
	d = month_tbl[leap][m-1]+(y%100) +7+ (y%100)/4 ;   // gregorian algorithm for finding a day of given date
	if(y<2000)
        d+=1;
	return (d%7); // remainder is 0 for sunday , 1 for monday and so on...
}
void print_calendar(int m, int y)
{
	int i, leap, FDOM;
	FDOM = FirstDayOfMonth(m,y);
	leap = ((y%4 == 0 && y%100 != 0)||(y%400 == 0));
	cout<<"\n\t"<<MonthTable[m-1]<<"   "<<y;
	cout<<"\n==========================================";
	cout<<"\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat";
	cout<<"\n==========================================\n";
	for(i=0; i<FDOM; i++)
	cout<<"      ";
	for(i=1; i<=day_tbl[leap][m-1]; i++)
	{
		cout<<setw(6)<<i;
		if((FDOM+i)%7 == 0)
		cout<<"\n";
	}
	cout<<"\n------------------------------------------\n";
}
int main()
{
	int y,m,ch;
	do{
        cout<<"\nMAIN MENU\n";
        cout<<"\n\t 1. By Year";
        cout<<"\n\t 2. By Month And Year";
        cout<<"\n\t Select Your Choice(1 - 3) : ";
        cin>>ch;
	switch(ch)
	{
     case 1:
        cout<<"\n Enter Year To Get Calender (1753 - 2100) : ";
        cin>>y;
        cout<<"\nCalender For Year "<<y<<" is Below\n";
        for(m = 1; m<=12; m++)
        print_calendar(m,y);
        break;
    case 2:
        cout<<"\n Enter Year (1753 - 2100) : ";
        cin>>y;
        cout<<"Enter Month (1 - 12) : "; cin>>m;
        cout<<"\nCalender For "<<MonthTable[m-1]<<"   "<<y<<" is Below\n";
        print_calendar(m,y);
        break;
	case 3:
            cout<<"\n\nThanks For Using This Application (Based On GreGorian Calender)....\n";
            return 0;  break;
    default:
        cout<<"\nYou Have Entered an Incorrect Option,,,,!!";
        break;
	}
	}while(ch!=3);
	return 0;
}

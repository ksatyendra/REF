#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
#define new_cal 1
#define old_cal 0
class std_calc
{
	public:
		static double addition(double , double);
		static double subtraction(double , double);
		static double multiplication(double , double);
		static double divison(double , double*);
		static double modulus(double* , double*);
};
class scie_calc
{
	public:
		static double square(double );
		static double cube(double);
		static double power(double , double);
		static double sq_root(double );
		static long int fact(double);
		static double sin_func(double);
		static double cos_func(double);
		static double tan_func(double);
};
double std_calc::addition(double a,double b)
{
	return a+b;
}
double std_calc::subtraction(double a, double b)
{
	return a-b;
}
double std_calc::multiplication(double a, double b)
{
	return a*b;
}
double std_calc::divison(double a, double *b)
{
	while(*b==0)
	{
		cout<<"\nCannot Divide by Zero...";
		cout<<"\nEnter Second Number Again...: ";
		cin>>*b;
	}
	return (a/(*b));
}
double std_calc::modulus(double *a, double *b)
{
	while(*b==0)
	{
		cout<<"\nCannot Divide by Zero...";
		cout<<"\nEnter Second Number Again...: ";
		cin>>*b;
	}
	int x = (int)*a; int y = (int)*b;
	if(*a-x>0 || *b-y>0)
		cout<<"\nConverting decimal number to integer to perform modulus";
	*a = x; *b = y;
	return x%y;
}
double scie_calc::square(double x)
{
	return pow(x,2);
}
double scie_calc::cube(double x)
{
	return pow(x,3);
}
double scie_calc::power(double x, double y)
{
	return pow(x,y);
}
double scie_calc::sq_root(double x)
{
	return sqrt(x);
}
long int scie_calc::fact(double x)
{
	int n = (int)x; long int f=1;
	while(n>1)
	{
		f *= n;
		n--;
	}
	return f;
}
double scie_calc::sin_func(double x)
{
	return sin(x);
}
double scie_calc::cos_func(double x)
{
	return cos(x);
}
double scie_calc::tan_func(double x)
{
	return tan(x);
}
//Displaying Main Menu
int main()
{
	double num1,num2,num3,temp=0; long int num4;
	int choice1,choice2,flag;
	do{
		cout<<"\n============Type of Calculators=========";
		cout<<"\n1\tStandard Calculator\n2\tScientific Calculator\n3\tQuit";
		cout<<"\nChoose the type of calculator: ";
		cin>>choice1; flag = new_cal;
		switch(choice1)
		{
			case 1:
				do{
					cout<<"\n===========Standard Calculator============";
					cout<<"\n1\tAddition\n2\tSubtraction\n3\tMultiplication\n4\tDivison\n5\tModulus\n6\treturn to previous menu\n7\tquit";
					if(flag==old_cal)
						cout<<"\n8\tClear Memory";
					cout<<"\nChoose type of calculation: ";
					cin>>choice2;
					switch(choice2)
					{
						case 1:
							if(flag==new_cal)
							{
								cout<<"\nEnter First Number: ";
								cin>>num1;
							}
							else
							{
								num1=temp;
								cout<<"\nFirst Number is "<<num1<<"\n";
							}
							cout<<"Enter Second Number: "; cin>>num2;
							num3 = std_calc::addition(num1,num2);
							cout<<"\nAddition of "<<num1<<" and "<<num2<<" is "<<num3;
							temp = num3; flag = old_cal;
							break;
						case 2:
							if(flag==new_cal)
							{
								cout<<"Enter first number: "; cin>>num1;
							}
							else
							{
								num1=temp; cout<<"\nFirst Number is "<<num1<<"\n";
							}
							cout<<"Enter Second Number: "; cin>>num2;
							num3 = std_calc::subtraction(num1,num2);
							cout<<"\nSubtraction of "<<num1<<" and "<<num2<<" is "<<num3;
							temp = num3;
							flag = old_cal; break;
						case 3:
							if(flag==new_cal)
							{
								cout<<"Enter first number: "; cin>>num1;
							}
							else
							{
								num1=temp; cout<<"\nFirst Number is "<<num1<<"\n";
							}
							cout<<"Enter Second Number: "; cin>>num2;
							num3 = std_calc::multiplication(num1,num2);
							cout<<"\nMultiplication of "<<num1<<" and "<<num2<<" is "<<num3;
							temp = num3;
							flag = old_cal; break;
						case 4:
							if(flag==new_cal)
							{
								cout<<"Enter first number: "; cin>>num1;
							}
							else
							{
								num1=temp; cout<<"\nFirst Number is "<<num1<<"\n";
							}
							cout<<"Enter Second Number: "; cin>>num2;
							num3 = std_calc::divison(num1,&num2);
							cout<<"\nDivision of "<<num1<<" and "<<num2<<" is "<<num3;
							temp = num3;
							flag = old_cal; break;
						case 5:
							if(flag==new_cal)
							{
								cout<<"Enter first number: "; cin>>num1;
							}
							else
							{
								num1=temp; cout<<"\nFirst Number is "<<num1<<"\n";
							}
							cout<<"Enter Second Number: "; cin>>num2;
							num3 = std_calc::modulus(&num1,&num2);
							cout<<"\nModulus of "<<num1<<" and "<<num2<<" is "<<num3;
							temp = num3;
							flag = old_cal; break;
						case 6:
							cout<<"\nReturning to previous menu."; break;
						case 7:
							cout<<"\nQuitting.........."; exit(0);
						case 8:
							if(flag==new_cal)
							{
								cout<<"\nInvalid choice.";
							}
							else
							{
								temp =0; flag= new_cal;
							}
							break;
						default:
							cout<<"\nInvalid Choice.."; break;
					}
				}while(choice2!=6);
				break;
			case 2:
				do{
					cout<<"\n===========Scientific Calculator=============";
					cout<<"\n1\tSquare\n2\tCube\n3\tPower\n4\tFactorial\n5\tSin\n6\tCos\n7\tTan\n8\tReturn to previous Menu\n9\tQuit";
					if(flag==old_cal)
					cout<<"\n10\tClear memory";
					cout<<"\nChoose Type of Calculation: "; cin>>choice2;
					switch(choice2)
					{
						case 1:
							if(flag==new_cal)
							{
								cout<<"Enter number to find Square: "; cin>>num1;
							}
							else
							{
								num1=temp; cout<<"\nNumber is "<<num1<<"\n";
							}
							num3 = scie_calc::square(num1);
							cout<<"\nSquare of "<<num1<<" is "<<num3;
							temp = num3;
							flag = old_cal; break;
						case 2:
							if(flag==new_cal)
							{
								cout<<"Enter number to find Cube: "; cin>>num1;
							}
							else
							{
								num1=temp; cout<<"\nNumber is "<<num1<<"\n";
							}
							num3 = scie_calc::cube(num1);
							cout<<"\nCube of "<<num1<<" is "<<num3;
							temp = num3;
							flag = old_cal; break;
						case 3:
							if(flag==new_cal)
							{
								cout<<"Enter First number for base to find Power: "; cin>>num1;
							}
							else
							{
								num1=temp; cout<<"\nFirst Number is "<<num1<<"\n";
							}
							cout<<"Enter Second Number For Power to Find power: "; cin>>num2;
							num3 = scie_calc::power(num1,num2);
							cout<<"\n"<<num1<<" to the power "<<num2<<" is "<<num3;
							temp = num3;
							flag = old_cal; break;
						case 4:
							if(flag==new_cal)
							{
								cout<<"Enter number to find Factorial: "; cin>>num1;
							}
							else
							{
								num1=temp; cout<<"\nNumber to find Factorial is "<<num1<<"\n";
							}
							num4 = scie_calc::fact(num1);
							cout<<"\nFactorial of "<<num1<<" is "<<num4;
							temp = num4;
							flag = old_cal; break;
						case 5:
							if(flag==new_cal)
							{
								cout<<"Enter Number to find Sin Value: ";
								cin>>num1;
							}
							else
							{
								num1=temp;
								cout<<"\nNumber for Sin value is "<<num1<<endl;
							}
							num3=scie_calc::sin_func(num1);
							cout<<"\nSin value of "<<num1<<" is "<<num3;
							temp = num3; flag = old_cal;
							break;
						case 6:
							if(flag==new_cal)
							{
								cout<<"Enter Number to find Cos Value: ";
								cin>>num1;
							}
							else
							{
								num1=temp;
								cout<<"\nNumber for Cos value is "<<num1<<endl;
							}
							num3=scie_calc::cos_func(num1);
							cout<<"\nCos value of "<<num1<<" is "<<num3;
							temp = num3; flag = old_cal;
							break;
						case 7:
							if(flag==new_cal)
							{
								cout<<"Enter Number to find Tan Value: ";
								cin>>num1;
							}
							else
							{
								num1=temp;
								cout<<"\nNumber for Tan value is "<<num1<<endl;
							}
							num3=scie_calc::tan_func(num1);
							cout<<"\nTan value of "<<num1<<" is "<<num3;
							temp = num3; flag = old_cal;
							break;
						case 8:
							cout<<"\nReturning to Previous Menu..."; break;
						case 9:
							cout<<"\nQuitting.......";
							exit(0);
						case 10:
							if(flag==new_cal)
							{
								cout<<"\nInvalid Choice.";
							}
							else
							{
								temp = 0;
								flag = new_cal;
							}
							break;
						default:
							cout<<"\nInvalid Choice..."; break;
					}
			}while(choice2!=8);
			case 3:
				cout<<"\nQuitting....."; break;
			default:
				cout<<"\nInvalid Choice.."; break;
		}
	}while(choice1!=3);
	return 0;
}

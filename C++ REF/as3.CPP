#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void sort(int a[], int size)
{
	int i,j,t;
	for(i=0; i<size; i++)
	{
		for(j=0; j<size-1-i; j++)
		{
			if(a[j]>a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}	
		}
	}
}

int maxFreq(int b[],int size)
{
	int max,i;
	max = b[0];
	for(i = 1; i<size; i++)
	{
		if(max < b[i])
			max = b[i];
	}
	return max;
}

void write_frequency(int b[],int size)
{
	ofstream fout;
	fout.open("frequency.txt");
	for(int i=0; i<size; i++)
		fout<<" "<<b[i];
	fout.close();
}

void Draw_Graph(int b[],int f[],int size)
{
	
	ofstream fout;
	fout.open("graph.txt");
	
	int max = maxFreq(f,size), i;
	
	int d = max;

 	for(i=0; i<max; i++, --d)
 	{
  		fout<<"|  ";
  		for(int j=0;j<size;j++)
  		{
   			if(f[j]>=d )
    			fout<<"*  ";
   			else
    			fout<<"   ";
  		}
  		fout<<"\n";
 	}
 	fout<<" ";
 	for(i=0;i<size;i++)
  		fout<<"~~~";
 	fout<<"\n ";
 	for(i=0;i<size;i++)
  		fout<<"  "<<b[i];
  	fout.close();
}

void getfrequency(int p[],int &size, int b[],int f[])
{
	int k=0,x=0,j,i=0;
	for(i = 0; i<size; i=j-1 )
	{
		b[k] = p[i]; j = i;
		while(b[k]==p[j++])
			x++;
		f[k] = x;
		x =0; k++;
	}
	size = k;
}
int main()
{
 	ifstream fin; 
	fin.open("number.txt");
	
	int i=0,k=0,j=0, x;
	int *p = new int[25];
	int *b = new int[10];
	int *f = new int[10];
	while(!fin.eof())
	{
		fin>>p[i++];
	}
	fin.close();
	sort(p,i);

	getfrequency(p,i,b,f);

	write_frequency(f,i);
	char ch;
	cout<<"For Graph Press Any Key....";
	cin.get(ch);
	Draw_Graph(b,f,i);
 	return 0;
}

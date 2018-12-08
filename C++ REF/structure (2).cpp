#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
struct s
{
       int number;
       int marks;
};
void swap(int& x,int&y)
{
     int t;
     t=x;
     x=y;
     y=t;
}
int main()
{   int n,i;
    cout<<"Enter the number of student records to be sorted:"; 
    cin>>n;
    s a[n];
    ifstream input;
    input.open("rollno.txt");
    int num;
    for(i=0;i<n;i++)
                     {
                     input>>num;
                     a[i].number=num;
                     if(input.eof())
                     break;
                     }
    input.close();
    ifstream input2;
    input2.open("marks.txt");
    for(i=0;i<n;i++)
                    { 
                           input2>>num;
                           a[i].marks=num;
                           if(input2.eof())
                           break;
                    }
    input2.close();
    for(i=0;i<n;i++)
         for(int j=0;j<n-i-1;j++)
         if(a[j].marks>a[j+1].marks)
         {
                                    swap(a[j].marks,a[j+1].marks);
                                    swap(a[j].number,a[j+1].number);
         }

    ofstream out;
    out.open("sorted_marks.txt");
    out<<"Roll No."<<"\t"<<"Marks"<<endl;
    for(i=0;i<n;i++)
    {
                    out<< a[i].number<<"\t"<<a[i].marks<<endl;
                    
    }
    out.close();
    system("pause");
    return(0);
}

#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int i,j,i2,j2;
    ifstream input1,input2;
    ofstream output;
    input1.open("f1.txt");
    input2.open("f2.txt");
    output.open("f3.txt");
    input1>>i;
    input2>>j;
    while((!input1.eof())&&(!input2.eof()))

   {
           if(i<j)
           {
                  output<<i<<"\t";
                  cout<<i<<"\t";
                  input1>>i2;
                  while(i2==i)
                  {
                              input1>>i2;
                              if(input1.eof())
                              break;
                  }
                  i=i2;
           }
          else if(i==j)
          {
               input2>>j;
          }

          else

           {
           output<<j<<"\t" ;
           cout<<j<<"\t" ;
           input2>>j2;
           while(j2==j)
           {

                       if(input2.eof())
                       break;
                       input2>>j2;
           }
           j=j2;
           }

    }
    if(!(input1.eof()))
    while(1)
          {
           output<<i<<"\t";
           cout<<i<<"\t";
           if (input1.eof())
           break;
           input1>>i2;
           while(i2==i)
                  {
                              input1>>i2;
                              if(input1.eof())
                              break;
                  }
           i=i2;
           }
     if(!(input2.eof()))
     while(1)
          {
           output<<j<<"\t";
           cout<<j<<"\t";
           input2>>j2;
           if (input2.eof())
           break;
           while(j2==j)
           {
                       input2>>j2;
                       if(input2.eof())
                       break;
           }
           j=j2;
          }
    input1.close();
    input2.close();
    output.close();
//    system("pause");
    return(0);
}

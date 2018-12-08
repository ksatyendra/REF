#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{   int **a,rows,columns,i,j;
    cout<<"Enter the rows and columns: \n";
    cin>>rows>>columns;
    int s_r[rows],s_c[columns];
    a=new int*[rows];
    for(i=0;i<rows;i++)
    a[i]=new int[columns];
    cout<<"Enter the elements in matrix: "<<endl;
    for(i=0;i<rows;i++)
    
    {                  s_r[i]=0;
                       for(j=0;j<columns;j++)
                       {                     
                          cin>>a[i][j];
                          s_r[i]+=a[i][j];
                       }
    }
    for(i=0;i<columns;i++)
    
    {                  s_c[i]=0;
                       for(j=0;j<rows;j++)
                       {                     
                          s_c[i]+=a[j][i];
                       }
    //cout<<s_c[i]<<endl;
    }
    for(i=0;i<rows;i++)
    {
                       for(j=0;j<columns;j++)
                       cout<<a[i][j]<<"\t";
                       cout<<s_r[i]<<endl;
    }
    for(i=0;i<columns;i++)
    cout<<s_c[i]<<"\t";
    cout<<"\t"<<endl;
    system("pause");
    return(0);
}

    
    
    

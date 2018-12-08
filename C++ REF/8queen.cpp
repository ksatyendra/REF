#include<iostream>
#include<stdio.h>
using namespace std;
int count;
void eightqueen(int r,int a[][8])
{
   if(r==8)
   {

     count++;
     int j=0;
     for(int i=0;i<8;i++)
     {
        j=0;
        while(a[i][j]!=1)
            j++;
        cout<<i+1<<"\t"<<j+1<<endl;
     }
   }
   else
   {
        for(int j=0;j<9;j++)
        {
            if(j!=0)
            a[r][j-1]=0;
        if(j<8)
        {
            int k,l;
            for(k=0;k<8 && a[r][k]!=1;k++);
            if(k==8)
            {
            for(k=0;k<8 &&a[k][j]!=1;k++);
            if(k==8)
            {
		      k=r;l=j;
		      while(k<8 && l>=0 && a[k][l]!=1){k++;l--;}

			  if(k==8 || l==-1)
			  {
			     k=r;l=j;
			     while(k>=0 && l<8 && a[k][l]!=1){k--;l++;}


				if(k==-1 || l==8)
				{
				   k=r;l=j;
				   while(k>=0 && l>=0 && a[k][l]!=1){k--;l--;}


				       if(k==-1 || l==-1)
				       {
					   k=r;l=j;
					   while(k<8 && l<8 && a[k][l]!=1){k++;l++;}

					      if(k==8 || l==8)
					      {
						  a[r][j]=1;
						  eightqueen(r+1,a);
					      }
                        }
                        }
                    }
                }
            }
        }
      }
   }
}
int main()
{
    int a[8][8];
    for(int i=0;i<8;i++)
    {
	 for(int j=0;j<8;j++)
	 {
	    a[i][j]=0;
	 }
    }
    eightqueen(0,a);
    cout<<count;
}

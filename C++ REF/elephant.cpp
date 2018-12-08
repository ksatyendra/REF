#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
string process7(int *a,int *b);
string process4(int *a,int *b);
void solve(int a[],int b[])
{
   string s="";
   s=s+process7(a,b)+process7(b,a);
   s=s+process4(a,b)+process4(b,a);
   cout<<s<<endl;
}
string process4(int *a,int *b)
{
   string s="";
   int i=3;
   while(a[4]!=0 && i>=0)
   {
      if(b[i]!=0)
      {
         s+='4';
         a[4]--;
         b[i]--;
         continue;
      }
      i--;
   }
   while(a[4]!=0)
   {
      if(b[4]!=0)
      {
         s+='4';
         a[4]--;
         b[4]--;
         continue;
      }
      break;
   }
   return s;
}
string process7(int *a,int *b)
{
   string s="";
   int i=6;
   while(a[7]!=0 && i>=0)
   {
      if(b[i]!=0)
      {
         s+='7';
         a[7]--;
         b[i]--;
         continue;
      }
      i--;
      if(i==4) i--;
   }
   i=4;
   while(a[7]!=0)
   {
      if(b[i]!=0)
      {
         s+='7';
         a[7]--;
         b[i]--;
         continue;
      }
      if(i==7) break;
      i=7;
   }
   return s;
}
int main()
{
   int t;
   char c;
   string s;
   scanf("%d",&t);
   scanf("%c",&c);
   while(t--)
   {

      int a[10],b[10],i;
      scanf("%c",&c);
      memset(&a,0,10*4);
      memset(&b,0,10*4);
      while(c!='\n')
      {
         a[c-'0']++;
         scanf("%c",&c);
      }
      scanf("%c",&c);
      while(c!='\n')
      {
         b[c-'0']++;
         scanf("%c",&c);
      }
      solve(a,b);
   }
   //system("pause");
   return 0;
}

import java.io.*;
import java.util.*;
class Fibonacci
{
  public static void main(String args[])
  {
   int a=0,b=1,c;
   System.out.println("Enter n value:");
   Scanner sc=new Scanner(System.in);
   int n=sc.nextInt();
   int i=0;
   System.out.println("fibonacci series for n is:");
   System.out.print(a+" "+b+" ");
   while(i<=n)
   {
     c=a+b;
     a=b;
     b=c;
     System.out.print(c+" ");
     i++;
   }
 }
}

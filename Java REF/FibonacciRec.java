import java.lang.*;
import java.util.*;
class FibonacciRec
{
  public static void main(String args[])
  {
     int a=0,b=1;
     Recurssion fr=new Recurssion();
     Scanner sc=new Scanner(System.in);
     System.out.println("Enter n value:");
     int n=sc.nextInt();
     System.out.println("Fibanacci series for n is:");
     System.out.print(" "+a+" "+b+" "); 
     fr.recurssion(n,a,b);
   }
}
class Recurssion
{
  int i=0;
  public void recurssion(int n,int a,int b)
  {
     int c;
     if(i<=n)
     {
       c=a+b;
       a=b;
       b=c;
       System.out.print(c+" ");
       i++;
      recurssion(n,a,b);
     }
  }
}
   


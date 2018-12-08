import java.io.*;
import java.lang.*;
import java.util.*;
class Quadratic
{
  public static void main(String args[])
  {
    int a,b,c,d;
    double e,f;
    System.out.println("Enter a,b,c vaues:");
    Scanner sc=new Scanner(System.in);
    a=sc.nextInt();
    b=sc.nextInt();
    c=sc.nextInt();
    System.out.println("Entered values are a="+a+" b="+b+" c="+c);
    d=((b*b)-(4*a*c));
    if(d<0)
    {
      System.out.println("No real roots");
    }
    else
    {
     e=((-b+Math.sqrt(d))/(2*a));
     f=((-b-Math.sqrt(d))/(2*a));
     System.out.println("Roots are"+e+" "+f);
    }
  }
}
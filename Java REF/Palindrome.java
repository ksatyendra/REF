import java.util.*;
import java.io.*;
import java.lang.*;
class Palindrome
{
 public static void main(String args[])
  {
    	Scanner sc=new Scanner(System.in);
     	System.out.println("Enter the string:");
     	String s=sc.nextLine(); 
    	StringBuffer s1=new StringBuffer(s);
   	 String rev=s1.reverse().toString();
    	if(s.equals(rev))
   	{
      		System.out.println(s+" :is a palindrome");
   	}
  	  else
 	 {
     		 System.out.println(s+" :is not a palindrome");
  	}
 }
}
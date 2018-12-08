import java.io.*;
class Sal
{
 	public static void main(String args[])throws ArithmeticException
{
	try
	{
	 int d=0;
 	int a=42/d;
	}
	catch(Exception e)
	{
	System.out.println("exception:"+e);
	}
	finally{
 	System.out.println("hi");
	}

}
}
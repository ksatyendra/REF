public class VDemo
{
static public void main(String args[])
{
try
{
	
	int d[]={12,13,14};
	d[3]=89;
	int a=5,b=0,c;
	c=a/b;
	System.out.println("c is:"+c);
}
catch(ArrayIndexOutOfBoundsException  aie)
{
	System.out.println("I caught the exception:"+aie);
}

catch(ArithmeticException e)
{
	System.out.println("I caught the exception:"+e);
}
finally
{
	System.out.println("okay");
}
}
}
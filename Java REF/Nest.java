class Nest
{
public static void main(String args[])
{
try
{
	int a=args.length;
	int b=42/a;
	System.out.println("a is:"+a);
	try
	{
		if(a==1)
		a=a/(a-a);
		if(a==2)
		{
			int c[]={1};
			c[42]=49;
		}
	}
	catch(ArithmeticException e)
	{
		System.out.println("Exception:"+e);
	}
}
catch(ArrayIndexOutOfBoundsException aie)
{
	System.out.println("Exception:"+aie);
}
}
}	
			
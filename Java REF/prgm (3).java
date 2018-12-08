class C
{
	void method1()
	{
		try
		{
			String str="Hello";
			char ch=str.charAt(5);
		}
		catch(StringIndexOutOfBoundsException sie)
		{
			System.out.println("please see the index is with in the range");
			throw sie; //re throw the exception
		}
	}
}
class D
{
	static public void main(String []args)
	{
		C c=new C();
		try
		{
			c.method1();
		}
		catch(StringIndexOutOfBoundsException sie)
		{
			System.out.println("i caught rethrown exception:"+sie);
		}
	}
}
		

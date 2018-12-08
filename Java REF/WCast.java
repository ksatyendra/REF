class One
{
 public void show1()
{
 	System.out.println("hi");
}
}
class Two extends One
{
	public void show2()
{
 	System.out.println("hello");
}
}
class WCast
{
 public static void main(String args[])
	{
		One  o=new Two();
		o.show1();
		
	}
} 

 	
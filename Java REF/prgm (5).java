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
class NCast
{
 public static void main(String args[])
	{
		One  o=(One) new Two();
		Two t=(Two)o;
		t.show1();
		t.show2();
	}
} 

 	
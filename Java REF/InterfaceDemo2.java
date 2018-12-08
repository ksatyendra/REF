interface Animal
{
	public abstract void moves();
}
interface Bird
{
	void fly();
}
public class InterfaceDemo2 implements Animal,Bird
{
	public void moves()
	{
		System.out.println("animal move on land");
	}
	public void fly()
	{
		System.out.println("birds fly in air");
	}
	public static void main(String args[])
	{
		InterfaceDemo2 id=new InterfaceDemo2();
		id.moves();
		id.fly();
	}
}
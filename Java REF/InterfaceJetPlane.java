interface   JetPlane
{
	
	{
		abstract int numEngine();
	}
}
class DC8 implements JetPlane
{
	public int numEngine()
	{
		return 3;
	}
}
class DC10 implements JetPlane
{
	public int numEngine()
	{
		return 4;
	}
}
public class InterfaceJetPlane
{
	public static void main(String args[])
	{
		System.out.println("No.of engines DC8 contains"+ new DC8.numEngine());
		System.out.println("No.of engines DC10 contains"+ new DC10.numEngine());
	}
}
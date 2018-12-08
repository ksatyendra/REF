class Flower
{
 public void smell()
{
 	System.out.println("flowery smell");
}
}
class Rose extends Flower
{
	public void smell()
{
 	System.out.println("rose smell");

}

 public static void main(String args[])
	{
		Flower  f=new Flower();
		Rose r=new Rose();
		f=r;
		f.smell();
		//r=f;
		r=(Rose)f;
		f.smell();
	}
} 

 	
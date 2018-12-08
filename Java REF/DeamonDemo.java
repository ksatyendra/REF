public class DeamonDemo extends Thread
{
	public void run()
	{
		for(int i=0;i<5;i++)
		System.out.println(this.getName()+" , "+i);
	}
	public static void main(String args[])
	{
		DaemonDemo d1=new DeamonDemo();
		DaemonDemo d2=new DeamonDemo();
		d1.setName("Deamon thread");
		d2.setName("Normal thread");
		d1.setDeamon(true);
		d1.setPriority(Thread.MIN_PRIORITY);
		d1.start();
		d2.start();
	}
}
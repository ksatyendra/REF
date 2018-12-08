public class DaemonDemo extends Thread
{
	public void run()
	{
		for(int i=0;i<5;i++)
		System.out.println(this.getName()+" :"+i);
	}
	public static void main(String args[])
	{
		DaemonDemo d1=new DaemonDemo();
		DaemonDemo d2=new DaemonDemo();
		d1.setName("Daemon thread");
		d2.setName("Normal thread");
		d1.setDaemon(true);
		d1.setPriority(Thread.MIN_PRIORITY);
		d1.start();
		d2.start();
	}
}
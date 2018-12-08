//single tasking using a thread
class MyThread implements Runnable
{
	public void run()
	{
		//executes tasks one by one by calling the methods.
		task1();
		task2();
		task3();
	}
	void task1()
	{
		System.out.println("this is task1");
	}
	void task2()
	{
		System.out.println("this is task2");
	}
	void task3()
	{
		System.out.println("this is task3");
	}
}
class Sin
{
	public static void main(String args[])
	{
		MyThread obj=new MyThread();
		Thread t1=new Thread(obj);
		t1.start();
	}
}

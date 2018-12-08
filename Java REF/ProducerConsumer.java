/**9.b) Write a Java program  that correctly  implements producer consumer problem using  the concept of  inter
thread communication.*/
//java program for producer and consumer--inter thread communication

class Producer implements Runnable
{
	Thread1 t;
	Producer(Thread1 t)
	{
		this.t=t;
		new Thread(this,"Producer").start();
	}
	public void run()
	{
		int i=0;
		while (true)
		{
			t.put(i++);
		}
	}
}
class Consumer implements Runnable
{
    Thread1 t;
	Consumer(Thread1 t)
	{
		this.t=t;
		new Thread(this,"Consumer").start();
	}
	public void run()
	{
		int i=0;
		while (true)
		{
			t.get();
		}
	}
}
class  ProducerConsumer
{
	public static void main(String[] args) 
	{
		
		Thread1 t=new Thread1();
		new Producer(t);
		new Consumer(t);
		
	}
}


class CThread extends Thread
{
	
	 public void run() 
	{
		void task1();
		void task2();
		void task3();
	}
}
void tak1()
{
		
				
				System.out.println("good morning");
		
}
void task2()
{
	
		
				
				System.out.println("hello");
		
}
void task3()
{
	
	
		
				
				System.out.println("welcome");
	
}
class SThread
{
	public static void main(String args[]) 
	{
		CThread obj=new CThread();
		Thread t=new Thead(obj);
		t.start();
		
		
	}
}


import java.io.*;
   class A
{
    final void display()
  {
	System.out.println("hi");
   }
     
	
} 
class B extends A
{
	void display()
	{
		super.display();
		System.out.println("hello");
		
		
	}
	 static public void main(String args[])
	{
		B b=new B();
		b.display();
		
		
		
	}
}
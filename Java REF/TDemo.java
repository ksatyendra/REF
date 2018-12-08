import java.io.*;
class MyThread implements Runnable
{ 
	boolean stop=false;
	public void run () 
  	{  
		for (int i = 0;i<=100000;i++) 
    		{ 
      			System.out.print (i + "\t"); 
      			if(stop==true) return;  //come out of run 
    		} 
  	} 
} 
class TDemo 
{ 
	 public static void main(String args[]) throws IOException 
  	{ 
		 MyThread obj = new MyThread (); 
    		Thread t = new Thread (obj); 
   		 t.start ();//stop the thread when enter key is pressed
   		System.in.read();
  		obj.stop=true;     
  	} 
} 
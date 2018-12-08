import java.io.*;
final class Demo1
{
    public void display()
     {
         System.out.println("hi");
      }
}
public class Demo3 extends Demo1 
{
   public static void main(String args[])
     {
         Demo1 d=new Demo1();
         d.display();
          
 }
}
    

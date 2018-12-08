import java.io.*;
import java.util.*;
class Scan
{
 static
   {
     System.out.println("Enter id name sal:");
     Scanner sc=new Scanner(System.in);
     int id=sc.nextInt();
     String name=sc.next();
     Float sal=sc.nextFloat();
    System.out.println("Id="+id);
    System.out.println("name="+name);
    System.out.println("sal="+sal);
    System.exit(0);
  }
}
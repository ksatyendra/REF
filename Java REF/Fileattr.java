import java.io.*;
import java.util.*;
class Fileattr
{
   public static void main(String args[])
   {
     File f1=new File(args[0]);
     System.out.println(f1.exists()?"file exists":"does not exist");
     System.out.println("Filename:"+f1.getName());
     System.out.println("Filepath:"+f1.getAbsolutePath());
     System.out.println(f1.isDirectory()?"is a directory":"is a simple file");
     System.out.println(f1.canRead()?"can be read":"can not be read");
     System.out.println(f1.canWrite()?"can be write":"can not be write");
     System.out.println("length of file in bytes:"+f1.length());
  }
}
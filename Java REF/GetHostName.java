import java.net.*;
import java.io.*;

public class GetHostName{
 public static void main(String [] args) {
   try {
        InetAddress addr = InetAddress.getByName("98.139.183.24");
       String hostname = addr.getHostName();
      System.out.println("hostname="+hostname);
    } catch (UnknownHostException e) {
    }

    }
}
import java.lang.*;
import java.io.*;
import java.net.*;
import java.net.InetAddress;
public class Client
{
 public static void main(String args[])
 {
 Socket sock=null;
 DataInputStream dis=null;
 PrintStream ps=null;
 System.out.println(" Trying to connect");
                                   
 try 
 {
 // to get the ip address of the server by the name
              
 InetAddress ip =InetAddress.getByName("www.calsoftlabs.com");

 // Connecting to the port 1025 declared in the Serverclass
 // Creates a socket with the server bind to it.

  sock= new Socket(ip,Server.PORT);
  ps= new PrintStream(sock.getOutputStream());
  ps.println(" Hi from client");
  DataInputStream is = new DataInputStream(sock.getInputStream());
  System.out.println(is.readLine());

 }
 catch(SocketException e)
 {
  System.out.println("SocketException " + e);
 }

 catch(IOException e)
 {
  System.out.println("IOException " + e);
 }

  // Finally closing the socket from the client side

 finally
 {
 try
  {
   sock.close();
  }
  catch(IOException ie)
  {
   System.out.println(" Close Error   :" +  ie.getMessage());
  }               
 }  // finally 
                        
} // main 
}   // Class Client 

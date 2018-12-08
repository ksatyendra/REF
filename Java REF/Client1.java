// a client that accepts data from server 
import java.util.*; 
import java.io.*; 
import java.net.*; 
class Client1 
{  public static void main(String args[]) throws IOException 
  {  //Create client socket 
    Socket s = new Socket ("localhost", 777); 
    //attach input stream to Socket 
    InputStream obj = s.getInputStream (); 
    //to receive data from socket 
    BufferedReader br = new BufferedReader (new InputStreamReader (obj)); 
    //read data coming from server 
    String str; 
    while ((str = br.readLine() ) != null ) 
      System.out.println (str); 
    //close connection 
       s.close (); 
    br.close (); 
  } 
} 
 
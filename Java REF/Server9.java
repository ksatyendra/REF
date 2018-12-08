import java.net.*; 
import java.io.*; 
class Server9
{  public static void main(String args[]) throws IOException 
  {  //create a server socket 
    ServerSocket ss = new ServerSocket (888); 
    //accept client connection 
    Socket s = ss.accept (); 
    System.out.println ("A connection is established..."); 
    //to send data to client 
    PrintStream ps = new PrintStream (s.getOutputStream ()); 
    //to receive data from client 
    BufferedReader br = new BufferedReader (new InputStreamReader  
                                                                                                   (s.getInputStream ())); 
    //to accept data from keyboard to sent to client 
    BufferedReader kb = new BufferedReader (new InputStreamReader (System.in));
while (true)   //server runs continuously 
{  String str, str1; 
  while ( (str= br.readLine() ) != null) 
  {  System.out.println (str); 
    str1 = kb.readLine (); 
    ps.println (str1); 
  } 
  s.close ();  ss.close ();     
  System.exit (0);
    } 
  } 
}     

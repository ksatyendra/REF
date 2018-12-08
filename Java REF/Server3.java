import java.io.*;
import java.net.*;
import java.util.*;

public class Server3 {
public  static void  main (String args [ ] ) {
try {
// create a server socket
ServerSocket s = new ServerSocket(80);

// start listening for connections on srver socket
Socket connectToClient = s.accept();

// create a buffered reader stream to get data from client
BufferedReader isFromClient = new BufferedReader(new InputStreamReader (connectToClient.getInputStream()));

// create a buffer reader to send result to client
PrintWriter osToClient = new PrintWriter(connectToClient.getOutputStream(), true);

// continuously read from client, process, send back
while (true) {
// read a line and create string tokenizer
StringTokenizer st = new StringTokenizer(isFromClient.readLine());

//convert string to double
double radius = new Double(st.nextToken()).doubleValue();

// display radius on console
System.out.println("Radius received from client: " + radius);

// comput area
double area = radius * radius *Math.PI;

// send result to client
osToClient.println(area);

// print result on console
System.out.println("Area found: "+area);
}
} catch (IOException e) {
System.err.println(e);
}
}
}
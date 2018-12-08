import java.io.*;
import java.net.*;
import java.util.*;

public class Client3 {
public  static void main (String args [ ] ) {
try {
// create a socket to connect to server
Socket connectToServer = new Socket("local host", 80);

// create a buffered input stream to get result from server
BufferedReader isFromServer = new BufferedReader(new InputStreamReader (connectToServer.getInputStream()));

// create a buffer output stream to send data to server
PrintWriter osToServer = new PrintWriter(connectToServer.getOutputStream(), true);

// continuously send radius and get area
while (true) {
Scanner input=new Scanner(System.in);
System.out.print("Please enter a radius: ");
double radius =input.nextDouble();

// display radius on console
osToServer.println(radius);

// get area from server
StringTokenizer st = new StringTokenizer(isFromServer.readLine());

// convert string to double
Double area = new Double(st.nextToken()).doubleValue();

// print result on console
System.out.println("Area received from the server is: " +area);
}
} catch (IOException e) {
System.err.println(e);
}
}
}
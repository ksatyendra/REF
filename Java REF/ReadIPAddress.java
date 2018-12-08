import java.net.*;
import java.io.*;

public class ReadIPAddress{
	public static void main(String[] args )throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the host name: ");
		String hostname = input.readLine();
		try {
			InetAddress inetadd = InetAddress.getByName(hostname);
			System.out.println("IP address is: " + inetadd.getHostAddress());
		}
		catch(UnknownHostException e ){
			System.out.println("Could not find IP address for: " + hostname);
		}
	}
}

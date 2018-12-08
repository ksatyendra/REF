import java.net.*;
import java.io.*;

public class IPReverseTest {
	public static void main (String[] args) {
		try {
			InetAddress ia = InetAddress.getByName("74.125.236.49");
			System.out.println(ia.getHostName());
		}
		catch (Exception ex) {
			System.err.println("does not fine hostname");
		}
	}
}
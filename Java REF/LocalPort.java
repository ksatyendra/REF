import java.net.*;
import java.io.*;

public class LocalPort{
	public static void main(String[] args) {
		for (int i = 1; i <= 7000; i++) {
			try {
				ServerSocket server = new ServerSocket(i);
			}
			catch (IOException e) {
				System.out.println("There is a server on port " + i + ".");
			}
		}
	}
}
import java.net.*;

public class Hostname{
	public static void main(String args[]){
		try{
			InetAddress local= InetAddress.getLocalHost();
			System.out.println ("Local hostname is: " + local.getHostName());
		}
		catch (UnknownHostException e){
			System.err.println ("Can't detect localhost : " + e);
		}
	}
}
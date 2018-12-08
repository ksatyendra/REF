import java.net.*;

public class Ipaddress{
	public static void main(String args[]){
		try{
			InetAddress local= InetAddress.getLocalHost();
			System.out.println ("Local IP Address is : " + local);
		}
		catch (UnknownHostException e){
			System.err.println ("Can't detect IP Address : " + e);
		}
	}
}
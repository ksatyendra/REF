//knowing IP address of a website
import java.io.*;
import java.net.*;
class Website
{
	public static void main(String args[])throws IOException
	{
		//accept name of website from keyboard
		
		try
		{
			//getByName() method accepts site name and returns its IP address
			InetAddress ia=InetAddress.getByName("74.125.236.52");
			System.out.println("The host is :"+ ia.getHostName());
		}
		catch(UnknownHostException ue)
		{
			System.out.println("website not found");
		}
	}
}
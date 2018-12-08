//knowing IP address of a website
import java.io.*;
import java.net.*;
class Address
{
	public static void main(String args[])throws IOException
	{
		//accept name of website from keyboard
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter a website name:");
		String site=br.readLine();
		try
		{
			//getByName() method accepts site name and returns its IP address
			InetAddress ip=InetAddress.getByName(site);
			System.out.println("The IP address is :"+ ip);
			
		}
		catch(UnknownHostException ue)
		{
			System.out.println("website not found");
		}
	}
}
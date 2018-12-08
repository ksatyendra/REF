import java.net.*;
import java.io.*;
public class HostLookup 
{
	public static void main (String[] args) 
	{
		if (args.length > 0) 
		{ 
			for (int i = 0; i < args.length; i++) 
			{
				System.out.println(lookup(args[i]));
			}
		}
		else 
		{	
			BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter the website name ");
			System.out.println("Enter \"exit\".");
			try {
				while (true) 
				{
					String host = buffer.readLine();
					if (host.equalsIgnoreCase("exit")) 
					{
						break;
					}
					System.out.println(lookup(host));
				}
			}
			catch (IOException ex) 
			{
				System.err.println(ex);
			}
		}
	}
	private static String lookup(String hostname) 	{
		InetAddress node;
		try {
			node = InetAddress.getByName(hostname);
		}
		catch (UnknownHostException ex) {
			return "Cannot find host " + hostname;
		}
		if (isHostname(hostname)) {
			return node.getHostAddress();
		}
		else {  
			return node.getHostName();
		}
	}
	private static boolean isHostname(String host) 
	{

    	// Is this an IPv6 address?
    		if (host.indexOf(':') != -1) return false;
      
    		char[] ca = host.toCharArray();
		for (int i = 0; i < ca.length; i++) 
		{
			if (!Character.isDigit(ca[i])) 
			{
				if (ca[i] != '.') return true;
			}
		}
    		return false;

   	} 

 } 


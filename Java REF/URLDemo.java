import  java.net.*;
public class URLDemo{
	
	public static void main(String args[])throws MalformedURLException{
		URL obj  = new  URL("98.139.183.24");
		System.out.println("Protocal:" +  obj.getProtocol());
		System.out.println("Port:" +  obj.getPort());
		System.out.println("Host:" +  obj.getHost());
		System.out.println("File:" +  obj.getFile());
		System.out.println("path:" +  obj.getPath());
		System.out.println("Ext:" + obj.toExternalForm());
	}
}

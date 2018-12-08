import java.net.InetAddress;
import java.net.UnknownHostException;
import java.lang.System;

public class NSLookupApp {
 public static void main(String args[]) {
  try {
   if(args.length!=1){
    System.out.println("Usage: java NSLookupApp hostName");
    return;
   }
   InetAddress host = InetAddress.getByName(args[0]);
   String hostName = host.getHostName();
   byte ipAddress[] = host.getAddress();
   System.out.println("Host name: "+hostName);
   System.out.print("IP address: ");
   for(int i=0;i<ipAddress.length;++i)
    System.out.print((ipAddress[i]+256)%256+".");
   System.out.println();
  }catch(UnknownHostException ex) {
   System.out.println("Unknown host");
   return;
  }
 }
}
  // In file network/ex2/SummerClient.java
  import java.net.*;
 import java.io.*;
  public class SummerClient {
      public static void main(String[] args)throws IOException {
        InetAddress ia = InetAddress.getByName(null);
         Socket sock = new Socket(ia,SummerServer.PORT);
         try {
           	BufferedReader serverReader =new BufferedReader(new InputStreamReader(sock.getInputStream()));
	BufferedWriter serverWriter =new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));

            LineNumberReader stdinReader =new LineNumberReader(new BufferedReader(new InputStreamReader(System.in)));

             for (;;) {
              String userLine = stdinReader.readLine();
              if (userLine == null ||userLine.length() == 0) {
                     break;
	}
                 serverWriter.write(userLine);
             serverWriter.newLine();
                serverWriter.flush();
                String serverLine =serverReader.readLine();
                 System.out.println(serverLine);
          }
        }
         finally {
           sock.close();
        }
  }
 }


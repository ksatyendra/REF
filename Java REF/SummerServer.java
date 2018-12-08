   // In file network/ex2/SummerServer.java
  import java.net.*;
   import java.io.*;
   import java.util.StringTokenizer;
  
   public class SummerServer {
  
      public static final int PORT = 2000;
       private static class InvalidLongException extends Exception {
          private String message;
          InvalidLongException(String s) {
              message = s;
         }
          public String getMessage() {
          return message;
         }
     }
      private static class SummerService extends Thread {
         private Socket sock;
     public SummerService(Socket sock) {
             this.sock = sock;
          }
         public void run() {
              try {
                  BufferedReader reader =new BufferedReader(new InputStreamReader(sock.getInputStream()));
                  BufferedWriter writer =new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
                 for (;;) {
                     String s = reader.readLine();
                    if (s == null) {
                          break;
                     }
                    String outString;
                      try {
                        outString =
                             Long.toString(sumString(s));
                      }
                    catch(InvalidLongException e) {
                     outString = e.getMessage();
                     }
                      writer.write(outString);
                     writer.newLine();
                    writer.flush();
            }
              }
         catch (IOException e) {
             }
              finally {
                  try {
                     sock.close();
                 }
               catch (IOException e) {
               }
           }
         }
      }
      public static void main(String[] args)throws IOException {
          ServerSocket listener = new ServerSocket(PORT);
          try {
             for (;;) {
                 Socket sock = listener.accept();
                 SummerService ss =
                  new SummerService(sock);
                 ss.start();
          }
          }
       finally {
             listener.close();
         }
   }
     private static long sumString(String s)throws InvalidLongException {
        long sum = 0;
        StringTokenizer st = new StringTokenizer(s);
       String token;
      while (st.hasMoreTokens()) {
             token = st.nextToken();
             try {
               sum += Long.parseLong(token);
            }
            catch (NumberFormatException e) {
                 throw new InvalidLongException(
                    "Invalid number: " + token);
          }
       }

        return sum;
    }
 }

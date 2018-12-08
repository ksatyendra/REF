import java.util.regex.*;
import java.io.*;
public class EmailValidation {
   public static void main(String[] args) 
                                 throws Exception {
                                 
      String input = "@sun.com";
      //Checks for email addresses starting with
      //inappropriate symbols like dots or @ signs.
      Pattern p = Pattern.compile("^\\.|^\\@");
      Matcher m = p.matcher(input);
      if (m.find())
         System.err.println("Email addresses don't start" +
                            " with dots or @ signs.");
      //Checks for email addresses that start with
      //www. and prints a message if it does.
      p = Pattern.compile("^www\\.");
      m = p.matcher(input);
      if (m.find()) {
        System.out.println("Email addresses don't start" +
                " with \"www.\", only web pages do.");
      }
      p = Pattern.compile("[^A-Za-z0-9\\.\\@_\\-~#]+");
      m = p.matcher(input);
      StringBuffer sb = new StringBuffer();
      boolean result = m.find();
      boolean deletedIllegalChars = false;

      while(result) {
         deletedIllegalChars = true;
         m.appendReplacement(sb, "");
         result = m.find();
      }

      // Add the last segment of input to the new String
      m.appendTail(sb);

      input = sb.toString();

      if (deletedIllegalChars) {
         System.out.println("It contained incorrect characters" +
                           " , such as spaces or commas.");
      }
   }
}

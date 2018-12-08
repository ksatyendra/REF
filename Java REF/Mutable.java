import java.io.*; 
class Mutable 
{  public static void main(String[] args) throws IOException 
  {  // to accept data from keyboard 
  BufferedReader br=new BufferedReader (new InputStreamReader (System.in)); 
    System.out.print ("Enter sur name : "); 
    String sur=br.readLine ( ); 
    System.out.print ("Enter mid name : "); 
    String mid=br.readLine ( ); 
    System.out.print ("Enter last name : "); 
    String last=br.readLine ( ); 
    // create String Buffer object 
    StringBuffer sb=new StringBuffer ( ); 
    // append sur, last to sb 
    sb.append (sur); 
    sb.append (last); 
    // insert mid after sur 
    int n=sur.length ( ); 
    sb.insert (n, mid); 
    // display full name 
    System.out.println ("Full name = "+sb); 
    System.out.println ("In reverse ="+sb.reverse ( )); 
  } 
} 
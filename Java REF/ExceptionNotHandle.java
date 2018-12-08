import java.io.*; 
class Sample 
{  
void accept( ) throws IOException 
  { 
   BufferedReader br=new BufferedReader (new InputStreamReader(System.in)); 
    System.out.print ("enter ur name: "); 
    String name=br.readLine ( ); 
    System.out.println ("Hai "+name); 
  } 
} 
class ExceptionNotHandle 
{  public static void main (String args[]) 
  { 
    Sample s=new Sample ( ); 
    s.accept ( ); 
  } 
} 
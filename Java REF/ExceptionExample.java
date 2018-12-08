class ExceptionExample 
{  public static void main(String args[]) 
{  try 
    {  System.out.println ("open files"); 
      int n=args.length; 
      System.out.println ("n="+n); 
      int a=45/n; 
      System.out.println ("a="+a); 
      int b[]={10,19,12,13}; 
      b[50]=100; 
    } 
    catch (ArithmeticException ae) 
    {  System.out.println ("i caught the exception:"+ae); 
      System.out.println ("plz type data while executing the program"); 
    } 
    catch (ArrayIndexOutOfBoundsException aie) 
    {  System.out.println ("i caught the exception:"+aie); 
      System.out.println ("please see that array index is not within the range"); 
    } 
    finally 
    {    System.out.println ("close files"); 
    } 
} 
} 
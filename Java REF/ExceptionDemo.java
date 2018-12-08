public class ExceptionDemo
{
   public static void main(String args[])throws ArrayIndexOutOfBoundsException
   {
      int subject[]={12,23,34,21};
      try
      {
        System.out.println(subject[4]);
        System.out.println("not okay");
      }
      catch(ArrayIndexOutOfBoundsException e)
     {
       System.out.println("i caught the exception:"+e);
        throw e;
      }
    finally
    {
      System.out.println("okay");
     }
  }
}
      
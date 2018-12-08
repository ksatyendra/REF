import java.util.*;
public class Demo5
{
	public static void main(String args[])
	{
		String s=new String("welcome to java");
  		StringTokenizer st=new StringTokenizer(s);
  		int n=st.countTokens();
  		System.out.println(n);
  		while(st.hasMoreTokens())
  		{
     			System.out.println(st.nextToken());
 		}
		
	}
}
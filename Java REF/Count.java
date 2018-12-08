import java.util.*;
import java.io.*;
import java.lang.*;
class Count
{
    public static void main(String[] args) 
    {
	Scanner sc = new Scanner(System.in);
       	Scanner input=new Scanner(System.in);
       	System.out.print("Enter string: ");
       	String st=input.nextLine();
	System.out.println("Enter the word u want to count");
	String findWord = sc.nextLine();
        	int count=0;
        	StringTokenizer stk=new StringTokenizer(st," ");
       	while(stk.hasMoreTokens())
	{
            		String token=stk.nextToken();
		if(findWord.equalsIgnoreCase(token))
		{
            			count++;
		}
        	}
       	 System.out.println("Number of words are: "+count);
    }
}
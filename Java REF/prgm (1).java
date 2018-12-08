import java.io.*;
import java.lang.*;
abstract class B
{
	abstract void push(int item);
	abstract void pop();
	abstract void show();
}
class C extends B
{
	int st[];
	int top;
	C(int n)
	{
		st=new int[n];
		top=-1;
	}
	public void push(int item)
	{
		if(top==st.length-1)
		System.out.println("stack is full");
		else
		st[++top]=item;
	}
	void show()
	{
		for(int i=0;i<=top;i++)
		System.out.println(st[i]);
	}
	void pop()
	{
		if(top==-1)
		System.out.println("stack is empty");
		else
		top--;
	}
}
class A
{
	public static void main(String args[])throws IOException,NumberFormatException
	{
		System.out.println("enter the size of stack:");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		C s=new C(n) ;
		int ch,item;
		do
		{
			System.out.println("1.push");
			System.out.println("2.pop");
			System.out.println("3.show");
			System.out.println("4.exit");
			System.out.println("enter ur choice:");
			ch=Integer.parseInt(br.readLine());
			switch(ch)
			{
				case 1: System.out.println("enter elements:");
				            item=Integer.parseInt(br.readLine());
				            s.push(item);
				            break;
				case 2: s.pop();
				            break;
				case 3: s.show();
				            break;
				case 4: System.exit(0);
				            break;
			}
		}while(true);
	}
}
				
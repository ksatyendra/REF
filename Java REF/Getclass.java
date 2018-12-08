import java.io.*;
import java.util.*;
class Myclass
{
	int x;
	Myclass(int x)
	{
		this.x=x;
	}
}
class GetName
{
	static void printName(Object obj)
	{
		Class c=obj.getClass();
		String name=c.getName();
		System.out.println("the class name:"+name);
	}
}
class Getclass
{
	static	
	{
		Myclass obj=new Myclass(10);
		GetName.printName(obj);
		System.exit(0);
	}
	
}
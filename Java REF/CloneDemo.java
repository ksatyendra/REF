import java.io.*;
import java.util.*;
class Employee implements Cloneable
{
	int id;
	String name;
	Employee(int id,String name)
	{
		this.id=id;
		this.name=name;
	}
	void getData()
	{
		System.out.println("id:"+id);
		System.out.println("name:"+name);
	}
	public Object myClone() throws CloneNotSupportedException
	{
		return super.clone();
	}
}
class CloneDemo
{
	public static void main(String args[])throws CloneNotSupportedException
	{
		Employee e1=new Employee(10,"cnu");
		System.out.println("original object:");
		e1.getData();
		Employee e2=(Employee)e1.myClone();
		System.out.println("cloned object:");
		e2.getData();
		System.exit(0);
	}
}
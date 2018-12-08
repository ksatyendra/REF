import java.io.*;
import java.util.*;
class Stack1
{
int top=-1,st[]=new int[5];
void push(int el)
{
st[++top]=el;
}
int pop()
{
return(st[top--]);
}
void display()
{
System.out.println("\nStack elements from top to bottom\n");
for(int i=top;i>=0;i--)
System.out.println(st[i]);
}
boolean isFull()
{
return(top==5-1);
}
boolean isEmpty()
{
return(top==-1);
}
}
class Stack
{
public static void main(String a[])
{
Scanner sc=new Scanner(System.in);
Stack1 s=new Stack1();
int el=0,ch=1;
while(ch!=4)
{
System.out.println("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
System.out.println("ENTER YOUR CHOICE");
ch=sc.nextInt();
switch(ch)
{
case 1:if(s.isFull())
	System.out.println("\nstack is full");
	else
	{
	System.out.println("Enter element");
	el=sc.nextInt();
	s.push(el);		
	}break;
case 2:if(s.isEmpty())
	System.out.println("\nstack is empty");
	else
	{
	el=s.pop();
	System.out.println("\nDeleted element = "+el);		
	}break;	
case 3:if(s.isEmpty())
	System.out.println("\nstack is empty");
	else
	s.display();
	break;
case 4:break;
default:System.out.println("\nEnter correct choice");
}
}
}
}
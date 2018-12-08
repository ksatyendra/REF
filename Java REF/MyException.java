 class MyException extends Exception 
        { 
    int accno[] = {1001,1002,1003,1004,1005}; 
String name[] = {"Hari","Siva","Bhanu","Rama","Chandu"}; 
double bal[] = {2500,3500,1500,1000,6000}; 
MyException() 
{ 
} 
MyException(String str) 
{ 
  super(str); 
} 
public static void main(String args[]) 
{ 
  try 
  { 
    MyException me = new MyException(""); 
    System.out.println("AccNo \t Name \t Balance "); 
    for(int i=0;i<5;i++) 
    { 
      System.out.println(me.accno[i]+ "\t" + me.name[i] + "\t" +  
me.bal[i] ); 
      if( me.bal[i]  < 2000 ) 
    { 
      MyException me1 = new MyException  
("Insufficient Balance"); 
      throw me1; 
    } 
  } 
} 
catch(MyException  e) 
{ 
  e.printStackTrace(); 
} 
}
}
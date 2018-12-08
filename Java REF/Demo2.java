import java.lang.*;
 class Protection {
int n = 1;
private int n_pri = 2;
protected int n_pro = 3;
public int n_pub = 4;
public Protection() {
System.out.println("base constructor");
System.out.println("n = " + n);
System.out.println("n_pri = " + n_pri);
System.out.println("n_pro = " + n_pro);
System.out.println("n_pub = " + n_pub);
}
}
class Protection2 extends Protection {
Protection2() {
System.out.println("derived other package constructor");
//  class or package only
//  System.out.println("n = " + n);
//  class only
//  System.out.println("n_pri = " + n_pri);
System.out.println("n_pro = " + n_pro);
System.out.println("n_pub = " + n_pub);
}
}
class OtherPackage {
OtherPackage() {
Protection p = new Protection();
System.out.println("other package constructor");
//  class or package only
//  System.out.println("n = " + p.n);
//  class only
//  System.out.println("n_pri = " + p.n_pri);
//  class, subclass or package only
//  System.out.println("n_pro = " + p.n_pro);
System.out.println("n_pub = " + p.n_pub);
}
}
// Instantiate the various classes in p2.
public class Demo2 {
public static void main(String args[]) {
Protection2 ob1 = new Protection2();
OtherPackage ob2 = new OtherPackage();
}
}


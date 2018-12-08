import javax.swing.*; 
import java.awt.Graphics; 

// <applet code="Choice.class" width=200 height=200> </applet>

public class Choice extends JApplet 
{ 
int i,ch; 

public void init() 
{ 
String input; 
input=JOptionPane.showInputDialog("enter your choice(1-lines,2-rectangles,3-ovals)"); 
ch=Integer.parseInt(input); 
} 

public void paint(Graphics g) 
{ 

switch(ch) 
{ 
case 1:
{ 
for(i=1;i<=10;i++) 
{ 
g.drawLine(10,10,250,10*i); 
} 
break; 
} 

case 2:
{ 
for(i=1;i<=10;i++) 
{ 
g.drawRect(10*i,10*i,50+10*i,50+10*i); 
} 
break; 
} 

case 3:
{ 
for(i=1;i<=10;i++) 
{ 
g.drawOval(10*i,10*i,50+10*i,50+10*i); 
} 
break; 
}
}//switch ends

}//paint ends

}//choice class ends

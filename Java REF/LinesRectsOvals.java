/**12.b) Write a Java program that allows the user to draw lines, rectangles and ovals.*/
//java program that allows user to draw lines,rectangles and ovals 
//<applet code="LinesRectsOvals.class" height="250" width="400"> </applet>
import java.applet.*;
import java.awt.*;
import javax.swing.*;
public class  LinesRectsOvals extends JApplet
{
	public void paint(Graphics g)
	{
		super.paint(g);
		g.setColor(Color.red);
		g.drawLine(5,30,350,30);
		g.setColor(Color.blue);
		g.drawRect(5,40,90,55);
		g.fillRect(100,40,90,55);
		g.setColor(Color.cyan);
		g.fillRoundRect(195,40,90,55,50,50);
		g.drawRoundRect(290,40,90,55,20,20);
		g.setColor(Color.yellow);
		g.draw3DRect(5,100,90,55,true);
		g.fill3DRect(100,100,90,55,false);
		g.setColor(Color.magenta);
		g.drawOval(195,100,90,55);
		g.fillOval(290,100,90,55);
	}
}

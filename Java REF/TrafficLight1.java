import java.awt.*; 
import java.awt.event.*; 
import javax.swing.*; 

public class TrafficLight1 
{ 
public static void main(String[] args) 
{ 
FrameCreator Frame= new FrameCreator(); 
Frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
Frame.setVisible(true); 
} 
} //TrafficLight class

class FrameCreator extends JFrame 
{ 
JPanel showPanel,radioButtonPanel; 
JRadioButton button1,button2,button3; 
ButtonGroup radioButtonGroup;

public FrameCreator() 
{ 
int height=200; 
int width=300; 
setSize(width,height); 
setLocation(0,0); 
setTitle("JRadioButton example"); 
showPanel=new JPanel(); 
radioButtonPanel=new JPanel(); 
radioButtonGroup=new ButtonGroup(); 
button1=new JRadioButton("RED",true); 
button2=new JRadioButton("GREEN",false); 
button3=new JRadioButton("YELLOW",true); 
showPanel.setBackground(Color.red); 
radioButtonGroup.add(button1); 
radioButtonGroup.add(button2); 
radioButtonGroup.add(button3); 
radioButtonPanel.add(button1); 
radioButtonPanel.add(button2); 
radioButtonPanel.add(button3); 
add(showPanel, BorderLayout.CENTER); 
add(radioButtonPanel, BorderLayout.SOUTH); 

button1.addActionListener(new ActionListener() 
{ 
public void actionPerformed(ActionEvent e) 
{ 
showPanel.setBackground(Color.red); 
repaint(); 
} 
});

button2.addActionListener(new ActionListener() 
{ 
public void actionPerformed(ActionEvent e) 
{ 
showPanel.setBackground(Color.green); 
repaint(); 
} 
}); 

button3.addActionListener(new ActionListener()
{
public void actionPerformed(ActionEvent e) 
{ 
showPanel.setBackground(Color.yellow); 
repaint(); 
} 
}); 

} 

}//FrameCreator class


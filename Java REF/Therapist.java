import java.io.*;
import java.net.*;
import java.util.Vector;
import java.util.StringTokenizer;
public class Therapist
{
	public static void main(String args[])
	{
		try
		{
			Therapist universe=new Therapist();
		}
		catch(IOException ioe)
		{
			System.out.println("an exception is received:"+ ioe);
		}
	}
	static final public int portNo=1235;
	public Therapist()throws IOException
	{
		ServerSocket s=new ServerSocket(portNo);
		while(true)
		{
			Socket skt=s.accept();
			Thread sn=new TherapySession(skt.getInputStream(),skt.getOutputStream());
			sn.start();
		}
	}
}

public class TherapySession extends Thread
{
	public TherapySession(InputStream is, OutputStream os)
	{
		Reader isr=new InputStreamReader(is);
		in=new BufferedReader(isr);
		out=new OutputStreamWriter(os);
	}
	private String name=" ";
	private BufferedReader in;
	private Writer out;
	private String response(String txt);
	{
		//replay with a question
		if(txt.endsWith("?"))
		return "y do u want to know?";
		//break the line
		Vector words=new Vector();
		StringTokenozer break=new StringTokenizer(text.toLowerCase(),",?!");
		while(break.hasMoreElements())
		words.addElement(break.nextElement());
		//search for "i feel"
		if((words.size()>1)&&words.elemntAt(0).equals("i")&&words.elementAt(1).equals("feel"))
		return "y do u feel that way?";
		//search for relatives
		for(int i=0;i<words.size();i++)
		{
			String rel=(String) words.elementAt(i);
			if(isRelative(rel))
			return "tell me about ur" +relative;
		}
		return "tell me more";
	}
	private boolean isRelative(String name)
	{
	return name.equals("mother")||name.equals("father")||name.equals("sister")||name.equals("brother")||name.equals("uncle")||name.equals("aunt");
	}

	public void run()
	{
		try
		{
			out.write("hi!,welcome to TherapySession, May I know ur name please?\n");
			out.flush();
			name=in.readLine();
			out.write("well"+name+"how can i help u?\n");
			out.flush();
			while(true)
			{
				String text=in.readLine();
				out.write(text+"\n");
				out.flush();
			}
		}
		catch(Exception ioe)
		{
			stop();
		}
	}
}

import java.io.*;
import java.net.*;
import java.util.Vector;
import java.util.StringTokenizer;
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
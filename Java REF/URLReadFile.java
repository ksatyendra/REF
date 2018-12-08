import java.net.*;
import java.io.*;
public class URLReadFile{
	public static void main(String[] args) throws IOException{
		try{
			URL url = new URL("file:///D:/java/AppletDemo.html");
			BufferedReader buff = new BufferedReader(new InputStreamReader(url.openStream()));
			String str;
			while((str = buff.readLine()) != null) {
							System.out.println("\n");
							System.out.println(str);
			}
			buff.close();
		}
		catch(IOException e){
			System.err.println(e);
		}
	}
}


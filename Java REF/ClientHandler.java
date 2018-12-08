import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;

public class ClientHandler implements Runnable {
	Socket socket;
	PrintStream out;

	ClientHandler(Socket s) {
		socket = s;
	}

	@Override
	public void run() {

		try {
			out = new PrintStream(socket.getOutputStream());
		} catch (IOException e) {
			System.out.println("PrintStream Error");
		}

		out.println("Hello");

		try {
			socket.close();
		} catch (IOException e) {
			System.out.println("Failed to close, oddly...");
		}
	}

}
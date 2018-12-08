import java.io.*; 
class StackX
{
	private int maxSize;
	private char[] stackArray;
	private int[] stackArray1;
	private int top;
	public StackX(int s) 
	{
		maxSize = s;
		stackArray = new char[maxSize];
		top = -1;
	}

	public void push(char j) 
	{
		 stackArray[++top] = j; 
	}

	public void push1(int j)
	{
 		stackArray1[++top] =j ;
	 }

	public char pop() 
	{ 
		return stackArray[top--];
	 }

	public char peek() 
	{
		 return stackArray[top];
	 }

	public boolean isEmpty() 
	{
		 return (top == -1);
	 }

	public int size() 
	{
		 return top+1;
	 }

	public char peekN(int n) 
	{
		 return stackArray[n];
	 }



} // end class StackX used from lab1

class InToPost // infix to postfix conversion borrowed from book
{
	private StackX theStack;
	private String input;
	private String output = " ";
	public InToPost(String in) // constructor
	{
		input = in;
		int stackSize = input.length();
		theStack = new StackX(stackSize);
	}

	public String doTrans() // algorithm that does translation with cases
	{
		for(int j=0; j<input.length(); j++) 
		{
			char ch = input.charAt(j); 

			switch(ch)
			{
				case '+':gotOper(ch, 1); break; 
				case '-':gotOper(ch, 1); break; 
				case '*':gotOper(ch, 2); break;	
				case '/':gotOper(ch, 2); break;
				default :output = output + ch; break; //writes to output 
			} // end of switch
		} // end for loop
		while( !theStack.isEmpty() ) // pop remaining operators at the end
		{
			output = output + theStack.pop(); // write to output
		}
		return output; // return postfix
	} 
//--------------------------------------------------------------
	public void gotOper(char opThis, int prec1)
	{ 
		while( !theStack.isEmpty() )
		{
			char opTop = theStack.pop();
			if(1==1 ) 
			{
				int prec2; 
				if(opTop=='+' || opTop=='-') // find new op prec
				prec2 = 1;
				else
				prec2 = 2;
				if(prec2 < prec1) 
				{ 
					theStack.push(opTop); 
					break;
				}
				else 
					output = output + opTop; 
			} 
		} // end while loop
	theStack.push(opThis); 
	} 
	public void evaluate() 
	{
		int x;
		int y;
		for (int j = 0; j < output.length(); j++) 
		{
			int result = 0;
			char ch = output.charAt(j);
			switch (ch) 
			{
			case '+':
				x = theStack.pop();
				y = theStack.pop();
				result = x + y;
				theStack.push1(result);
				break;
			case '-':
				x = theStack.pop();
				y = theStack.pop();
				result = x - y;
				theStack.push1(result);
				break;
			case '*':
				x = theStack.pop();
				y = theStack.pop();
				result = x * y;
				theStack.push1(result);
				break;
			case '/':
				x = theStack.pop();
				y = theStack.pop();
				result = x / y;
				theStack.push1(result);
				break;
			default:
				theStack.push(ch);
				break;
		}
	}
	System.out.println(theStack.pop());
	}

} 

class InfixToPost
{
	public static void main(String[] args) throws IOException
	{
		String input, output;
		//while(true)
		//{
			System.out.print("Enter infix: ");
			System.out.flush();
			input = getString(); 
			//if( input.equals("") ) 
			//break;
			InToPost theTrans = new InToPost(input);
			output = theTrans.doTrans(); 
			System.out.println("Postfix is " + output );
		//} 
	} 

	public static String getString() throws IOException
	{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = br.readLine();
		return s;
	}

} 
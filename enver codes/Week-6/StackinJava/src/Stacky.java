
public class Stacky {
	private int[] mystack;
	private int top;
	private int size;
	
	Stacky (int n)
	{
		mystack=new int[n];
		top=0;
		size=n;
	}
	
	public void push(int n)
	{
		if(top==size)
			System.out.println("Stack is full cannot push");
		else 
			mystack[top++]=n;
	}
	
	public int pop()
	{
		if(top==0)
		{
			System.out.println("Empty stack cannot pop");
			return -1;
		}
		
		else
			return mystack[--top];
	}
	
	public int peek()
	{
		if(top==0)
		{
			System.out.println("Empty stack cannot pop");
			return -1;
		}
		
		else
			return mystack[top-1];
	}
	
	public void sprint()
	{
		System.out.println("\n\nPrinting the stack\n--------------");
		for(int i=0;i<top;i++)
			System.out.println("Stack["+i+"]:"+mystack[i]);
	}
	
	public boolean myequals(Stacky s)
	{
		if (this.size!=s.size) return false;
		if (top!=s.top) return false;
		for(int i=0;i<top;i++)
		{
			if(mystack[i]!=s.mystack[i])
				return false;
		}
		return true;
	}

}

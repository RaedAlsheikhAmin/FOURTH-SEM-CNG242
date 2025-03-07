
public class sequencerexample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
         
		L1: for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
			    //if(j==3) break;	
				//if(j==3) break L1;
				//if(j==3) continue;
				if(j==3) continue L1;
				System.out.println("i:"+i+", j:"+j);
			}
		}
		
		
	}

}

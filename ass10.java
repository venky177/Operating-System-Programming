import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;


public class ass10 {

	/**
	 * @param args
	 */
	Process p;
	InputStream in;
	BufferedReader br;
	String str;

	public void listprocess()
	{
		try{		
					p=Runtime.getRuntime().exec("ps");
					in = p.getInputStream();
					br =	new BufferedReader(new InputStreamReader(in));
					str=br.readLine();
					while(str!=null)
						{
						System.out.println(str);	
						str=br.readLine();
							
						
						}
			
			}catch(Exception e)
			{
				System.out.println(e.getMessage());
				
			}
		
	}
	public void DisGlobal()
	{
		try{		
			p=Runtime.getRuntime().exec("ps -ecl");
			in = p.getInputStream();
			br =	new BufferedReader(new InputStreamReader(in));
			str=br.readLine();
			while(str!=null)
				{
				System.out.println(str);	
				str=br.readLine();
					
				
				}
	
			}catch(Exception e)
			{
				System.out.println(e.getMessage());
			}
	}
	public void chprio(int ...args)
	{
		int pri = 0;
	    if (args.length > 0) {	    
	    	try
	    	{
	    		p=Runtime.getRuntime().exec(   		   
	    		        "nice -n "+pri+" gedit");

	    		in=p.getInputStream();
	    		br=new BufferedReader(new InputStreamReader(in));
	    		str=br.readLine();
	    		System.out.println(str);
	    		while(str!=null)
	    		{
	    			System.out.println(str);
	    			str=br.readLine();
	    		}
	    	
	    	}catch(IOException e)
	    	{
	    		System.out.println(e.getMessage());
	    	}
	    }
	    if (args.length > 1) {
	     System.out.println("sorry no option \n");
	    }
	    

	}
	public static void main(String[] args) {
		int ch;
		boolean flag=true;
		DataInputStream in=null;
		ass10 a=new ass10();
		while(flag)
		{
			try
			{
			in=new DataInputStream(System.in);
			System.out.println("\n1.listprocess\n2.DisGlobal\n3.change process Piority\n4.exit");
			System.out.println("\nplase enter ur choice\n\n");
			ch=Integer.parseInt(in.readLine());
			switch(ch)
			{
			case 1:
				a.listprocess();
					break;
			case 2 :
				a.DisGlobal();
					break;
			case 3:
				System.out.println("\nplease Enter Process Priority\n");
				int pr=Integer.parseInt(in.readLine());
				a.chprio(pr);
			case 4: flag=false;
				default:
					System.out.println("\nsorry\n");
					break;
			}
			
			}catch(Exception e)
			{
				System.out.println(e.getMessage());
			}	
			System.out.println("\n1.listprocess\n2.InfoProcess\n3.DisGlobal\n4.change process Piority\n5.exit");
				
		}
		

	}

}

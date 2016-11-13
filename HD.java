import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;




public class HD {

	
	public static void main(String[] args) {
String str=null;
try
{
	Process p=Runtime.getRuntime().exec("lshw");
	InputStream in=p.getInputStream();
	BufferedReader br=new BufferedReader((new InputStreamReader(in)));
	str=br.readLine();
	while(str!=null)
	{
		System.out.println(str);
		str=br.readLine();
		
	}
	}
	catch(Exception e)
	{
		System.out.println(e.getMessage());
		
		
	}
	


	}

}


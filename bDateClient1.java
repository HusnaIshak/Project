import java.io.*;

import java.net.*;

class DateClient1

{

    public static void main(String args[]) throws Exception

    {

        Socket soc=new Socket("192.168.81.132",7778);

       //BufferedReader in=newBufferedReader(newInputStreamReader(soc.getInputStream()  ));
	
	BufferedReader in=new BufferedReader(new InputStreamReader(soc.getInputStream()));

        System.out.println(in.readLine());
	int hour = Integer.parseInt(in.readLine());
	
	if (hour < 12)
	System.out.println("Good Morning!");

  	else if (hour <= 17 && hour >= 12 )
	System.out.println("Good Afternoon!");

  	else if (hour >17 && hour <= 20)
	System.out.println("Good Evening!");

  	else
	System.out.println("Good Night!");


	//System.out.println(+hours);
	
    }    

}

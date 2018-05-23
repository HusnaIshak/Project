import java.net.*;

import java.io.*;

import java.util.*;

class DateServer1

{

    public static void main(String args[]) throws Exception

    {

        ServerSocket s=new ServerSocket(7778);

        while(true)

        {

            System.out.println("Waiting For Connection ...");

            Socket soc=s.accept();

            DataOutputStream out=new DataOutputStream(soc.getOutputStream());
	    Date dt = new Date();
            int hour = dt.getHours();
	    String hours = Integer.toString(hour);	
	   	out.writeBytes("Server Date & Time: " +dt.toString() +"\n");
	  	out.writeBytes(hours);
	   // if (hour < 12)
		//out.writeBytes("Good Morning! \n");
	   // else if (hour < 17 && !(hour == 12))
	   	//out.writeBytes("Good Afternoon");
	   // else if (hour == 12)
	   //	out.writeBytes("Good Noon");
	   // else
	    //	out.writeBytes("Good Evening");

	   // out.writeBytes("Server Date: " + dt.toString() + "\n");

            out.close();

            soc.close();

        }

    }

}

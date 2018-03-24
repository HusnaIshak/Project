import java.io.*;

import java.net.*;

public class ChatServer

{

  public static void main(String[] args) throws Exception

  {

      ServerSocket sersock = new ServerSocket(36812);

      System.out.println("Server  are ready to CHAT :)");

      Socket sock = sersock.accept( );                          

                              // reading from keyboard (keyRead object)

      BufferedReader keyRead = new BufferedReader(new 
InputStreamReader(System.in));

	                      // sending to client (pwrite object)

      OutputStream ostream = sock.getOutputStream(); 

      PrintWriter pwrite = new PrintWriter(ostream, true);

 

                              // receiving from server 
      InputStream istream = sock.getInputStream();

      BufferedReader receiveRead = new BufferedReader(new 
InputStreamReader(istream));

 

      String receiveMessage, sendMessage;               

      while(true)

      {

        if((receiveMessage = receiveRead.readLine()) != null)  

             {

           System.out.println(receiveMessage);         

        }         

        sendMessage = keyRead.readLine(); 

        pwrite.println(sendMessage);             

        pwrite.flush();

      }               

    }                    

}                        



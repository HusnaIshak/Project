import java.io.*;

import java.net.*;

public class ChatClient

{

  public static void main(String[] args) throws Exception

  {

     Socket sock = new Socket("192.168.81.131", 36812);

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

 

     System.out.println("Start the Chat,Type and Press Enter key");


     String receiveMessage, sendMessage;               

     while(true)

     {

        sendMessage = keyRead.readLine();  // keyboard reading

        pwrite.println("From Client: "+sendMessage); //send to server
 

        pwrite.flush();                    // flush the data

        if((receiveMessage = receiveRead.readLine()) != null) //receive

        {

            System.out.println("From Server: "+receiveMessage); 

        }         

      }               

    }                    

}                        




 # Project

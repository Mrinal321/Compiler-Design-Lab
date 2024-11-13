import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.time.LocalDateTime;
import java.util.Base64;

import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;

public class MailAssignment {
    private static DataOutputStream dos;
    public static BufferedReader br;

    public static void main(String[] args) throws Exception {
        String user = "s2010676158@ru.ac.bd";
        String password = "bXJpbmFsNTQzMjE=";

        String username = new String(Base64.getEncoder().encode(user.getBytes()));
        //String password = new String(Base64.getEncoder().encode(pass.getBytes()));
        SSLSocket s = (SSLSocket) SSLSocketFactory.getDefault().createSocket("smtp.gmail.com", 465);

        dos = new DataOutputStream(s.getOutputStream());
        br = new BufferedReader(new InputStreamReader(s.getInputStream()));

        send("EHLO smtp.gmail.com\r\n");
            for(int i = 0; i < 9; i++){
                System.out.println("Server: " + br.readLine());
            }

        send("AUTH LOGIN\r\n");
                System.out.println("SERVER: " + br.readLine());
        
        send(username + "\r\n");
                System.out.println("SERVER: " + br.readLine());

        send(password + "\r\n");
                System.out.println("SERVER: " + br.readLine());

        send("MAIL FROM:<s2010676158@ru.ac.bd>\r\n");
                System.out.println("SERVER: " + br.readLine());

        send("RCPT TO:<mrinalkantihowlader154@gmail.com>\r\n");
                System.out.println("SERVER: " + br.readLine());

        send("DATA\r\n");
                System.out.println("SERVER: " + br.readLine());

        send("FROM: s2010676158@ru.ac.bd\r\n");
        send("TO: mrinalkantihowlader154@gmail.com\r\n");
        send("Subject: Emali Test" + LocalDateTime.now() + "\r\n");
        send("Alpha test 1.0.\r\n");
        send(".\r\n");
                System.out.println("SERVER: " + br.readLine());

        send("QUIT\r\n");
                System.out.println("SERVER: " + br.readLine());
    }

    private static void send(String s) throws Exception {
        dos.writeBytes(s);
        Thread.sleep(500);
        System.out.println("Client: " + s);
    }
}

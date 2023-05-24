import java.util.Properties;

import javax.mail.FetchProfile;
import javax.mail.Folder;
import javax.mail.Message;
import javax.mail.MessagingException;
import javax.mail.Session;
import javax.mail.Store;

public class Email {
    protected String usr;
    protected String pwd;
    protected Store store;
    private Folder folder;
    
    public Email(String user, String password)
    {
        String host = "imap.gmail.com";
        this.usr = user;
        this.pwd = password;
        Properties props = new Properties();
        props.setProperty("mail.imap.ssl.enable", "true");
        Session session = Session.getInstance(props);
        try 
        {
            this.store = session.getStore("imap");
            store.connect(host, this.usr, this.pwd);
        } 
        catch (MessagingException e) 
        {
            e.printStackTrace();
        }
    } 
    
    public void openFolder(String folderName) throws MessagingException
    {
        this.folder = (Folder)store.getFolder(folderName);
        System.out.println((new StringBuilder("For test----")).append
            (folder.getParent().getFullName()).toString());
        try
        {
            folder.open(2);
            System.out.println((new StringBuilder("Folder name----")).append
                (folder.getFullName()).toString());
        }
        catch(Exception ex)
        {
            System.out.println((new StringBuilder("Folder Opening Exception..")).append(ex).toString());
        }
    }

    public void printAllMessages()
    throws Exception
    {
        Message msgs[] = folder.getMessages();
        FetchProfile fp = new FetchProfile();
        folder.fetch(msgs, fp);
        for(int i = 0; i < msgs.length; i++)
        {
            Message message = msgs[i];
            dumpEnvelope(msgs[i]);
            System.out.println("==============================");
            System.out.println("Email #" + (i + 1));
            System.out.println("Subject: " + message.getSubject());
            System.out.println("From: " + message.getFrom()[0]);
            System.out.println("Text: " + message.getContent().toString());
        }
    }

    private void dumpEnvelope(Message message) {
    
    }
}

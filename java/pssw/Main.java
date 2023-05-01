import java.io.IOException;
import java.io.OutputStream;
import java.util.InputMismatchException;
import java.util.Scanner;


public class Main extends Generator {
    public static void main(String[] args) throws IOException
    {
        System.out.println("Hello, please type the number of characters that your password will have.");
        System.out.println("Remember that this number must be greater than 5 and smaller than 128!");
        
        Scanner reader = new Scanner(System.in);
        Short size;
        while (true) 
        {
            try
            {
                size = reader.nextShort();
                reader.nextLine(); /* Consume los \n o la basura que queda en el buffer */

                if (size < 5 || size > 128)
                {
                    throw new ArithmeticException();
                }
                else
                {
                    break;
                }
            }
            catch (ArithmeticException e)
            {
                System.out.println("Remember that this number must be between 5 and 128!");
            }
            catch (InputMismatchException e)
            {
                System.out.println("The value must be of integer type!");
                reader.nextLine();
            }
        }

        reader.close();
        System.out.printf("The size of your password will be: %d\n",size);
        String password = password(size);
        System.out.println("Your new password is: " + password);

        String[] cmd = {"xclip", "-selection", "clipboard"};
        Process pb = Runtime.getRuntime().exec(cmd);
        try (OutputStream out = pb.getOutputStream()) 
        {
            out.write(password.getBytes());
        }
        catch (IOException e)
        {
            System.out.println("Error in IO");
        }

    }
}

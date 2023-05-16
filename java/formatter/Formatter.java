import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;

/**
 * Formatter
 */
public class Formatter {

    public String readFile(String path) throws UnsupportedEncodingException {
        Path location = Paths.get(path);
        byte[] data = null;
        try 
        {
            data = Files.readAllBytes(location);
        } 
        catch (IOException e) { e.printStackTrace();}
        String fileContent = new String(data, "ascii");
        return fileContent;
    }
    
    public byte[] byteString(String input) {
        byte[] bytes = input.getBytes();
        return bytes;
    }


    public static void main(String[] args) throws UnsupportedEncodingException  {
        Formatter formatter = new Formatter();
        String content = formatter.readFile("test.c");
        System.out.println(Arrays.toString(formatter.byteString(content)));
    }
}
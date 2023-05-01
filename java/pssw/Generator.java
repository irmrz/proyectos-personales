
import java.security.SecureRandom;


public class Generator
{

    private static Short generateSecureRandomNumber(int i, int j) {
        SecureRandom random = new SecureRandom();
        int range = j - i;
        int bits = (short) (range >= 0 ? Integer.highestOneBit(range) : 0);
        int value;
        do {
            value = (short) (random.nextInt() & (bits - 1));
        } while (value >= range);
        return (short) (i + value);
    }

    public static String password(Short size)
    {
        String password;
        int rand;
        StringBuilder constructor = new StringBuilder();

        for (Short i=0; i < size; i++)
        {
            rand = generateSecureRandomNumber(32, 126);
            char randNum = (char) rand;
            constructor.append(randNum);
        }
        password = constructor.toString();
        return password;
    }

}
import java.util.*;
import java.io.*;

class Solution
{
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String args[]) throws IOException {
        String num = br.readLine();
        int result = 0;
        for(int i=0; i<num.length(); i++) {
            result += num.charAt(i) - 48;
        }
        System.out.println(result);
    }
}


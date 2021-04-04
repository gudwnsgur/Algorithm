import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String src = br.readLine();
        String dest = br.readLine();

        // pi
        int[] pi = new int[dest.length()];
        for (int i = 1, j = 0; i < pi.length; i++) {
            while (j > 0 && dest.charAt(i) != dest.charAt(j)) j = pi[j - 1];
            if (dest.charAt(i) == dest.charAt(j)) pi[i] = ++j;
        }

        // KMP algorithm
        for(int i=0, j=0; i<src.length(); i++) {
            while(j > 0 && src.charAt(i) != dest.charAt(j)) j = pi[j-1];
            if(src.charAt(i) == dest.charAt(j)) {
                if(j == dest.length()-1) {
                    System.out.println(1);
                    return;
                }
                else j++;
            }
        }

        System.out.println(0);
    }
}

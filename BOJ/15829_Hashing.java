import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        int result = 0;
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        for(int i=0; i<n; i++) {
            result += Math.pow(31, i)*(s.charAt(i)-'a'+1);
        }
        System.out.println(result%1234567891);
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        String s = br.readLine();
        StringBuilder e = new StringBuilder();
        for(int i=0; i<s.length(); i++) {
            e.append(s.charAt(i) >= 'a' && s.charAt(i) <= 'z' ? (char)(s.charAt(i) - 32) : (char)(s.charAt(i)+32) );
        }
        System.out.println(e);
    }
}

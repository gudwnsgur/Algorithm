import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        StringBuilder s = new StringBuilder();
        while(tk.hasMoreElements()) s.append(tk.nextToken());
        String ascending = "12345678", descending = "87654321";
        System.out.println(s.toString().equals(ascending) ? "ascending" :
                s.toString().equals(descending) ? "descending" : "mixed");
    }
}

import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class SWEA2070 {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        for(int i=1; i<=tc; i++) {
            tk = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(tk.nextToken());
            int b = Integer.parseInt(tk.nextToken());
            System.out.println("#" + i + " " + (a<b ? "<" : a>b ? ">" : "="));
        }

    }
}


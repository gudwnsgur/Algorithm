import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int a, b, c, d, e, f;

    public static void input() throws IOException {
        tk = new StringTokenizer(br.readLine());

        a = Integer.parseInt(tk.nextToken());
        b = Integer.parseInt(tk.nextToken());
        c = Integer.parseInt(tk.nextToken());
        d = Integer.parseInt(tk.nextToken());
        e = Integer.parseInt(tk.nextToken());
        f = Integer.parseInt(tk.nextToken());
    }
    public static void main(String[] args) throws IOException {
        input();
        for(int x= -999; x <= 999; x++) {
            for(int y = -999; y<=999; y++) {
                if(a*x + b*y == c && d*x + e*y == f) {
                    System.out.println(x + " " + y);
                    return;
                }
            }
        }
    }
} 

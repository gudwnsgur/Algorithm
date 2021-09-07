import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int a, b;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        a = Integer.parseInt(tk.nextToken());
        b = Integer.parseInt(tk.nextToken());

        int cnt = 1;
        while(a < b) {
            if(b % 2 ==0) b /= 2;
            else if(b%10 == 1) b /= 10;
            else {
                System.out.println(-1);
                return;
            }
            cnt++;
        }
        System.out.println((a==b) ? cnt : -1);
    }
}


import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class SWEA2068 {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        for(int i=1; i<=tc; i++) {
            tk = new StringTokenizer(br.readLine());

            int result = Integer.MIN_VALUE;
            for(int j=0; j<10; j++) {
                result = Math.max(Integer.parseInt(tk.nextToken()), result);
            }
            System.out.println("#" + i + " " + result);
        }
    }
}


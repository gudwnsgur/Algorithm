import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class SWEA2071 {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        for(int i=1; i<=tc; i++) {
            int sum = 0;
            tk = new StringTokenizer(br.readLine());
            for(int j=0; j<10; j++) {
                sum += Integer.parseInt(tk.nextToken());
            }
            System.out.println("#" + i + " " +
                    ((sum % 10 < 5) ? sum/10 : sum/10 + 1)) ;
        }

    }
}


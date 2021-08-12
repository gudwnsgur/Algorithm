import java.math.BigInteger;
import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tk.nextToken());
        int m = Integer.parseInt(tk.nextToken());

        if(m == 0 || m == n) System.out.println(1);
        else {
            BigInteger result = new BigInteger(String.valueOf(n));
            for(int i=2; i<=m; i++) {
                result = result.multiply(new BigInteger(String.valueOf(n-i+1)));
                result = result.divide(new BigInteger(String.valueOf(i)));
            }
            System.out.println(result);
        }
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());
        long gcd = Long.parseLong(tk.nextToken());
        long lcm = Long.parseLong(tk.nextToken());

        long xy = gcd * lcm;
        long left = gcd, right = lcm;

        for (long i = 2 * gcd; i * i <= xy; i += gcd) {
            if (xy % i != 0) continue;
            if (gcd(i, (xy/i)) == gcd) {
                if (left + right > (xy/i) + i) {
                    left = i;
                    right = (xy/i);
                }
            }
        }
        System.out.println(left + " " + right);
    }
}

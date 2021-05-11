import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int a, b, c;
    static boolean aa, bb, cc;
    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        a = Integer.parseInt(tk.nextToken());
        b = Integer.parseInt(tk.nextToken());
        c = Integer.parseInt(tk.nextToken());
        aa = (a%2==1);
        bb = (b%2==1);
        cc = (c%2==1);

        if((aa && bb && cc ) || (!aa && !bb && !cc)) System.out.println(a*b*c);
        else System.out.println((aa ? a : 1) * (bb ? b : 1 ) * (cc ? c : 1));
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static boolean[] b = new boolean[31];

    public static void main(String[] args) throws IOException {
        for(int i=0; i<28; i++) b[Integer.parseInt(br.readLine())] = true;
        for(int i=1; i<=30; i++) if(!b[i]) System.out.println(i);
    }
}

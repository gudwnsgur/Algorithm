import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] numOfEdges = new int[n+1];
        for(int i=0; i<n-1; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());

            numOfEdges[s]++;
            numOfEdges[e]++;
        }

        int queries = Integer.parseInt(br.readLine());
        while(queries-- > 0 ) {
            tk = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(tk.nextToken());
            if(a == 2) System.out.println("yes");
            else {
                int b = Integer.parseInt(tk.nextToken());
                if(numOfEdges[b] != 1) System.out.println("yes");
                else System.out.println("no");
            }
        }
    }
}

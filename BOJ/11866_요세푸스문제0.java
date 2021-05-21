import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, k;
    static int[] result;
    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        k = Integer.parseInt(tk.nextToken());
        result = new int[n];

        Queue<Integer> q = new LinkedList<>();
        for(int i=1; i<=n; i++) q.add(i);

        int idx =0;
        while(!q.isEmpty()) {
            for(int i=0; i<k-1; i++) q.add(q.poll());
            result[idx++] = q.poll();
        }
        System.out.print("<");
        for(int i=0 ;i<n-1; i++) System.out.print(result[i]+ ", ");
        System.out.println(result[n-1] + ">");
    }
}


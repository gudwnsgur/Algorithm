import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    static long solve(int n, int[] arr) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for(int i=0; i<n; i++) pq.add((long)arr[i]);

        long result = 0;
        while(pq.size() > 1) {
            long a = pq.poll();
            long b = pq.poll();

            result += a+b;
            pq.add(a+b);
        }

        return result;
    }
    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            tk = new StringTokenizer(br.readLine());
            for(int i=0; i<n; i++) arr[i] = Integer.parseInt(tk.nextToken());

            System.out.println(solve(n, arr));
        }
    }
}

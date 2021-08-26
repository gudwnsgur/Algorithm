import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tk.nextToken());
        int k = Integer.parseInt(tk.nextToken());
        int [] arr = new int[n];
        tk = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            arr[i] = Integer.parseInt(tk.nextToken());
        }

        int result = Integer.MIN_VALUE;
        for(int i=0; i<n-k+1; i++) {
            int sum = 0;
            for(int j=i; j<i+k; j++) {
                sum += arr[j];
            }
            result = Math.max(result, sum);
        }
        System.out.println(result);

    }
}



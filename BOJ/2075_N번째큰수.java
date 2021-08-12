import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        int[] arr = new int[n*n];
        for(int i=0; i<n; i++) {
            tk = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++) {
                arr[n*i + j ] = Integer.parseInt(tk.nextToken());
            }
        }
        Arrays.sort(arr);
        System.out.println(arr[n*n-n]);
    }
}

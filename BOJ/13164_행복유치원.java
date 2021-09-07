import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, k;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        k = Integer.parseInt(tk.nextToken());

        tk = new StringTokenizer(br.readLine());
        arr = new int[n];
        for(int i=0; i<n; i++) arr[i] =  Integer.parseInt(tk.nextToken());

        int[] diff =new int[n-1];
        for(int i=0; i<n-1; i++) diff[i] = arr[i+1] - arr[i];
        Arrays.sort(diff);

        int result =0 ;
        for(int i=0; i<n-k; i++) result += diff[i];
        System.out.println(result);
    }
}

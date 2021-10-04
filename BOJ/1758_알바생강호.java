import java.io.*;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = Integer.parseInt(br.readLine());
        Arrays.sort(arr);

        long result = 0;
        for(int i=n-1, j=1; i>=0; i--, j++) {
            result += Math.max(arr[i] - (j - 1), 0);
        }
        System.out.println(result);
    }
}


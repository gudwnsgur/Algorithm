import java.util.*;
import java.io.*;

class Solution {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer tk;
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        tk = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) arr[i] = Integer.parseInt(tk.nextToken());
        Arrays.sort(arr);
        System.out.println(arr[(n-1)/2]);
    }
}

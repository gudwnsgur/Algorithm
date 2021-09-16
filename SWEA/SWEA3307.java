import java.io.*;
import java.util.*;
 
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static int[] arr;
     
    static int solve() {
        int[] LIS = new int[n];
         
        int max = 0;
        for(int i=0; i<n; i++) {
            LIS[i] = 1;
            for(int j=0; j<i; j++) {
                if(arr[j] < arr[i] && LIS[i] < LIS[j] + 1) {
                    LIS[i] = LIS[j] + 1;
                }
            }
            if(max< LIS[i]) max = LIS[i];
        }
        return max;
    }
     
    public static void main(String[] args) throws Exception{
        int tc = Integer.parseInt(br.readLine());
        for(int i=1; i<= tc; i++) {
            n = Integer.parseInt(br.readLine());
            arr = new int[n];
            tk = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++) {
                arr[j] = Integer.parseInt(tk.nextToken());
            }
             
            System.out.println("#" + i + " " + solve());
        }
    }
 
}

import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        tk = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) arr[i] = Integer.parseInt(tk.nextToken());
        Arrays.sort(arr);
        int result = Integer.MAX_VALUE ;
        int diff = Integer.MAX_VALUE;

        for(int i=0; i<n-3; i++) {
            for(int j=i+3; j<n; j++) {
                int left = i+1, right = j-1;
                while(left < right) {
                    diff = ((arr[i] + arr[j])- (arr[left] + arr[right]));
                    result = Math.min(Math.abs(diff), result);
                    if(diff > 0) left++;
                    else if(diff < 0) right--;
                    else {
                        System.out.println(0);
                        return;
                    }
                }
            }
        }
        System.out.println(result);

    }
}

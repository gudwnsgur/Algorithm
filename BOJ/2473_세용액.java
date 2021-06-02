import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static long[] solution;
    static int n;
    static long[] arr = new long[3];
    static long result = Long.MAX_VALUE;

    static void solve(int cur) {
        int left = cur+1, right = n-1;
        while(left < right) {
            long sum = solution[left] + solution[right] + solution[cur];
            if(Math.abs(sum) < result ) {
                result = Math.abs(sum);
                arr[0] = solution[cur];
                arr[1] = solution[left];
                arr[2] = solution[right];
            }
            if(sum > 0) right--;
            else left++;
        }
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        tk = new StringTokenizer(br.readLine());
        solution = new long[n];
        for(int i=0; i<n; i++) solution[i] = Integer.parseInt(tk.nextToken());

        Arrays.sort(solution);
        for(int i=0; i<n-2; i++) solve(i);

        System.out.println(arr[0] + " " + arr[1] + " " + arr[2]);
    }
}



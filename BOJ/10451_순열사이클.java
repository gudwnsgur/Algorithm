
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    static int getCycleCount(int n, int[] arr) {
        int result = 0;
        boolean[] visited = new boolean[n+1];
        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                result++;
                int cur = i;
                visited[cur] = true;
                while(!visited[arr[cur]]) {
                    visited[arr[cur]] = true;
                    cur = arr[cur];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0 ) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n+1];
            tk = new StringTokenizer(br.readLine());
            for(int i=1; i<arr.length; i++) {
                arr[i] = Integer.parseInt(tk.nextToken());
            }

            System.out.println(getCycleCount(n, arr));
        }
    }
}

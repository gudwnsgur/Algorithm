import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int tc, n;
    static int[][] arr;

    static int solve() {
        Arrays.sort(arr, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });

        int s = arr[0][1], cnt = 1;
        for(int i=1; i<n; i++) {
            if(s > arr[i][1]) {
                s = arr[i][1];
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws IOException {
        tc = Integer.parseInt(br.readLine());
        while(tc-- > 0) {
            n = Integer.parseInt(br.readLine());
            arr = new int[n][2];
            for(int i=0; i<n; i++) {
                tk = new StringTokenizer(br.readLine());
                arr[i][0] = Integer.parseInt(tk.nextToken());
                arr[i][1] = Integer.parseInt(tk.nextToken());
            }
            System.out.println(solve());
        }
    }
}



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] time = new int[n][2];

        for(int i=0; i<n ; i++) {
            StringTokenizer tk = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(tk.nextToken());
            int s = Integer.parseInt(tk.nextToken());
            time[i][0] = s-t;
            time[i][1] = s;

        }

        Arrays.sort(time, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[1] > o2[1]) return -1;
                else if(o1[1] < o2[1]) return 1;
                return 0;
            }
        });

        int cur = time[0][1];
        for(int i=0; i<n; i++) {
            if(cur >= time[i][1]) cur = time[i][0];
            else cur -= (time[i][1] - time[i][0]);
        }

        System.out.println((cur >= 0 ? cur : -1));
    }
}

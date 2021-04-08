import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n =  Integer.parseInt(br.readLine());
        int[][] lectures = new int[n][3];
        for(int i=0; i<n; i++) {
            StringTokenizer tk = new StringTokenizer(br.readLine());
            lectures[i][0] = Integer.parseInt(tk.nextToken());
            lectures[i][1] = Integer.parseInt(tk.nextToken());
            lectures[i][2] = Integer.parseInt(tk.nextToken());
        }

        Arrays.sort(lectures, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[1] < o2[1] ) return -1;
                else if(o1[1] > o2[1]) return 1;

                if(o1[2] < o2[2]) return -1;
                else if(o1[2] > o2[2]) return 1;
                return 0;
            }
        });

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0; i<n; i++) {
            if(!pq.isEmpty() && pq.element() <= lectures[i][1]) pq.remove();
            pq.add(lectures[i][2]);
        }
        System.out.println(pq.size());
    }
}

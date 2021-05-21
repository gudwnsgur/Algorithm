import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Jewelry {
    int m, v;
    Jewelry(int m, int v) {
        this.m = m;
        this.v = v;
    }
}
class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, k;
    static long result = 0;
    static int[] bag;
    static Jewelry[] jewelries;
    static PriorityQueue<Jewelry> pq;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        k = Integer.parseInt(tk.nextToken());

        pq = new PriorityQueue<>(new Comparator<Jewelry>() {
            @Override
            public int compare(Jewelry o1, Jewelry o2) {
                if(o1.v > o2.v) return -1;
                else if(o1.v < o2.v) return 1;

                if(o1.m < o2.m) return -1;
                else if(o1.m > o2.m) return 1;
                return 0;
            }
        });

        jewelries = new Jewelry[n];
        for(int i=0; i<n; i++) {
            tk = new StringTokenizer(br.readLine());
            jewelries[i] = new Jewelry(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken()));
        }
        Arrays.sort(jewelries, new Comparator<Jewelry>() {
            @Override
            public int compare(Jewelry o1, Jewelry o2) {
                if(o1.m < o2.m) return -1;
                else if(o1.m > o2.m) return 1;

                if(o1.v > o2.v) return -1;
                else if(o1.v < o2.v) return 1;
                return 0;
            }
        });
        bag = new int[k];
        for(int i=0; i<k; i++) bag[i] = Integer.parseInt(br.readLine());
        Arrays.sort(bag);

        int jIdx = 0;
        for(int i=0; i<k; i++) {
            while(jIdx < n && bag[i] >= jewelries[jIdx].m) pq.add(jewelries[jIdx++]);
            if(!pq.isEmpty()) result += pq.poll().v;
        }
        System.out.println(result);
    }
}

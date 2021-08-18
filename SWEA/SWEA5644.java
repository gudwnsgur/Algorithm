import java.io.*;
import java.util.*;
 
class Bc {
    int idx, p;
    Bc(int idx, int p) {
        this.idx = idx;
        this.p = p;
    }
}
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static StringBuilder sb = new StringBuilder();
    static final int[] dx = {0, -1, 0, 1, 0};
    static final int[] dy = {0, 0, 1, 0, -1};
    static int move, bc;
    static int sum;
    static int[] A, B;
    static int[][] bcInfo;
    static int[][][] map;
    static PriorityQueue<Bc> aPQ, bPQ;
     
     
    public static void input() throws IOException {
        sum = 0;
        tk = new StringTokenizer(br.readLine());
        move =Integer.parseInt(tk.nextToken());
        bc = Integer.parseInt(tk.nextToken());
         
        A = new int[move+1];
        tk = new StringTokenizer(br.readLine());
        for(int i=1; i<=move; i++) A[i] = Integer.parseInt(tk.nextToken());
         
        B = new int[move+1];
        tk = new StringTokenizer(br.readLine());
        for(int i=1; i<=move; i++) B[i] = Integer.parseInt(tk.nextToken());
         
        bcInfo = new int[bc][4];
        for(int i=0; i< bc; i++) {
            tk = new StringTokenizer(br.readLine());
            for(int j=0; j<4; j++) {
                bcInfo[i][j] = Integer.parseInt(tk.nextToken());
            }
        }
         
        map = new int[11][11][bc];
        for(int i=0; i<bc; i++) {
            for(int x=1; x<=10; x++) {
                for(int y=1; y<=10; y++) {
                    if(Math.abs(x - bcInfo[i][1]) + 
                            Math.abs(y - bcInfo[i][0]) <= bcInfo[i][2]) 
                        map[x][y][i] = bcInfo[i][3];
                }
            }
        }
         
         
        aPQ = new PriorityQueue<>(new Comparator<Bc>() {
            @Override
            public int compare(Bc o1, Bc o2) {
                return Integer.compare(o2.p, o1.p);
            }
        });
         
        bPQ = new PriorityQueue<>(new Comparator<Bc>() {
            @Override
            public int compare(Bc o1, Bc o2) {
                return Integer.compare(o2.p, o1.p);
            }
        });
    }
     
    public static void solve() {
        int ax = 1, ay = 1, bx = 10, by = 10;
        for(int i=0; i<=move; i++) {
            ax += dx[A[i]];
            ay += dy[A[i]];
             
            bx += dx[B[i]];
            by += dy[B[i]];
             
            aPQ.clear();
            bPQ.clear();
            for(int j=0; j<bc; j++) {
                if(map[ax][ay][j] > 0) aPQ.add(new Bc(j, map[ax][ay][j]));
                if(map[bx][by][j] > 0) bPQ.add(new Bc(j, map[bx][by][j]));
            }
             
            if(aPQ.isEmpty()) {
                if(bPQ.isEmpty()) continue;
                else sum += bPQ.peek().p;
            }
            else {
                if(bPQ.isEmpty()) sum += aPQ.peek().p;
                else {
                    if(aPQ.size() ==1) {
                        if(bPQ.size() ==1) {
                            if(aPQ.peek().idx == bPQ.peek().idx) sum+= aPQ.peek().p;
                            else sum += aPQ.peek().p + bPQ.peek().p;
                        }
                        else {
                            if(aPQ.peek().idx == bPQ.peek().idx) bPQ.poll();
                            sum += aPQ.peek().p + bPQ.peek().p;
                        }
                    }
                    else {
                        if(bPQ.size() ==1) {
                            if(aPQ.peek().idx == bPQ.peek().idx) aPQ.poll();
                            sum += aPQ.peek().p + bPQ.peek().p;
                        }
                        else {
                            if(aPQ.peek().idx == bPQ.peek().idx) {
                                sum += aPQ.poll().p;
                                bPQ.poll();
                                sum += Math.max(aPQ.poll().p, bPQ.poll().p);
                            }
                            else sum += aPQ.peek().p + bPQ.peek().p;
                        }
                    }
                }
            }
        }
    }
     
    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        for(int t = 1; t <= tc ; t++) {
            input();
 
            solve();
            sb.append("#").append(t).append(" ").append(sum).append("\n");
        }
        System.out.println(sb.toString());
         
    }
 
}

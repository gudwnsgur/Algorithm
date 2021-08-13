import java.util.*;
import java.io.*;

class Loc {
    int x,y;
    Loc(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m, d, enemySize;
    static int result = Integer.MIN_VALUE;
    static ArrayList<Loc> enemy = new ArrayList<>();
    static int[] archer = new int[3];
    static boolean[] visited, liveEnemies;

    static int getDist(int archerY, Loc enemy, int move) {
        int diff = Math.abs( n - (enemy.x + move) ) + Math.abs(archerY - enemy.y);
        return diff > d ? -1 : diff;
    }

    static int solve() {
        // archer == 0, 1, 2
        liveEnemies = new boolean[enemySize];
        Arrays.fill(liveEnemies, true);
        boolean[] pos;
        int kill = 0, move = 0;

        while(true) {
            pos = new boolean[enemySize];

            // 거리재기
            for(int i=0; i<3; i++) {
                int minDist = Integer.MAX_VALUE;
                int idx = -1;
                for(int j=0; j < enemySize; j++) {
                    if(!liveEnemies[j]) continue;
                    int dist = getDist(archer[i], enemy.get(j), move);
                    if(dist != -1 && dist < minDist) {
                        minDist = dist;
                        idx = j;
                    }
                }
                if(idx != -1) pos[idx] = true;
            }

            // 죽이기 kill ++
            for(int i=0; i<enemySize; i++) {
                if(pos[i]) {
                    liveEnemies[i] = false;
                    kill++;
                }
            }

            move++;
            int lived = 0;
            for(int i=0; i<enemySize; i++) {
                if(enemy.get(i).x + move >= n) liveEnemies[i] = false;
                if(liveEnemies[i]) lived++;
            }
            if(lived == 0) return kill;
        }
    }


    static void dfs(int len) {
        if(len == 3) {
//            System.out.print("ARC : ");
//            for(int i=0; i<3; i++) {
//                System.out.print(archer[i] + " ");
//            }
//            System.out.println();
            result = Math.max(result, solve());
            return;
        }

        for(int i=0; i<m; i++) {
            if(!visited[i] && (len == 0 || archer[len-1] < i)) {
                visited[i] = true;
                archer[len] = i;
                dfs(len+1);
                visited[i] = false;
            }
        }

    }


    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        d = Integer.parseInt(tk.nextToken());

        for(int i=0; i<n; i++) {
            tk = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++) {
                if(tk.nextToken().equals("1")) enemy.add(new Loc(i, j));
            }
        }
        enemySize = enemy.size();
        Collections.sort(enemy, (o1, o2) -> {
            if(o1.y < o2.y) return -1;
            else if(o1.y > o2.y) return 1;

            if(o1.x > o2.x) return -1;
            else if(o1.x < o2.x) return 1;
            return 0;
        });

//        System.out.print("Enemy : ");
//        for(int i=0; i<enemy.size(); i++) {
//            System.out.print("(" + enemy.get(i).x + "," + enemy.get(i).y + ") ");
//        }
//        System.out.println();

        visited = new boolean[m];
        dfs(0);
        System.out.println(result);
    }
}

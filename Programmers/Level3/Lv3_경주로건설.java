import java.util.*;
import static java.lang.Math.max;
class Pair{
    int x, y, dir, cost;
    public Pair(int x, int y, int dir, int cost) {
        this.x = x;
        this.y = y;
        this.dir = dir;
        this.cost = cost;
    }
}

class Solution {
    int[] dx = {0, 1, 0, -1};
    int[] dy = {1, 0, -1, 0};
    int[][] dp = new int[26][26];
    int[][] boards;
    boolean[][] visited = new boolean[26][26];
    int n;

    void bfs(int x, int y, int dir) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(x, y, dir, 100));
        dp[x][y] = 100;

        for(int i=0; i<26; i++) for(int j=0; j<26; j++) visited[i][j] = false;
        visited[x][y] = true;

        while(!q.isEmpty()) {
            int curX = q.element().x, curY = q.element().y;
            int curCost = q.element().cost, curDir = q.element().dir;

            if(curX == n-1 && curY == n-1) {
                dp[n-1][n-1] = Math.min(curCost, dp[n-1][n-1]);
                q.remove();
                continue;
            }
            for(int i=0; i<4; i++) {
                if(i == 2) continue; // 뒤로 가는거 제외
                int nx = curX + dx[(curDir+i+4)%4], ny = curY + dy[(curDir+i+4)%4];
                if(nx < 0 || nx >=n || ny <0 || ny >=n ) continue;
                if(boards[nx][ny] == 1) continue;

                int cost = i==0 ? 100+curCost : 600+curCost;

                if(dp[nx][ny] < cost) continue;

                dp[nx][ny] = cost;
                q.add(new Pair(nx, ny, (curDir+4+i)%4, cost));
            }
            q.remove();
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
    }


    public int solution(int[][] board) {
        n = board.length;
        boards = board;
        for(int i=0; i<25; i++) {
            for(int j=0; j<25; j++) {
                dp[i][j] = 376000;
            }
        }
        dp[0][0] = 0;
        if(boards[0][1] != 1) bfs(0,1,0);
        if(boards[1][0] != 1) bfs(1,0,1);
        return dp[n-1][n-1];
    }
}

class Main {
    public static void main(String[] args) {
    }
}

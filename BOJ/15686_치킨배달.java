import java.util.*;
import java.io.*;

class Loc {
    int x, y;
    Loc(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m, result = Integer.MAX_VALUE;
    static int[][] city;
    static ArrayList<Loc> house = new ArrayList<>();
    static ArrayList<Loc> chicken = new ArrayList<>();
    static int[] arr;
    static boolean[] visited;

    static int getDist(Loc a, Loc b) {
        return Math.abs(a.x-b.x) + Math.abs(a.y-b.y);
    }


    static void dfs(int len, int m) {
        if(len == m) {
//            System.out.println("선택된 치킨집의 index");
//            for(int i=0; i<m; i++) System.out.print(arr[i] + " ");
//            System.out.println();


            int diffSum = 0;
            for(int i=0; i<house.size(); i++) {
                int cur = Integer.MAX_VALUE;
                for(int j=0; j<m; j++) {
                    // house.get(i) 와  chickens.get( ( arr[j] )  ) 의 거리 구하기
                    cur = Math.min(cur, getDist(house.get(i), chicken.get((arr[j]))));
                }
                diffSum += cur;
            }

            result = Math.min(result, diffSum);
            return;
        }

        for(int i=0; i<chicken.size(); i++) {
            if(!visited[i] && (len == 0 || arr[len-1] < i) ) {
                visited[i] = true;
                arr[len] = i;
                dfs(len + 1, m);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        city = new int[n][n];
        for(int i=0; i<n; i++) {
            tk = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++) {
                city[i][j] = Integer.parseInt(tk.nextToken());
                if(city[i][j] == 1) house.add(new Loc(i, j));
                if(city[i][j] == 2) chicken.add(new Loc(i, j));
            }
        }

//        System.out.println("총 치킨집의 개수 : " + chicken.size());
//        System.out.println("골라야 하는 치킨집의 개수 : " + m);
        visited = new boolean[chicken.size()];
        arr = new int[m];
        dfs(0, m);

        System.out.println(result);
    }
}

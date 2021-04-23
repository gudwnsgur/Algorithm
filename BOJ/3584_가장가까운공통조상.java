import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    static ArrayList<ArrayList<Integer>> graph;
    static int[] depths, parents;

    static int LCA(int A, int B) {
        if(depths[A] > depths[B]) {
            while(depths[A] != depths[B]) A = parents[A];
        }
        else if(depths[A] < depths[B]) {
            while (depths[A] != depths[B]) B = parents[B];
        }

        while(A != B) {
            A = parents[A];
            B = parents[B];
        }
        return A;
    }

    static void dfs(int cur, int depth, int parent) {
        depths[cur] = depth;
        parents[cur] = parent;

        for(int i=0; i < graph.get(cur).size(); i++) {
            int next = graph.get(cur).get(i);
            if(next != parent) dfs(next, depth+1, cur);
        }
    }
    static int solution(int n) throws IOException {
        depths = new int[n+1];
        parents = new int[n+1];

        graph = new ArrayList<>();
        for(int i=0; i<= n; i++) graph.add(new ArrayList<>());

        for(int i=0; i< n-1; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());

            graph.get(s).add(e);
            graph.get(e).add(s);
            parents[e] = s; // e의 부모 == s
        }

        // find root node
        int root = 0;
        for(int i=1; i<=n; i++){
            if(parents[i] == 0) {
                root = i;
                break;
            }
        }

        // find depth
        dfs(root, 0, 0);

        tk = new StringTokenizer(br.readLine());
        
        int A = Integer.parseInt(tk.nextToken());
        int B = Integer.parseInt(tk.nextToken());
        // A 와 B의 LCA 찾기
        return LCA(A, B);
    }

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0 ) {
            int n = Integer.parseInt(br.readLine());
            System.out.println(solution(n));
        }
    }
}

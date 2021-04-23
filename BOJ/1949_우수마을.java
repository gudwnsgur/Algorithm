import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    static int n;
    static int[] populations;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

    static boolean[] visited, greatCity;
    static int result = 0;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
        populations = new int[n+1];
        greatCity = new boolean[n+1];
        visited = new boolean[n+1];

        tk = new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++) populations[i] = Integer.parseInt(tk.nextToken());

        for(int i=0; i<n-1; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());

            graph.get(s).add(e);
            graph.get(e).add(s);
        }



    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static HashMap<Integer, Boolean> knowTruth = new HashMap<>();
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static ArrayList<ArrayList<Integer>> rooms = new ArrayList<>();
    static boolean pos;
    static boolean[] visited;

    static void dfs(int node) {
        if(knowTruth.containsKey(node)) {
            pos = false;
            return;
        }
        for(int i=0; i<graph.get(node).size(); i++) {
            if(!visited[graph.get(node).get(i)]) {
                visited[graph.get(node).get(i)] = true;
                dfs(graph.get(node).get(i));
                if(!pos) return;
            }
        }
    }

    static boolean canTellLie(ArrayList<Integer> room) {
        for(int value : room) if(knowTruth.containsKey(value)) return false;
        for(int value : room) {
            visited = new boolean[n+1];
            visited[value] = true;
            pos = true;

            dfs(value);
            if(!pos) return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
        for(int i=0; i<m; i++) rooms.add(new ArrayList<>());

        tk = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(tk.nextToken());
        for(int i=0; i<x; i++) {
            knowTruth.put(Integer.parseInt(tk.nextToken()), true);
        }

        // draw graph
        for(int i=0; i<m; i++) {
            tk = new StringTokenizer(br.readLine());
            int size = Integer.parseInt(tk.nextToken());
            for(int j=0; j<size; j++) {
                rooms.get(i).add(Integer.parseInt(tk.nextToken()));
            }
            for(int j=0; j<rooms.get(i).size()-1; j++) {
                for(int k=j+1; k<rooms.get(i).size(); k++) {
                    graph.get(rooms.get(i).get(j)).add(rooms.get(i).get(k));
                    graph.get(rooms.get(i).get(k)).add(rooms.get(i).get(j));
                }
            }
        }

        // count
        int result = 0;
        for(ArrayList<Integer> room : rooms) {
            if(canTellLie(room)) result++;
        }
        System.out.println(result);
    }
}

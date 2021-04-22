import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static int[] numOfLinks;

    static int[] topologicalSort() {
        ArrayList<Integer> result = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();

        // 진입차수가 0인 정점 queue에 삽입
        for(int i=1; i<=n; i++) if(numOfLinks[i] == 0) queue.add(i);

        while(!queue.isEmpty()) {
            // 위상정렬에 추가
            int node = queue.poll();
            result.add(node);

            // 연결 제거
            for(int i=0; i<graph.get(node).size(); i++) {
                int next = graph.get(node).get(i);
                numOfLinks[next]--;

                // 연결이 제거된 정점이 진입차수가 0이 된다면 queue에 삽입
                if(numOfLinks[next] == 0) queue.add(next);
            }
        }

        int[] answer = new int[n];
        for(int i=0; i<n; i++) answer[i] = result.get(i);
        return answer;
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());

        n = Integer.parseInt(tk.nextToken());
        for(int i=0; i<=n; i++) graph.add(new ArrayList<>());
        numOfLinks = new int[n+1];

        m = Integer.parseInt(tk.nextToken());
        for(int i=0; i<m; i++) {
            tk = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(tk.nextToken());
            int e = Integer.parseInt(tk.nextToken());

            graph.get(s).add(e);
            numOfLinks[e]++;
        }

        int[] result = topologicalSort();
        for(int i=0; i<result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}

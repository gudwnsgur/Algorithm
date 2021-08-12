import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static int[] p;
    static boolean[] erased;
    static ArrayList<ArrayList<Integer>> tree = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        p = new int[n];
        erased = new boolean[n];
        tk = new StringTokenizer(br.readLine());
        for(int i=0; i<=n; i++) tree.add(new ArrayList<>());

        for(int i=0; i<n; i++) {
            int tmp = Integer.parseInt(tk.nextToken());
            p[i] = tmp;
            if(tmp != -1) tree.get(tmp).add(i);
        }

        Queue<Integer> q = new LinkedList<>();
        int start = Integer.parseInt(br.readLine());
        q.add(start);

        while(!q.isEmpty()) {
            int cur = q.poll();
            erased[cur] = true;
            for(int i=0; i<tree.get(cur).size(); i++) {
                q.add(tree.get(cur).get(i));
            }
        }

        int result = 0;
        for(int i=0; i<n; i++) if(!erased[i] && tree.get(i).size() == 0) result++;
        if(p[start] != -1 &&  tree.get(p[start]).size() == 1) result++;

        System.out.println(result);
    }
}


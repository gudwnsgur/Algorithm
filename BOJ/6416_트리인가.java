import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {

        for (int tc = 1; ; tc++) {
            ArrayList<Integer> node = new ArrayList<>();
            HashMap<Integer, Integer> map = new HashMap<>();
            boolean isTree = true;
            int edges = 0;

            while (true) {
                boolean finished = false;
                tk = new StringTokenizer(br.readLine());
                while (tk.hasMoreElements()) {
                    int s = Integer.parseInt(tk.nextToken());
                    int e = Integer.parseInt(tk.nextToken());
                    if(s < 0 && e < 0) return;

                    if (s == 0 && e == 0) {
                        finished = true;
                        break;
                    }
                    edges++;
                    if (!map.containsKey(s)) {
                        map.put(s, 0);
                        node.add(s);
                    }

                    if (map.containsKey(e)) map.put(e, map.get(e) + 1);
                    else {
                        map.put(e, 1);
                        node.add(e);
                    }

                }
                if (finished) break;
            }
            boolean root = false;
            for(int i=0; i<node.size(); i++) {
                if(map.get(node.get(i)) == 0) {
                    if(root) isTree = false;
                    else root = true;
                }
                else if(map.get(node.get(i)) != 1) isTree = false;
            }
            if(!root || edges != node.size() - 1) isTree = false;
            if(edges == 0 ) isTree = true;
            System.out.println("Case " + tc + " is " + (isTree ? "a tree." : "not a tree."));
        }

    }
}

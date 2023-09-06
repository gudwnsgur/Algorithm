import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node {
    int num;
    int count;
    int clipboard;

    Node(int num, int count, int clipboard) {
        this.num = num;
        this.count = count;
        this.clipboard = clipboard;
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static boolean[][] visited = new boolean[10000][10000];
    static Queue<Node> queue;

    public static void main(String[] args) throws IOException {
        int s = Integer.parseInt(br.readLine());
        initialize();
        System.out.println(getResult(s));
    }

    private static int getResult(int s) {
        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            if (cur.num == s) {
                return cur.count;
            }
            if (!visited[cur.num][cur.clipboard]) {
                visited[cur.num][cur.clipboard] = true;
                queue.add(new Node(cur.num, cur.count + 1, cur.num));
                if (cur.clipboard != 0) queue.add(new Node(cur.num + cur.clipboard, cur.count + 1, cur.clipboard));
                if (cur.num > 0) queue.add(new Node(cur.num - 1, cur.count + 1, cur.clipboard));
            }
        }
        return 0;
    }

    static void initialize() {
        Node cur = new Node(1, 0, 0);
        queue = new LinkedList<>();
        queue.add(cur);
    }
}


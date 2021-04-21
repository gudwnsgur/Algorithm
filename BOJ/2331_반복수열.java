import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pair {
    int cnt, num;

    Pair(int cnt, int num) {
        this.cnt = cnt;
        this.num = num;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(tk.nextToken());
        int p = Integer.parseInt(tk.nextToken());

        // a : 1~9999, p : 1~5
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(1, a));

        HashMap<Integer, Integer> existed = new HashMap<>();
        existed.put(a, 1);

        while (!queue.isEmpty()) {
            Pair cur = queue.peek();
            int curNum = cur.num, next = 0;
            while(curNum > 0 ) {
                int x = curNum % 10;
                curNum /= 10;
                next += Math.pow(x, p);
            }
            if (existed.containsKey(next)) {
                System.out.println(existed.get(next)-1);
                return;
            }
            existed.put(next, cur.cnt+1);
            queue.add(new Pair(cur.cnt+1, next));
            queue.remove();
        }
    }
}

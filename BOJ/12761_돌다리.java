import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int a, b, n, m;
    static HashMap<Integer, Integer> map = new HashMap<>();
    static Queue<Integer> queue = new LinkedList<>();
    static int[] arr;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        a = Integer.parseInt(tk.nextToken());
        b = Integer.parseInt(tk.nextToken());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        arr = new int[6];
        arr[0] = 1; arr[1] = -1;
        arr[2] = a; arr[3] = -1*a;
        arr[4] = b; arr[5] = -1*b;

        map.put(n, 0);
        queue.add(n);
        while(!queue.isEmpty()) {
            int cur = queue.poll(), cnt = map.get(cur);
            if(cur == m) {
                System.out.println(cnt);
                return;
            }

            for(int i = 0 ; i<6; i++) {
                if(cur + arr[i] >=0 && cur + arr[i] <= 100000 && !map.containsKey(cur + arr[i])) {
                    queue.add(cur + arr[i]);
                    map.put(cur+arr[i], cnt+1);
                }
            }
            if(cur * a <= 100000 && !map.containsKey(cur*a)) {
                queue.add(cur*a);
                map.put(cur*a, cnt+1);
            }
            if(cur * b <= 100000 && !map.containsKey(cur*b)) {
                queue.add(cur*b);
                map.put(cur*b, cnt+1);
            }
        }
    }
}

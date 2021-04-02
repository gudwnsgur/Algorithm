import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Deque<Integer> q = new LinkedList<>();

        int n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++) {
            String[] op = br.readLine().split(" ");

            if(op[0].equals("push")) q.addLast(Integer.parseInt(op[1]));
            else if(op[0].equals("pop")) {
                if(q.isEmpty()) System.out.println(-1);
                else {
                    System.out.println(q.getFirst());
                    q.removeFirst();
                }
            }
            else if(op[0].equals("front")) System.out.println((q.isEmpty() ? -1 : q.getFirst()));
            else if(op[0].equals("back")) System.out.println((q.isEmpty() ? -1 : q.getLast()));
            else if(op[0].equals("size")) System.out.println(q.size());
            else System.out.println((q.isEmpty() ? 1 : 0));
        }
    }
}

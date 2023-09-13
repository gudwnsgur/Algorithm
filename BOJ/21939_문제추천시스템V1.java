import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Problem {
    int no;
    int level;

    Problem(int no, int level) {
        this.no = no;
        this.level = level;
    }
}

public class Main {
    private static final String RECOMMEND = "recommend";
    private static final String ADD = "add";
    private static final String SOLVED = "solved";
    private static final int HARDEST_PROBLEM = 1;
    private static final int EASIEST_PROBLEM = -1;
    private static final int[] problemLevel = new int[100001];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    private static PriorityQueue<Problem> maxHeap;
    private static PriorityQueue<Problem> minHeap;

    public static void main(String[] args) throws IOException {
        initialize();
        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            tk = new StringTokenizer(br.readLine());
            String command = tk.nextToken();

            if (command.equals(RECOMMEND)) recommend(Integer.parseInt(tk.nextToken()));
            else if (command.equals(ADD)) add(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken()));
            else if (command.equals(SOLVED)) solved(Integer.parseInt(tk.nextToken()));
        }
    }

    private static int compare(Problem p1, Problem p2) {
        if (p1.level > p2.level) return -1;
        else if (p1.level < p2.level) return 1;
        else {
            if (p1.no > p2.no) return -1;
            else if (p1.no < p2.no) return 1;
            else return 0;
        }
    }

    private static void initialize() throws IOException {
        maxHeap = new PriorityQueue<>((o1, o2) -> compare(o1, o2));
        minHeap = new PriorityQueue<>((o1, o2) -> compare(o2, o1));

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            int no = Integer.parseInt(tk.nextToken());
            int level = Integer.parseInt(tk.nextToken());

            maxHeap.add(new Problem(no, level));
            minHeap.add(new Problem(no, level));
            problemLevel[no] = level;
        }
    }

    private static void recommend(int option) {
        if (option == HARDEST_PROBLEM) {
            while (!maxHeap.isEmpty()) {
                Problem cur = maxHeap.peek();
                if (problemLevel[cur.no] == cur.level) {
                    System.out.println(cur.no);
                    return;
                }
                maxHeap.poll();
            }
        } else if (option == EASIEST_PROBLEM) {
            while (!minHeap.isEmpty()) {
                Problem cur = minHeap.peek();
                if (problemLevel[cur.no] == cur.level) {
                    System.out.println(cur.no);
                    return;
                }
                minHeap.poll();
            }
        }
    }

    private static void add(int no, int level) {
        problemLevel[no] = level;
        minHeap.add(new Problem(no, level));
        maxHeap.add(new Problem(no, level));
    }

    private static void solved(int no) {
        problemLevel[no] = 0;
    }
}


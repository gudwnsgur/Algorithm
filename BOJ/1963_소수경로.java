import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node {

    int number;
    int count;

    Node(int number, int count) {
        this.number = number;
        this.count = count;
    }
}

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static boolean[] isPrimeNumber = new boolean[10000];
    static boolean[] visited;
    static Queue<Node> queue;

    public static void main(String[] args) throws IOException {
        initializePrimeNumber();
        int testCase = Integer.parseInt(br.readLine());
        for (int i = 0; i < testCase; i++) {
            visited = new boolean[10000];
            queue = new LinkedList<>();
            tk = new StringTokenizer(br.readLine());
            int result = getResult(Integer.parseInt(tk.nextToken()), Integer.parseInt(tk.nextToken()));

            System.out.println(result != -1 ? result : "Impossible");
        }
    }

    private static void initializePrimeNumber() {
        for(int i=1001; i<=9999; i++) {
            isPrimeNumber[i] = isPrimeNumber(i);
        }
    }

    private static boolean isPrimeNumber(int number) {
        for (int i=2; i<number; i++) {
            if(number % i == 0) return false;
        }
        return true;
    }

    private static int getResult(int start, int target) {
        queue.add(new Node(start, 0));
        visited[start] = true;
        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            if (cur.number == target) {
                return cur.count;
            }

            String curNumber = String.valueOf(cur.number);
            for (int i = 0; i <= 9; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i != 0 || j != 0) {
                        addIfPrimeNumber(switchValue(curNumber, j, i), cur.count);
                    }
                }
            }
        }
        return -1;
    }

    private static int switchValue(String curNumber, int location, int number) {
        return Integer.parseInt(curNumber.substring(0, location) + number + curNumber.substring(location + 1));
    }

    private static void addIfPrimeNumber(int num, int curCount) {
        if (!visited[num] && isPrimeNumber[num]) {
            queue.add(new Node(num, curCount + 1));
            visited[num] = true;
        }
    }
}


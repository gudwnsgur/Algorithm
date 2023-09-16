import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class TimeStamp {
    int time;
    String status;

    public TimeStamp(int time, String status) {
        this.time = time;
        this.status = status;
    }

    public static TimeStamp start(int time) {
        return new TimeStamp(time, Main.START);
    }

    public static TimeStamp end(int time) {
        return new TimeStamp(time, Main.END);
    }
}

class Main {

    public static final String START = "START";
    public static final String END = "END";

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static PriorityQueue<TimeStamp> pq = new PriorityQueue<>((o1, o2) -> compare(o1, o2));

    public static void main(String[] args) throws IOException {
        initialize();
        int max = 0, count = 0;

        while (!pq.isEmpty()) {
            if (pq.poll().status.equals(START)) {
                count++;
            } else {
                count--;
            }

            max = Math.max(count, max);
        }
        System.out.println(max);
    }

    static void initialize() throws IOException {
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            pq.add(TimeStamp.start(Integer.parseInt(tk.nextToken())));
            pq.add(TimeStamp.end(Integer.parseInt(tk.nextToken())));
        }
    }

    static int compare(TimeStamp n1, TimeStamp n2) {
        if (n1.time < n2.time) {
            return -1;
        } else if (n1.time > n2.time) {
            return 1;
        } else {
            if (n1.status.equals(END)) {
                return -1;
            } else if (n2.status.equals(END)) {
                return 1;
            }
        }
        return 0;
    }
}


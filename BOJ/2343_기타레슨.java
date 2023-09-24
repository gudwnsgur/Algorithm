import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[] lessons;

    public static void main(String[] args) throws IOException {
        initialize();

        int max = 100000 * 10000;
        int min = 0;
        int mid = (min + max) / 2;
        int result = 100000 * 10000;

        while (true) {
            if (possibleContains(mid)) {
                max = mid;
                result = mid;
            } else {
                min = mid + 1;
            }
            if (min == mid) {
                break;
            }
            mid = (min + max) / 2;
        }
        System.out.println(result);
    }

    private static boolean possibleContains(int cur) {
        int total = 1;
        int curSize = 0;

        for (int i = 0; i < n; i++) {

            if (lessons[i] > cur) {
                return false;
            }
            if (cur >= curSize + lessons[i]) {
                curSize += lessons[i];
            } else {
                curSize = lessons[i];
                total++;
            }
        }
        return total <= m;
    }

    static void initialize() throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        lessons = new int[n];
        tk = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            lessons[i] = Integer.parseInt(tk.nextToken());
        }
    }
}


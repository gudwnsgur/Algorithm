import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, m;
    static int[] books;

    public static void main(String[] args) throws IOException {
        initialize();
        System.out.println(calculateLeft() + calculateRight() - Math.max(Math.abs(books[0]), Math.abs(books[n - 1])));
    }

    private static int calculateLeft() {
        int result = 0;
        for (int i = 0; i < n; ) {
            if (books[i] > 0) break;
            result += Math.abs(books[i]) * 2;
            i += m;
        }
        return result;
    }

    private static int calculateRight() {
        int result = 0;
        for (int i = n - 1; i >= 0; ) {
            if (books[i] < 0) break;
            result += books[i] * 2;
            i -= m;
        }
        return result;
    }

    private static void initialize() throws IOException {
        tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());
        tk = new StringTokenizer(br.readLine());
        books = new int[n];
        for (int i = 0; i < n; i++) books[i] = Integer.parseInt(tk.nextToken());
        Arrays.sort(books);
    }
}


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Parameter;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int m, n;
    static int[][] planet;

    static boolean isEqualSpace(int[] a, int[] b) {
        for (int i = 0; i < a.length - 1; i++) {
            for (int j = i + 1; j < a.length; j++) {
                if (a[i] < a[j] && b[i] >= b[j]) return false;
                if (a[i] > a[j] && b[i] <= b[j]) return false;
                if (a[i] == a[j] && (b[i] > b[j] || b[i] < b[j])) return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        m = Integer.parseInt(tk.nextToken());
        n = Integer.parseInt(tk.nextToken());
        planet = new int[m][n];

        for (int i = 0; i < m; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                planet[i][j] = Integer.parseInt(tk.nextToken());
            }
        }
        int result = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = i + 1; j < m; j++) {
                if (isEqualSpace(planet[i], planet[j])) result++;
            }
        }
        System.out.println(result);
    }
}

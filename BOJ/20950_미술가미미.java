import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class RGB {
    int red, green, blue;

    RGB(int red, int green, int blue) {
        this.red = red;
        this.green = green;
        this.blue = blue;
    }
}


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n;
    static int result = Integer.MAX_VALUE;
    static boolean[] visited;
    static RGB[] rgbs;
    static int[] arr;
    static RGB gomduri;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        rgbs = new RGB[n];

        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            rgbs[i] = new RGB(Integer.parseInt(tk.nextToken()),
                    Integer.parseInt(tk.nextToken()),
                    Integer.parseInt(tk.nextToken()));
        }
        tk = new StringTokenizer(br.readLine());
        gomduri = new RGB(Integer.parseInt(tk.nextToken()),
                Integer.parseInt(tk.nextToken()),
                Integer.parseInt(tk.nextToken()));
    }

    static void dfs(int length, int m) {
        if (length == m) {
            RGB cur = new RGB(0, 0, 0);
            for (int i = 0; i < arr.length; i++) {
                cur.red += rgbs[arr[i]].red;
                cur.green += rgbs[arr[i]].green;
                cur.blue += rgbs[arr[i]].blue;
            }
            cur.red /= arr.length;
            cur.green /= arr.length;
            cur.blue /= arr.length;

            result = Math.min(result, Math.abs(cur.red - gomduri.red) +
                    Math.abs(cur.green - gomduri.green) + Math.abs(cur.blue - gomduri.blue));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (length == 0 || arr[length - 1] < i) {
                    visited[i] = true;
                    arr[length] = i;
                    dfs(length + 1, m);
                    visited[i] = false;
                }
            }
        }

    }

    public static void main(String[] args) throws IOException {
        input();
        for (int i = 2; i <= 7; i++) {
            visited = new boolean[n];
            arr = new int[i];
            dfs(0, i);
        }
        System.out.println(result);
    }
}

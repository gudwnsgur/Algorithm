import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static boolean isPrimeNumber(int num) {
        if (num == 0 || num == 1) return false;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    static void dfs(int len, int n, String str) {
        if (len == n) {
            System.out.println(str);
            return;
        }
        for (int i = 0; i <= 9; i++) {
            String cur = str + (char) (i + 48);
            if (isPrimeNumber(Integer.parseInt(cur))) {
                dfs(len + 1, n, cur);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        dfs(0, n, "");
    }
}

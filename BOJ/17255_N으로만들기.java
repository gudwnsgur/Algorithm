import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String N;
    static char[] arr;
    static int cnt =0 ;
    static Set<String> set = new HashSet<>();
    static boolean[] visited;

    static void dfs(int len, int n, String order, String str) {
        if (len == n && str.equals(N)) {
            if(!set.contains(order)) {
                set.add(order);
                cnt++;
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(len + 1, n, order + arr[i] + str, N.charAt(i) + str);
                dfs(len + 1, n, order + str + arr[i], str + N.charAt(i));
                visited[i] = false;
            }
        }
    }


    public static void main(String[] args) throws IOException {
        N = br.readLine();
        visited = new boolean[N.length()];
        arr = new char[N.length()];
        for(int i=0; i<N.length(); i++) arr[i] = N.charAt(i);

        dfs(0, N.length(), "", "");
        System.out.println(cnt);
    }
}



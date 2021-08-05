import java.util.*;
import java.io.*;

class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int cnt = n;
        for(int i=0; i<n; i++) {
            boolean[] used = new boolean[150];
            String str = br.readLine();
            used[str.charAt(0)] = true;
            for(int j=1; j<str.length(); j++) {
                if(used[str.charAt(j)] && str.charAt(j-1) != str.charAt(j)) {
                   cnt--;
                   break;
                }
                used[str.charAt(j)] = true;
            }
        }
        System.out.println(cnt);

    }
}

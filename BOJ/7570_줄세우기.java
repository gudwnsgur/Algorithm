import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static  StringTokenizer tk;
    static HashMap<Integer, Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());
        tk = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            map.put(Integer.parseInt(tk.nextToken()), i);
        }

        int result = 1, cnt = 1, prev = map.get(1);
        for(int i=2; i<=n; i++) {
            if(map.get(i) > prev) cnt++;
            else {
                result = Math.max(result, cnt);
                cnt = 1;
            }
            prev = map.get(i);
        }
        System.out.println(n - result);
    }
}

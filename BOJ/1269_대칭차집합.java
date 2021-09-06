import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int[] aArr, bArr;
    static Set<Integer> a = new HashSet<>();
    static Set<Integer> b = new HashSet<>();
    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tk.nextToken());
        int m = Integer.parseInt(tk.nextToken());
        aArr = new int[n];
        bArr = new int[m];

        tk = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            aArr[i] =Integer.parseInt(tk.nextToken());
            a.add(aArr[i]);
        }
        tk = new StringTokenizer(br.readLine());
        for(int i=0; i<m; i++) {
            bArr[i] = Integer.parseInt(tk.nextToken());
            b.add(bArr[i]);
        }

        int cnt = 0;
        for(int i=0; i<n; i++) if(!b.contains(aArr[i])) cnt++;
        for(int i=0; i<m; i++) if(!a.contains(bArr[i])) cnt++;
        System.out.println(cnt);
    }
}



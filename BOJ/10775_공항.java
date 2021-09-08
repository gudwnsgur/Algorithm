import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int gate, plain;
    static int[] arr;
    static int[] cnt;

    static void unionParents(int a, int b) {
        a = getParnets(a);
        b = getParnets(b);
        if (a < b) cnt[b] = a;
        else cnt[a] = b;
    }

    static int getParnets(int a) {
        if (cnt[a] == a) return a;
        return cnt[a] = getParnets(cnt[a]);
    }

    static void union(int a, int b) {
        if (getParnets(a) != getParnets(b)) {
            unionParents(a, b);
        }
    }

    public static void main(String[] args) throws IOException {
        gate = Integer.parseInt(br.readLine());
        plain = Integer.parseInt(br.readLine());
        arr = new int[plain];
        cnt = new int[gate + 1];
        for (int i = 0; i <= gate; i++) cnt[i] = i;

        int[] arr = new int[plain];
        for (int i = 0; i < plain; i++) arr[i] = Integer.parseInt(br.readLine());

        int result = 0;
        for (int i = 0; i < plain; i++) {
            int target = arr[i];
            if(getParnets(target) == 0) break;
            union(getParnets(target), getParnets(target)-1);
            result++;
        }
        System.out.println(result);
    }
}



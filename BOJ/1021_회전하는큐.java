import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tk.nextToken()), m = Integer.parseInt(tk.nextToken());

        int answer = 0;
        int start = 5000, len = n;
        int[] arr = new int[10000];
        for (int i = start; i < start + len; i++) arr[i] = i - start + 1;


        tk = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            int num = Integer.parseInt(tk.nextToken());
            if (num == arr[start]) {
                start++;
                len--;
                continue;
            }
            int idx = start;
            while (arr[idx] != num) idx++;
            if (idx - start <= start + len - 1 - idx) {
                for (int j = start; j < idx; j++) {
                    answer++;
                    arr[j + len] = arr[j];
                }
                start = idx + 1;
                len--;
            } else {
                for (int j = start + len - 1; j >= idx; j--) {
                    answer++;
                    arr[j - len] = arr[j];
                }
                start =  1 + idx - len;
                len--;
            }
        }
        System.out.print(answer);
    }
}


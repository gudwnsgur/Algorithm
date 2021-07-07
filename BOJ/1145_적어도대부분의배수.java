import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;


    public static void main(String[] args) throws IOException {
        int[] arr = new int[5];
        tk = new StringTokenizer(br.readLine());
        for (int i = 0; i < arr.length; i++) arr[i] = Integer.parseInt(tk.nextToken());

        for(int i=1; i<100*99*98; i++) {
            int cnt = 0;
            for(int j=0; j<5; j++) {
                if(i % arr[j] == 0) cnt++;
            }
            if(cnt >= 3) {
                System.out.println(i);
                return;
            }
        }

    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tk.nextToken());
        int k = Integer.parseInt(tk.nextToken());

        String number = br.readLine();
        StringBuilder answer = new StringBuilder();

        for(int i=0; i<n;) {
            if(n-i == k) {
                System.out.println(answer);
                return;
            }

            int maxIdx = i;
            char maxNum = number.charAt(i);
            if(maxNum != '9') {
                for (int j = i; j < i + k + 1 && j < n; j++) {
                    if (number.charAt(j) > maxNum) {
                        maxIdx = j;
                        maxNum = number.charAt(j);
                        if(number.charAt(j) == '9') break;
                    }
                }
            }
            answer.append(maxNum);
            k -= maxIdx - i;
            i = maxIdx + 1;
        }
        System.out.println(answer);
    }
}

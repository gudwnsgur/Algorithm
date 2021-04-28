import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int cnt = 0, n;
    static boolean isFinished = false;
    static String result = "";
    static int[] arr;


    static void dfs(int length, int m) {
        if(isFinished) return;
        if(length == m) {
            if(cnt == n) {
                isFinished = true;
                for(int i=0; i<arr.length; i++) result += arr[i];
                return;
            }

            cnt++;
            return;
        }
        for(int i=0; i<=9; i++) {
            if(!isFinished && (length == 0 || (length != 0 && arr[length-1] > i))) {
                arr[length] = i;
                dfs(length+1, m);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        if(n >= 1023) {
            System.out.println(-1);
            return;
        }
        
        for(int i=1; i<=10; i++) {
            arr = new int[i];
            dfs(0, i);
            if(isFinished) break;
        }
        System.out.println(result);
    }
}


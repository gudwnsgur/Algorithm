
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] arr;

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = Integer.parseInt(br.readLine());

        int x = arr[0];
        int cnt = 1;
        for(int i=1; i<n; i++) {
            if(x < arr[i]) {
                cnt++;
                x = arr[i];
            }
        }

        System.out.println(cnt);
        x = arr[n-1];
        cnt =1;
        for(int i=n-2; i>=0; i--) {
            if(x <arr[i]) {
                cnt++;
                x = arr[i];
            }
        }
        System.out.println(cnt);
    }
}


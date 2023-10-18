import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        tk = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            arr[i] = Integer.parseInt(tk.nextToken());
        }
        Arrays.sort(arr);
        System.out.println(getResult(n, arr));
    }

    static int getResult(int n, int[] arr) {
        if(arr[0] >= 0) return arr[0] + arr[1];
        if(arr[n-1] <= 0) return arr[n-1] + arr[n-2];
        int positiveIdx = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] >= 0) {
                positiveIdx = i;
                break;
            }
        }
        int negativeIdx = positiveIdx-1;
        int result = Integer.MAX_VALUE;
        if(positiveIdx < n-1) result = arr[positiveIdx] + arr[positiveIdx+1];
        if(negativeIdx > 0) result = result < Math.abs(arr[negativeIdx] + arr[negativeIdx-1]) ?
                                     result : arr[negativeIdx] + arr[negativeIdx-1];

        while(negativeIdx >= 0 && positiveIdx < n) {
            int cur = arr[negativeIdx] + arr[positiveIdx];
            result = Math.abs(result) < Math.abs(cur) ? result : cur;
            if(cur < 0) positiveIdx++;
            else if(cur > 0) negativeIdx--;
            else return 0;
        }
        return result;
    }
}


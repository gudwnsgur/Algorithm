import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    public static void main(String[] args) throws IOException {
        tk = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tk.nextToken());
        int limit = Integer.parseInt(tk.nextToken());

        int[][] info = new int[n+1][n+1];
        int query = Integer.parseInt(br.readLine());
        for(int i=0; i<query; i++) {
            tk = new StringTokenizer(br.readLine());
            info[Integer.parseInt(tk.nextToken())][Integer.parseInt(tk.nextToken())] = Integer.parseInt(tk.nextToken());
        }


        int total = 0;
        int result = 0;
        int[] truck = new int[n+1];
        for(int i=1; i<=n; i++) {
            result += truck[i];
            total -= truck[i];
            truck[i] = 0;
            for(int j=i+1; j<=n; j++) {
                if(total + info[i][j] <= limit) {
                    total += info[i][j];
                    truck[j] += info[i][j];
                }
                else {
                    for(int k = n ; k>=j; k--) {
                        int cur = Math.min(( limit - total  +  truck[k]), info[i][j]);
                        truck[j] += cur;
                        total += cur;
                        truck[k] -= (total - limit);
                        total = limit;
                    }
                }
            }
        }
        System.out.println(result);
    }
}

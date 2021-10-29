import java.io.*;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int[][][] result = new int[51][51][51];
    static final int INF = 987654321;

    static int w(int a, int b, int c) {
        if(a <=0 || b<=0 || c<=0) return result[a][b][c] = 1;
        else if(result[a][b][c] != INF) return result[a][b][c];
        else if(a > 20 || b > 20 || c > 20) return result[a][b][c] = w(20, 20, 20);
        else if(a < b && b < c) return result[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
        else  return result[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    }

    static void solution() {
        for(int i=0; i<=50; i++) {
            for(int j=0; j<=50; j++) {
                for(int k=0; k<=50; k++) {
                    result[i][j][k] = w(i, j, k);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        for(int i=0; i<51; i++) {
            for(int j=0; j<51; j++) {
                Arrays.fill(result[i][j], INF);
            }
        }


        solution();
        int a, b, c;
        tk = new StringTokenizer(br.readLine());
        a = Integer.parseInt(tk.nextToken());
        b = Integer.parseInt(tk.nextToken());
        c = Integer.parseInt(tk.nextToken());
        while(a != -1 || b != -1 || c != -1) {
            System.out.print("w(" + a + ", " + b + ", " + c +") = ");
            System.out.println((a<0 || b<0 || c<0 ? 1 : result[a][b][c]));

            tk = new StringTokenizer(br.readLine());
            a = Integer.parseInt(tk.nextToken());
            b = Integer.parseInt(tk.nextToken());
            c = Integer.parseInt(tk.nextToken());
        }
    }
}

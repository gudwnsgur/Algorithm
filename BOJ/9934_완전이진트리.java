import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int depth, n;
    static int[] arr;
    static ArrayList<Integer> order = new ArrayList<>();

    static void inorder(int node) {
        if(node > n) return;
        inorder(node*2);
        order.add(node);
        inorder(node*2+1);
    }

    public static void main(String[] args) throws IOException {
        depth = Integer.parseInt(br.readLine());
        n = (int)(Math.pow(2, depth) - 1); // 7
        order.add(0);

        arr = new int[n+1]; // 8
        tk =new StringTokenizer(br.readLine());
        for(int i=1; i<=n; i++) arr[i] = Integer.parseInt(tk.nextToken());

        inorder(1);


        int[] result = new int[n+1];
        for(int i=1; i<=n; i++) {
            result[order.get(i)] = arr[i];
        }

        for(int i=1; i<=n; i*=2) {
            for(int j=i; j< i*2; j++) {
                System.out.print(result[j] + " ");
            }
            System.out.println();
        }
    }
}

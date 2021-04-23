import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    static void postorder(int left, int right, int cur, int[] preorder, int[] inorder) {
        for(int i=left; i<right; i++) {
            if(inorder[i] == preorder[cur]) {
                postorder(left, i, cur+1, preorder, inorder);
                postorder(i+1, right, cur+i-left+1, preorder, inorder);
                System.out.print(preorder[cur] + " ");
            }
        }
    }
    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());
        while(tc-- > 0 ) {
            int n = Integer.parseInt(br.readLine());

            int[] preorder = new int[n];
            tk = new StringTokenizer(br.readLine());
            for(int i=0; i<n; i++) preorder[i] = Integer.parseInt(tk.nextToken());

            int[] inorder = new int[n];
            tk = new StringTokenizer(br.readLine());
            for(int i=0; i<n; i++) inorder[i] = Integer.parseInt(tk.nextToken());

            postorder(0, n, 0, preorder, inorder);
            System.out.println();
        }
    }
}

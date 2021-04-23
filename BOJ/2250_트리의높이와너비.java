import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Node {
    int data, left, right;
    Node(int data) {
        this.data = data;
        this.left = -1;
        this.right = -1;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    static boolean[] isNotRootNode;
    static int[][] level; // [level][min, max]
    static int order = 1;
    static int maxLevel = -1;
    static ArrayList<Node> bTree = new ArrayList<>();

    static void inorder(int cur, int lev) {
        if(cur != -1) {
            inorder(bTree.get(cur).left, lev+1);

            maxLevel = Math.max(maxLevel, lev);
            level[lev][0] = Math.min(level[lev][0], order);
            level[lev][1]  = Math.max(level[lev][1], order);
            order++;

            inorder(bTree.get(cur).right, lev+1);
        }
    }

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        level = new int[n+1][2];
        isNotRootNode = new boolean[n+1];

        for(int i=0; i<=n; i++) {
            bTree.add(new Node(i));
            level[i][0] = n;
            level[i][1] = 0;
        }

        for(int i=0; i<n; i++) {
            tk = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(tk.nextToken());
            int left = Integer.parseInt(tk.nextToken());
            int right = Integer.parseInt(tk.nextToken());

            bTree.get(p).left = left;
            bTree.get(p).right = right;
            if(left != -1) isNotRootNode[left] = true;
            if(right != -1) isNotRootNode[right] = true;
        }
        int root = 0;
        for(int i=1; i<=n; i++) {
            if(!isNotRootNode[i]) {
                root = i;
                break;
            }
        }

        inorder(root, 1);
        int resultLev=1, resultWidth=1;
        for(int i=1; i<=maxLevel; i++) {
//            System.out.println(i + " " + (level[i][1] - level[i][0] + 1));
            if(level[i][1] - level[i][0] + 1 > resultWidth) {
                resultWidth = level[i][1] - level[i][0] + 1;
                resultLev = i;
            }
        }
        System.out.println(resultLev + " " + resultWidth);
    }
}

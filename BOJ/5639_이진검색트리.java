import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Node {
    private final int data;
    private Node left, right;

    public Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
    public int getData() { return data; }
    public void setLeft(Node left) {this.left = left;}
    public void setRight(Node right) {this.right = right;}

    public Node getLeft() { return left; }
    public Node getRight() { return right; }
}

class BST {
    private final Node root;

    public BST(int data) { this.root = new Node(data); }
    public Node getRoot() { return root; }

    public void insert(Node cur) {
        Node p= root, q = root;
        while(q != null) {
            p = q;
            q = (cur.getData() < p.getData() ? p.getLeft() : p.getRight());
        }
        if(cur.getData() < p.getData()) p.setLeft(cur);
        else p.setRight(cur);
    }
    public void postorder(Node node) {
        if(node != null) {
            postorder(node.getLeft());
            postorder(node.getRight());
            System.out.print(node.getData() + " ");
        }
    }

}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    public static void main(String[] args) throws IOException {
        int root = Integer.parseInt(br.readLine());
        BST bst = new BST(root);

        String line = br.readLine();
        while(line != null) {
            int x = Integer.parseInt(line);
            bst.insert(new Node(x));
            line = br.readLine();
        }
        bst.postorder(bst.getRoot());
    }
}

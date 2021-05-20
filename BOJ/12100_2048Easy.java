import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node {
    int value;
    boolean unioned;

    Node(int value, boolean unioned) {
        this.value = value;
        this.unioned = unioned;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;
    static int n, result = 0;

    static void dfs(int length, int cnt, int dir, int[][] tmp) {
        int[][] board = new int[n][n];
        for(int i=0; i<n; i++) {
            System.arraycopy(tmp[i], 0, board[i], 0, n);
        }
        if (length == cnt) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    result = Math.max(result, board[i][j]);
                }
            }
            return;
        }

        Stack<Node> s = new Stack<>();
        if(dir == 0) {
            for (int i = 0; i < n; i++) {
                s.clear();
                for (int j = n - 1; j >= 0; j--) {
                    if (board[i][j] == 0) continue;

                    if (!s.isEmpty() && s.peek().value == board[i][j] && !s.peek().unioned) {
                        s.add(new Node(s.pop().value * 2, true));
                    }
                    else s.add(new Node(board[i][j], false));
                }

                for (int j = 0; j < (n - s.size()); j++) board[i][j] = 0;
                for (int j = n - s.size(); j < n; j++) board[i][j] = s.pop().value;
            }
        }
        else if(dir == 1) {
            for (int i = 0; i < n; i++) {
                s.clear();
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 0) continue;
                    if (!s.isEmpty() && s.peek().value == board[i][j] && !s.peek().unioned) {
                        s.add(new Node(s.pop().value * 2, true));
                    } else s.add(new Node(board[i][j], false));
                }

                for (int j = n - 1; j >= s.size(); j--) board[i][j] = 0;
                for (int j = s.size() - 1; j >= 0; j--) board[i][j] = s.pop().value;
            }
        }
        else if(dir == 2) {
            for (int i = 0; i < n; i++) {
                s.clear();
                for (int j = 0; j < n; j++) {
                    if (board[j][i] == 0) continue;
                    if (!s.isEmpty() && s.peek().value == board[j][i] && !s.peek().unioned) {
                        s.add(new Node(s.pop().value * 2, true));
                    } else s.add(new Node(board[j][i], false));
                }
                for (int j = n - 1; j >= s.size(); j--) board[j][i] = 0;
                for (int j = s.size() - 1; j >= 0; j--) board[j][i] = s.pop().value;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                s.clear();
                for (int j = n - 1; j >= 0; j--) {
                    if (board[j][i] == 0) continue;

                    if (!s.isEmpty() && s.peek().value == board[j][i] && !s.peek().unioned) {
                        s.add(new Node(s.pop().value * 2, true));
                    } else s.add(new Node(board[j][i], false));
                }

                for (int j = 0; j < (n - s.size()); j++) board[j][i] = 0;
                for (int j = n - s.size(); j < n; j++) board[j][i] = s.pop().value;
            }
        }
        for (int i = 0; i < 4; i++) dfs(length + 1, cnt, i, board);
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        int[][] board = new int[n][n];
        for (int i = 0; i < n; i++) {
            tk = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) board[i][j] = Integer.parseInt(tk.nextToken());
        }

        for (int i = 0; i < 4; i++) dfs(0, 5, i, board);
        System.out.println(result);
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Loc {
    int x, y;
    Loc(int x, int y ) {
        this.x = x;
        this.y = y;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] sudoku = new int[9][9];
    static ArrayList<Loc> empty = new ArrayList<>();
    static int[] arr;
    static boolean isFinished = false;

    static boolean promise(int x, int y, int num) {
        for(int i=0; i<9; i++) if(sudoku[x][i] == num) return false;
        for(int i=0; i<9; i++) if(sudoku[i][y] == num) return false;

        for(int i=(x/3)*3; i < (x/3)*3 + 3; i++) {
            for(int j=(y/3)*3; j<(y/3)*3 + 3; j++) {
                if(sudoku[i][j] == num) return false;
            }
        }
        return true;
    }

    static void dfs(int length, int n) {
        if(length == n) {
            isFinished = true;
            return;
        }

        int curX = empty.get(length).x;
        int curY = empty.get(length).y;
        for(int i=1; i<=9; i++) {
            if(promise(curX, curY, i)) {
                sudoku[curX][curY] = i;
                dfs(length+1, n);
                if(isFinished) return;
                sudoku[curX][curY] = 0;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        for(int i=0; i<9; i++) {
            String s = br.readLine();
            for(int j=0; j<9; j++) {
                sudoku[i][j] = s.charAt(j) - 48;
                if(sudoku[i][j] == 0) empty.add(new Loc(i, j));
            }
        }

        arr = new int[empty.size()];
        dfs(0, empty.size());



        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                System.out.print(sudoku[i][j]);
            }
            System.out.println();
        }

    }
}


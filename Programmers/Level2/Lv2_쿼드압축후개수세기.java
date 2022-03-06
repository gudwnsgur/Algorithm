import java.util.*;

class Solution {
    int[][] map;
    int one = 0, zero = 0;

    void recursive(int x1, int y1, int x2, int y2) {
        if (x2 - x1 <= 1 && y2 - y1 <= 1) {
            if (map[x1][y1] == 1) one++;
            else zero++;
            return;
        }

        boolean pos = true;
        for (int i = x1; i < x2; i++) {
            if (!pos) break;
            for (int j = y1; j < y2; j++) {
                if (map[i][j] != map[x1][y1]) {
                    pos = false;
                    break;
                }
            }
        }
        if (pos) {
            if (map[x1][y1] == 1) one++;
            else zero++;
            return;
        }

        recursive(x1, y1, (x1+x2)/2, (y1+y2)/2);
        recursive(x1, (y1+y2)/2, (x1+x2)/2, y2 );
        recursive((x1+x2)/2, y1, x2, (y1+y2)/2);
        recursive((x1+x2)/2, (y1+y2)/2, x2, y2);
    }

    public int[] solution(int[][] arr) {
        int[] answer = new int[2];
        map = arr;
        recursive(0, 0, arr.length, arr.length);
        answer[0] = zero;
        answer[1] = one;
        return answer;
    }
}


class Main{
    public static void main (String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution(new int[][]{{1,1,0,0},{1,0,0,0}, {1,0,0,1}, {1,1,1,1}}));
    }
}

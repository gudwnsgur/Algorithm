import java.util.*;

class Solution {
    boolean[] op;
    int[] number;
    int result = 0;

    void dfs(int length, int n, int target) {
        if (length == n) {
            int cur = 0;
            for (int i = 0; i < op.length; i++) {
                cur += (op[i] ? number[i] : number[i] * -1);
            }
            if (cur == target) result++;
            return;
        }
        op[length] = false;
        dfs(length + 1, n, target);
        op[length] = true;
        dfs(length + 1, n, target);
    }

    public int solution(int[] numbers, int target) {
        op = new boolean[numbers.length];
        number = numbers;
        dfs(0, numbers.length, target);
        return result;
    }
}

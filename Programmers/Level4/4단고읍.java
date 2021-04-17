import java.util.*;

class Solution {
    int result = 0;

    void dfs(int n, int minus) {
        if (n == 1 && minus == 0) {
            result++;
            return;
        }
        int minDiv = (minus % 2 == 1 ? minus / 2 + 1 : minus / 2);
        if (Math.pow(3, minDiv) > n) return;

        dfs(n - 1, minus + 1);
        if (n % 3 == 0 && minus >= 2) dfs(n / 3, minus - 2);
    }

    public int solution(int n) {
        dfs(n-2, 2);
        return result;
    }
}

import java.util.*;

class Solution {
    boolean[] visited = new boolean[8];
    char[] result = new char[8];
    char[] source = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    String[] rule;
    int answer = 0;

    boolean promise() {
        for( int i=0; i<rule.length;i ++) {
            int a = -1, b = -1;
            for(int j=0;  j<result.length; j++) {
                if(result[j] == rule[i].charAt(0)) a = j;
                if(result[j] == rule[i].charAt(2)) b = j;
            }
            if(rule[i].charAt(3) == '=' && (rule[i].charAt(4) - 48 != Math.abs(b - a) -1)) return false;
            if(rule[i].charAt(3) == '>' && (rule[i].charAt(4) - 48 >= Math.abs(b - a) -1)) return false;
            if(rule[i].charAt(3) == '<' && (rule[i].charAt(4) - 48 <= Math.abs(b - a) -1)) return false;
        }
        return true;
    }

    void dfs(int length) {
        if(length == 8) {
            if(promise()) answer++;
            return;
        }
        for(int i=0; i<8; i++) {
            if(!visited[i]) {
                visited[i] = true;
                result[length] = source[i];
                dfs(length+1);
                visited[i] = false;
            }
        }
    }
    public int solution(int n, String[] data) {
        rule = data;
        dfs(0);
        return answer;
    }
}

class Main{
    public static void main (String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution(2, new String[] {"N~F=0", "R~T>2"}));
    }
}

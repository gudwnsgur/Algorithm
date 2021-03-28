import java.util.*;

class Solution {
    char[] arr;
    boolean[] visited;
    String str;
    ArrayList<Integer> result = new ArrayList<>();

    boolean isPrimeNumber(int num) {
        if(num ==0 || num ==1) return false;
        for(int i=2; i<num; i++) {
            if(num % i == 0) return false;
        }
        return true;
    }

    void dfs(int length, int n) {
        if(length == n) {
            String tmp = "";
            for (char c : arr) tmp += c;
            int num = Integer.parseInt(tmp);
            if(!result.contains(num) && isPrimeNumber(num)) result.add(num);
            return;
        }

        for(int i=0; i<str.length(); i++) {
            if(!visited[i]) {
                visited[i] = true;
                arr[length] = str.charAt(i);
                dfs(length+1, n);
                visited[i] = false;
            }
        }
    }


    public int solution(String numbers) {
        str = numbers;
        for(int i=1; i<=numbers.length(); i++) {
            visited = new boolean[str.length()];
            arr = new char[i];
            dfs(0, i);
        }

        for(int i=0; i<result.size(); i++) System.out.println(result.get(i));
        return result.size();
    }
}
class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution("1232"));
    }
}


import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];

        for(int i=0; i<prices.length-1; i++) {
            int cnt = 0;
            for(int j=i+1; j <prices.length; j++) {
                cnt ++;
                if(prices[i] > prices[j]) break;
            }
            answer[i] = cnt;
        }
        answer[answer.length-1] = 0;
        return answer;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

    }
}

import java.util.*;

class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];

        int wh = brown+yellow;
        int wPlush = (brown+4)/2;


        for(int i=1; i<= wPlush/2; i++) {
            if(i * (wPlush-i) == wh) {
                answer[1] = i;
                answer[0] = wPlush-i;
                return answer;
            }
        }
        return answer;
    }
}

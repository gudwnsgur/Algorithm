import java.util.*;

class Solution {
    int[] citation;

    boolean isPossibleH(int h) {
        int left = 0, right = 0;
        for (int value : citation) {
            if (value < h) left++;
            else right++;
        }
        return left < h && right >= h;
    }

    public int solution(int[] citations) {
        Arrays.sort(citations);
        citation = citations;

        int result = citations.length;
        while(result >= 0) {
            if(isPossibleH(result)) return result;
            result--;
        }
        return 0;
    }
}


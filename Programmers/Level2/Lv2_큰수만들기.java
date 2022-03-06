import java.util.*;
class Solution {
    public String solution(String number, int k) {
        String answer = "";
        for(int i=0; i<number.length();) {
            if(number.length()-i == k) return answer;

            int maxIdx = i;
            char maxNum = number.charAt(i);
            if(maxNum != '9') {
                for (int j = i; j < i + k + 1 && j < number.length(); j++) {
                    if (number.charAt(j) > maxNum) {
                        maxIdx = j;
                        maxNum = number.charAt(j);
                        if(number.charAt(j) == '9') break;
                    }
                }
            }
            answer += maxNum;
            k -= maxIdx - i;
            i = maxIdx + 1;
        }
        return answer;
    }
}
class Main{
    public static void main (String[] args) {
        Solution solution = new Solution();
    }
}

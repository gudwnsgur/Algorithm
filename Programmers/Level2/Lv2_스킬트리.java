import java.util.*;

class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        int[] alphabet = new int[26];
        for(int i=0; i<26; i++) alphabet[i] = -1;
        for(int i=0; i<skill.length(); i++) alphabet[skill.charAt(i) - 'A'] = i;

        for(String str : skill_trees) {
            boolean pos = true;
            int idx = 0;
            for(int i=0; i<str.length(); i++) {
                int cur = alphabet[str.charAt(i)-'A'];
                if(cur == -1) continue;

                if(cur == idx) idx = cur+1;
                else {
                    pos = false;
                    break;
                }
            }
            if(pos) answer++;
        }
        return answer;
    }
}
class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
    }
}


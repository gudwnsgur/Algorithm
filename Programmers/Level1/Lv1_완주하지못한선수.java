import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        Arrays.sort(participant);
        Arrays.sort(completion);

        for (int i = 0; i < completion.length; i++) {
            if (!participant[i].equals(completion[i])) return participant[i];
        }
        return participant[participant.length-1];
    }
}

class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(new String[]{"leo", "kiki", "eden"},
                new String[]{"eden", "kiki"}));
    }
}


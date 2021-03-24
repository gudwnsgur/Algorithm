
import java.util.*;
import static java.lang.Math.max;

class Solution {
    public int[] solution(int[] answers) {
        ArrayList<Integer> answer = new ArrayList<>();
        int[] count = {0, 0, 0};

        int[] A = {1, 2, 3, 4, 5};
        int[] B = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] C = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

        for(int i=0; i<answers.length; i++){
            if(answers[i] == A[i%5]) count[0]++;
            if(answers[i] == B[i%8]) count[1]++;
            if(answers[i] == C[i%10]) count[2]++;
        }

        int max = max(count[0], max(count[1], count[2]));
        for(int i=0; i<3; i++) {
            if(count[i] == max) answer.add(i+1);
        }

        int[] ans = new int[answer.size()];
        for(int i=0; i<answer.size(); i++) {
            ans[i] = answer.get(i);
        }
        return ans;
    }
}

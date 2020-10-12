
import java.util.ArrayList;
import java.util.List;

class Solution {
    private boolean[] existed = new boolean[201];
    public int[] solution(int[] numbers) {
        List<Integer> list = new ArrayList<>();
        int [] answer;
        for(int i=0; i<numbers.length-1; i++) {
            for(int j=i+1; j<numbers.length; j++) {
                existed[numbers[i]+numbers[j]] = true;
            }
        }
        for(int i=0; i<=200; i++) {
            if (existed[i]) list.add(i);
        }
        int i =0;
        answer = new int[list.size()];
        for(int num : list) {
            answer[i++] = num;
        }
        return answer;
    }
}

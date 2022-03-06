import java.util.*;

class Solution {

    int calculateDay(int progress, int speed) {
        return (100 - progress) % speed == 0 ?
                (100 - progress) / speed :
                (100 - progress) / speed + 1;
    }

    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> result = new ArrayList<>();
        int n = progresses.length;
        int idx = 0;

        while (idx < n) {
            int cur = calculateDay(progresses[idx], speeds[idx]);
            int curCnt = 1;
            idx++;
            while (idx < n && calculateDay(progresses[idx], speeds[idx]) <= cur) {
                idx++;
                curCnt++;
            }
            result.add(curCnt);
        }


        int[] answer = new int[result.size()];
        for (
                int i = 0;
                i < answer.length; i++)
            answer[i] = result.get(i);
        return answer;
    }
}

class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] arr = s.solution(new int[]{93, 30, 55}, new int[]{1, 30, 5});

        for (int value : arr) System.out.println(value);

    }
}


import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        ArrayList<Integer> answer = new ArrayList<>();

        for (int[] command : commands) {
            ArrayList<Integer> arr = new ArrayList<>();

            int s = command[0], e = command[1], loc = command[2];

            for (int j = s - 1; j <= e - 1; j++) arr.add(array[j]);
            Collections.sort(arr);
            answer.add(arr.get(loc - 1));
        }

        int[] ans = new int[answer.size()];
        for(int i =0 ; i<answer.size(); i++) {
            ans[i] = answer.get(i);
        }
        return ans;
    }
}


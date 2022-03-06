import java.util.*;

class Solution {
    public int solution(int[][] triangle) {
        ArrayList<int[]> dp = new ArrayList<>();
        dp.addAll(Arrays.asList(triangle));

        for(int i=1; i<dp.size(); i++) {
            for(int j=0; j<dp.get(i).length; j++) {
                if(j == 0) dp.get(i)[j] += dp.get(i-1)[j];
                else if(j == dp.get(i).length-1) dp.get(i)[j] += dp.get(i-1)[j-1];
                else dp.get(i)[j] += Math.max(dp.get(i-1)[j-1], dp.get(i-1)[j]);
            }
        }


        int answer = dp.get(dp.size()-1)[0];
        for(int i=1; i < dp.get(dp.size()-1).length; i++) answer = Math.max(answer, dp.get(dp.size()-1)[i]);
        return answer;
    }
}

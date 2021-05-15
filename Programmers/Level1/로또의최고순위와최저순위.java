class Solution {
    public final int[] rank = {6, 6, 5, 4, 3, 2, 1};
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        int zero = 0, right = 0;
        for(int i=0; i<6; i++) {
            if(lottos[i] == 0) {
                zero++;
                continue;
            }
            for(int j = 0; j<6; j++)
                if(lottos[i] == win_nums[j]) right++;
        }
        answer[0] = rank[right+zero];
        answer[1] = rank[right];
        return answer;
    }
}

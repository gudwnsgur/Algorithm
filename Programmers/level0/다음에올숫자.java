class Solution {
    public int solution(int[] common) {
        return common[1]-common[0] == common[2]-common[1] ? common[0] + (common[1]-common[0])*common.length : common[0] * (int)Math.pow(common[1]/common[0], common.length);
    }
}


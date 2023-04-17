class Solution {
    public int[] solution(int num, int total) {
        int[] nums = new int[num];
        for(int i=0, j = total/num -  (num % 2 == 0 ? (num-(num/2 +1)) : (num-(num/2)-1)); i<nums.length; i++, j++)
            nums[i]=j;
        return nums;
    }
}

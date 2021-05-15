class Solution {
    boolean isEven(int num) {
        int cnt = 0;
        for(int i=1; i<=num; i++) {
            if(num % i == 0) cnt++;
        }
        return cnt % 2 == 0;
    }
    public int solution(int left, int right) {
        int answer = 0;
        for(int num = left; num <= right; num++) {
            answer += (isEven(num) ? num : num*-1);
        }
        return answer;
    }
}

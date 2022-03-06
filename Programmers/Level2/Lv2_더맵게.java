import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0; i<scoville.length; i++) pq.add(scoville[i]);

        int result = 0;
        while(!pq.isEmpty()) {
            if(pq.element() >= K) return result;
            result++;

            int a = pq.element();
            pq.remove();
            if(pq.isEmpty()) return -1;
            int b = pq.element();
            pq.remove();

            pq.add(a + b*2);
        }
        return -1;
    }
}
class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

    }
}


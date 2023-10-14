import java.util.PriorityQueue;

class Node {
    int index;
    int value;
    Node(int index, int value) {
        this.index = index;
        this.value = value;
    }
}
class Solution {

    public int solution(int[] stones, int k) {
        PriorityQueue<Node> pq = new PriorityQueue<Node>(((o1, o2) -> {
            if(o1.value > o2.value )return -1;
            else if(o1.value < o2.value) return 1;
            else return 0;
        }));
        for(int i=0; i<k; i++) {
            pq.add(new Node(i, stones[i]));
        }
        int result = pq.peek().value;
        for(int i=k; i<stones.length; i++) {
            pq.add(new Node(i, stones[i]));
            while(!pq.isEmpty()) {
                if(pq.peek().index <= i-k) pq.poll();
                else break;
            }
            result = Math.min(result, pq.peek().value);
        }
        return result;
    }
}

import java.util.*;

class Node{
    int value;
    int name;
    Node(int name, int value) {
        this.name = name;
        this.value = value;
    }
}

class Solution {
    public int solution(int[] priorities, int location) {
        Queue<Node> queue = new LinkedList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> pq2 = new PriorityQueue<>((o1, o2) -> o1 > o2 ? -1 : 1);
        PriorityQueue<Integer> pq3 = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 > o2 ? -1 : 1;
            }
        });


        int answer = 1;

        for(int i=0; i<priorities.length;i ++) {
            pq.add(priorities[i]);
            queue.add(new Node(i, priorities[i]));
        }

        while(!pq.isEmpty()) {
            System.out.println("PQ : " + pq.element());
            while(pq.element() != queue.element().value) {
                Node cur = new Node(queue.element().name, queue.element().value);
                System.out.println(cur.name + " " + cur.value);
                queue.remove();
                queue.add(cur);
            }
            if(queue.element().name == location) return answer;
            answer++;
            pq.remove();
            queue.remove();
        }
        return answer;
    }
}


class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
    }
}


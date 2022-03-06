import java.util.*;

class Truck {
    int weight, entranceTime;
    Truck(int weight, int entranceTime) {
        this.weight = weight;
        this.entranceTime = entranceTime;
    }
}

class Solution {

    Queue<Truck> queue = new LinkedList<>();
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int idx = 0, time = 0, curWeight = 0;
        while(true) {
            time ++;

            if(!queue.isEmpty() && time - queue.element().entranceTime >= bridge_length) {
                curWeight -= queue.element().weight;
                queue.remove();
            }

            if(queue.isEmpty() && idx >= truck_weights.length) return time;

            if(idx < truck_weights.length && curWeight + truck_weights[idx] <= weight) {
                curWeight += truck_weights[idx];
                queue.add(new Truck(truck_weights[idx], time));
                idx++;
            }
        }
    }
}
class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(2,10, new int[]{7,4,5,6}));

    }
}


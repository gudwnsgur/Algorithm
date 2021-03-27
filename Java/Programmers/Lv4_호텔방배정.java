import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

class Solution {
    ConcurrentHashMap<Long, Long> map = new ConcurrentHashMap<>();

    long getParents(long node) {
        if(!map.containsKey(node)) return node;

        map.put(node, getParents(map.get(node)));
        return getParents(map.get(node));
    }

    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];

        for(int i=0; i<room_number.length; i++) {
            if (!map.containsKey(room_number[i])) {
                answer[i] = room_number[i];
                long p = getParents(room_number[i] + 1);
                map.put(room_number[i], p);

            }
            else {
                long p = getParents(room_number[i]);
                answer[i] = p;
                map.put(p, getParents(p+1));

            }
        }
        return answer;
    }
}
class Main {
    public static void main(String[] args) {
    }
}

import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        HashMap<String, Integer> map = new HashMap<>();
        ArrayList<String> kinds = new ArrayList<>();
        int answer = 1;
        for (String[] cloth : clothes) {
            if (!map.containsKey(cloth[1])) {
                map.put(cloth[1], 2);
                kinds.add(cloth[1]);
            } else map.put(cloth[1], map.get(cloth[1]) + 1);
        }

        for (String kind : kinds) {
            answer *= map.get(kind);
        }
        return answer-1;
    }
}

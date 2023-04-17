import java.util.HashMap;
import java.util.Map;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        Map<String, Integer> rate = new HashMap<>();

        for(int i=0; i<players.length; i++) {
            rate.put(players[i], i);
        }

        for (String call : callings) {
            String tmp = players[rate.get(call) - 1];
            players[rate.get(call) - 1] = players[rate.get(call)];
            players[rate.get(call)] = tmp;

            rate.put(call, rate.get(call) - 1);
            rate.put(tmp, rate.get(tmp) + 1);
        }
        return players;
    }
}

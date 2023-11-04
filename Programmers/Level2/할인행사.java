import java.util.HashMap;

class Solution {

    HashMap<String, Integer> map = new HashMap<>();
    HashMap<String, Integer> cur = new HashMap<>();

    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        for (int i = 0; i < want.length; i++) {
            map.put(want[i], number[i]);
        }

        for (int i = 0; i < 10; i++) {
            cur.put(discount[i], cur.getOrDefault(discount[i], 0) + 1);
        }

        for (int i = 10; i < discount.length; i++) {
            if (possible(want)) {
                answer++;
            }
            goToNextDay(discount[i], discount[i - 10]);
        }
        if (possible(want)) {
            answer++;
        }
        return answer;
    }

    private void goToNextDay(String nextProduct, String previousProduct) {
        if (nextProduct.equals(previousProduct)) {
            return;
        }
        cur.put(nextProduct, cur.getOrDefault(nextProduct, 0) + 1);
        cur.put(previousProduct, cur.get(previousProduct) - 1);
    }

    private boolean possible(String[] want) {
        for (int i = 0; i < want.length; i++) {
            if (map.get(want[i]) > cur.getOrDefault(want[i], 0)) {
                return false;
            }
        }
        return true;
    }
}


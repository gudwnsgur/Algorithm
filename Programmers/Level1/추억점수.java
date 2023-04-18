import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] result = new int[photo.length];
        Map<String, Integer> score = new HashMap<>();
        for (int i = 0; i < name.length; i++) score.put(name[i], yearning[i]);

        for(int i=0; i<photo.length; i++) {
            int total = 0;
            for(int j=0; j<photo[i].length; j++) {
                total += score.getOrDefault(photo[i][j], 0);
            }
            result[i] = total;
        }
        return result;
    }
}


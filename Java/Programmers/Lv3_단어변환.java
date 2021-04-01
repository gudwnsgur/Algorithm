import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        int answer = -1;
        boolean[] visited = new boolean[words.length];

        Queue<String> queue = new LinkedList<>();
        queue.add(begin);
        while (!queue.isEmpty()) {
            int size = queue.size();
            answer++;
            for (int s = 0; s < size; s++) {
                if (queue.element().equals(target)) return answer;
                String cur = queue.element();

                for (int i = 0; i < words.length; i++) {
                    if (!visited[i]) {
                        int cnt = 0;
                        for (int j = 0; j < cur.length(); j++) {
                            if (cur.charAt(j) != words[i].charAt(j)) cnt++;
                        }
                        if (cnt == 1) {
                            visited[i] = true;
                            queue.add(words[i]);
                        }
                    }
                }
                queue.remove();
            }
        }

        return 0;
    }
}

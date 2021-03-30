import java.util.*;
class Solution {
    public int[] solution(String s) {
        HashMap<String, Integer> map = new HashMap<>();
        ArrayList<String> str = new ArrayList<>();

        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                String num = "";
                int j =i;
                for(; (s.charAt(j) >='0' && s.charAt(j) <= '9'); j++) {
                    num += s.charAt(j);
                }
                if(map.containsKey(num)) map.put(num, map.get(num) + 1);
                else {
                    map.put(num, 1);
                    str.add(num);
                }
                i = j;
            }

        }
        Collections.sort(str, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(map.get(o1) > map.get(o2)) return -1;
                else if(map.get(o1) < map.get(o2)) return 1;
                return 0;
            }
        });
        int[] answer = new int[str.size()];
        for(int i=0; i<str.size(); i++) {
            answer[i] = Integer.parseInt(str.get(i));
        }
        return answer;
    }
}
class Main{
    public static void main (String[] args) {
        Solution solution = new Solution();
    }
}

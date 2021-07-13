import java.util.*;


class Solution {
    public String[] strings = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    public int solution(String s) {
        String result = "";
        for (int i = 0; i < s.length(); ) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                result += s.charAt(i);
                i++;
            } else {
                String str = "";
                boolean done = false;
                while (i < s.length() && s.charAt(i) > '9') {
                    str += s.charAt(i);
                    for (int j = 0; j < 10; j++) {
                        if (strings[j].equals(str)) {
                            result += j;
                            done = true;
                            break;
                        }
                    }
                    i++;
                    if (done) break;
                }
            }
        }
        return Integer.parseInt(result);
    }
}

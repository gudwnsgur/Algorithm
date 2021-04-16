import java.util.*;

class Solution {
    public boolean isRightBracket(String str) {
        Stack<Character> stack = new Stack<>();
        for(int i=0; i<str.length(); i++) {
            char ch = str.charAt(i);
            if(ch == '[' || ch == '(' || ch == '{') stack.push(ch);
            else {
                if(stack.isEmpty()) return false;
                if(ch == ']' && stack.peek() != '[') return false;
                if(ch == ')' && stack.peek() != '(') return false;
                if(ch == '}' && stack.peek() != '{') return false;

                stack.pop();
            }
        }
        return stack.isEmpty();
    }
    public int solution(String s) {
        if(s.length() % 2 == 1) return 0;
        int cnt = 0;
        for(int i=0; i<s.length(); i++) {
            String a = s.substring(0, i), b = s.substring(i);
            if(isRightBracket(b+a)) cnt++;
        }
        return cnt;
    }
}

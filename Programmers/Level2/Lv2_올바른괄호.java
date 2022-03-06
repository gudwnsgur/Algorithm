import java.util.*;
class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> stack = new Stack<>();
        if(s.charAt(0) == ')') return false;
        if(s.charAt(s.length()-1) == '(') return false;


        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == '(') stack.add(s.charAt(i));
            else {
                if(stack.isEmpty()) return false;
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
}
class Main{
    public static void main (String[] args) {
        Solution solution = new Solution();
    }
}

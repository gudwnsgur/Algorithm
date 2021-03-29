package com.company;

import java.util.*;

class Solution {

    String result = "";

    boolean isRightString(String u) {
        Stack<Character> s = new Stack<>();

        for(int i=0; i<u.length(); i++) {
            char ch = u.charAt(i);

            if(ch == '(') s.push(ch);
            else {
                if(s.isEmpty()) return false;
                s.pop();
            }
        }
        return s.isEmpty();
    }


    String solve(String p) {
        // ( ) ) ) ( ( ( )
        // 0 1 2 3 4 5 6 7
        if(p.length() == 0) return "";
        String u ="", v = "";
        int leftCnt = 0, rightCnt = 0, idx = 0;

        for(; idx<p.length(); idx++) {
            if ((p.charAt(idx) == '('))    leftCnt++;
            else rightCnt++;

            if(leftCnt == rightCnt) break;
        }
        u = p.substring(0, idx+1);
        if(idx+1 != p.length()) v = p.substring(idx+1);


        if(isRightString(u)) return u + solve(v);
        else {
            String tmp = "(" + solve(v) + ")";
            for(int i=1; i<u.length()-1; i++) {
                if(u.charAt(i) == '(') tmp += ')';
                else tmp += '(';
            }
            return tmp;
        }
    }


    public String solution(String p) {
        String answer = "";
        boolean pos =true;
        Stack<Character> stack = new Stack<>();

        for(int i=0; i<p.length(); i++) {
            char ch = p.charAt(i);
            if(ch == '(') stack.push(ch);
            else {
                if(stack.isEmpty()) {
                   pos = false;
                   break;
                }
                stack.pop();
            }
        }
        if(pos) return p;
        return solve(p);
    }
}
class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution("(()())()"));
        System.out.println(solution.solution(")("));
        System.out.println(solution.solution("()))((()"));


    }
}


import java.util.*;

class Solution {
    public int solution(String name) {
        int answer = 0;
        ArrayList<Integer> Aidx = new ArrayList<>();
        ArrayList<Integer> idx = new ArrayList<>();
        for(int i=0; i<name.length(); i++) {
            answer += Math.min(name.charAt(i) - 'A', 'A' + 26 - name.charAt(i));
            if(name.charAt(i) == 'A') Aidx.add(i);
            else idx.add(i);
        }
        if(Aidx.isEmpty()) return answer + name.length() - 1;
        if(idx.isEmpty()) return answer;

        int move = Math.min(name.length()-1, idx.get(idx.size()-1));

        move = Math.min(move,name.length() - idx.get(0));

        for(int i=0; i<idx.size() - 1; i++) {
            move = Math.min(move, idx.get(i) + idx.get(i) + name.length() - idx.get(i+1));
        }
        return answer + move;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

    }
}


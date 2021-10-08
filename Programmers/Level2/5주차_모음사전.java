import java.util.*;
import java.io.*;

class Solution {
    final char[] alpha = {'A', 'E', 'I', 'O', 'U'};
    int answer = 0;
    boolean finished = false;
    
    public void dfs(int len, char[] src, char[] dest) {
        boolean fin = true;
        for(int i=0; i<5; i++) {
            if(src[i] != dest[i]) fin=false;
        }
        if(fin) {
            finished = true;
            return;
        }
        if(len == 5) return;
            
        for(int i=0; i<5; i++) {
            if(finished) return;
            src[len] = alpha[i];
            answer++;
            dfs(len+1, src, dest);
            src[len] = 'X';
        }        
    }
    
    public int solution(String word) {
        char[] dest = new char[5];
        for(int i=0; i < word.length(); i++) dest[i] = word.charAt(i);
        for(int i = word.length(); i<5; i++) dest[i] = 'X';
        
        char[] src = {'X','X','X','X','X'};
        
        dfs(0, src, dest);
        return answer;
    }
}

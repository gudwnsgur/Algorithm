import java.util.*;
import java.io.*;

class Solution {
    public String solution(int[][] scores) {
        String answer = "";
        int n = scores.length;
        
        for(int i=0; i<n; i++) {
        	boolean notOnlyOne = false;
        	
        	int max = -1, min = 101;
        	int maxIdx = -1, minIdx = -1;
        	int res = 0;
        	
        	for(int j=0; j<n; j++) {
        		if(i != j && scores[i][i] == scores[j][i]) notOnlyOne = true;
        		
        		if(max < scores[j][i]) {
        			max = scores[j][i];
        			maxIdx = j;
        		}
        		if(min > scores[j][i]) {
        			min = scores[j][i];
        			minIdx = j;
        		}
        		
        		res += scores[j][i];
        	}
        	
        	if(!notOnlyOne) {
        		if(scores[i][i] == max) {
        			n--;
        			res -= scores[i][i];
        		}
        		if(scores[i][i] == min) {
        			n--;
        			res -= scores[i][i];
        		}
        	}
        	
        	res /= n;
        	
        	if(res >= 90) answer += "A";
        	else if(res >= 80) answer += "B";
        	else if(res >= 70) answer += "C";
        	else if(res >= 50) answer += "D";
        	else answer+= "F";
        	n = scores.length;
        }
        return answer;
    }
}

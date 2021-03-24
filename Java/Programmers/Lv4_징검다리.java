import java.util.*;

class Solution {
    int[] diff ;

    int erasedRock(int mid) {
        int cnt = 0;
        int curDist;
        System.out.println("Mid : " + mid);
        for(int i=0; i<diff.length; i++) {
            if(diff[i] >= mid) continue;

            curDist = diff[i];
            int j = i+1;
            for(; j<diff.length; j++) {
                curDist += diff[j];
                cnt++;
                if(curDist >= mid) break;
            }
            if(j == diff.length) return cnt+1;
            i = j;
        }
        return cnt;
    }

    public int solution(int distance, int[] rocks, int n) {
        diff = new int[rocks.length+1];
        Arrays.sort(rocks);
        diff[0] = rocks[0];

        for(int i=1; i<rocks.length; i++) {
            diff[i] = rocks[i] - rocks[i-1];
        }
        diff[rocks.length] = distance - rocks[rocks.length-1];
        int left = 1, right = distance;
        int answer = 1;

        while(left <= right) {
            int mid = (left+right)/2;
            int erased = erasedRock(mid);


            if(erased > n) right = mid-1;
            else {
                answer = mid;
                left = mid +1;
            }
        }
        return answer;
    }
}

class Main {
    public static void main(String[] args) {
        int[] a = {2,14,11,21,17};
        Solution s = new Solution();
        System.out.println(s.solution(25, a, 2));

    }
}

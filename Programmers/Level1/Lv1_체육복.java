import java.util.*;

class Solution {
    private int student[] = new int[32];

    public int solution(int n, int[] lost, int[] reserve) {
        for(int i=1; i<=n; i++) student[i] = 1;
        for(int value : lost) student[value]--;
        for(int value : reserve) student[value]++;

        for(int i=1; i<=n; i++) {
            System.out.print(student[i] + " ");
        }

        for(int i=1; i<=n; i++) {
            if(student[i] == 0) {
                if(student[i-1] == 2) {
                    student[i]++;
                    student[i-1]--;
                }
                else if(student[i+1] == 2) {
                    student[i]++;
                    student[i+1]--;
                }
            }
        }

        int cnt =0;
        for(int i=1; i<=n; i++) if(student[i] != 0 ) cnt++;
        System.out.println();
        return cnt;
    }
}


class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(5, new int[]{1, 2, 3}, new int[]{2, 3, 4}));

        System.out.println(s.solution(5, new int[]{1, 2, 3, 4, 5}, new int[]{1, 2, 3, 4, 5}));
        System.out.println(s.solution(5, new int[]{1, 2, 3, 4, 5}, new int[]{}));
    }
}

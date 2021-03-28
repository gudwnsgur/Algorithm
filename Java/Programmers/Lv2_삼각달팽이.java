import java.util.*;

class Solution {

    public int[] solution(int n) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        int[][] arr = new int[n + 1][n + 1];
        int[] loc = {1, 1, n, 1, n, 2, n, n, n - 1, n - 1, 2, 2};
        int num = 1;

        while (true) {
            int cnt = 0;
            for (int i = loc[0]; i <= loc[2]; i++, num++, cnt++) arr[i][loc[1]] = num;
            loc[0] +=2; loc[1]++;
            loc[2]--; loc[3]++;
            if(cnt == 1) break;

            cnt = 0;
            for(int i=loc[5]; i<=loc[7]; i++, num++, cnt++) arr[loc[4]][i] = num;
            loc[4]--; loc[5]++;
            loc[6]--; loc[7]-=2;
            if(cnt == 1) break;


            cnt = 0;
            for(int i=loc[8], j=loc[9]; i>=loc[10]; i--,j--, num++, cnt++) arr[i][j] = num;
            loc[8]--; loc[9]-=2;
            loc[10]+=2; loc[11]++;
            if(cnt == 1) break;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                arrayList.add(arr[i][j]);
            }
        }

        int[] answer = new int[arrayList.size()];
        for(int i=0; i<arrayList.size(); i++) answer[i] = arrayList.get(i);
        return answer;
    }
}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] a = solution.solution(4);
        int[] b = solution.solution(5);
        int[] c = solution.solution(6);

        for(int i=0; i<a.length; i++) System.out.print(a[i] + " ");
        System.out.println();
        for(int i=0; i<b.length; i++) System.out.print(b[i] + " ");
        System.out.println();
        for(int i=0; i<c.length; i++) System.out.print(c[i] + " ");
    }
}

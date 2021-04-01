import java.util.*;

class Solution {
    int[] p;
    int getParent(int node) {
        if(p[node] == node) return node;
        return getParent(p[node]);
    }

    void unionParent(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if(a < b) p[b] = a;
        else p[a] = b;
    }

    public int solution(int n, int[][] costs) {
        int answer = 0;
        p = new int[n];
        for(int i=0; i<n; i++) p[i] = i;

        ArrayList<int[]> arrays = new ArrayList<>(Arrays.asList(costs));
        Collections.sort(arrays, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[2] == o2[2]) {
                    if(o1[0] == o2[0]) {
                        if(o1[1] < o2[1]) return -1;
                        else if(o1[1] > o2[2]) return 1;
                        else return 0;
                    }
                    else if(o1[0] < o2[0]) return -1;
                    else return 1;
                }
                else if(o1[2] < o2[2]) return -1;
                else return 1;
            }
        });

        for(int[] arr : arrays) {
            if(getParent(arr[0]) != getParent(arr[1])) {
                answer += arr[2];
                unionParent(arr[0], arr[1]);
            }
        }
        return answer;
    }
}

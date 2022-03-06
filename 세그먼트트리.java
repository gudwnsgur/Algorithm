class Solution {
    int n;
    int[] segmentTree;
    int[] myArr;

    int initTree(int node, int s, int e) {
        if (s == e) return segmentTree[node] = myArr[s];

        return segmentTree[node] = initTree(node * 2, s, (s + e) / 2) +
                initTree(node * 2 + 1, (s + e) / 2 + 1, e);
    }

    int getSum(int node, int s, int e, int left, int right) {
        if (left > e || right < s) return 0;
        if (left <= s && e <= right) return segmentTree[node];
        return getSum(node * 2, s, (s + e) / 2, left, right) +
                getSum(node * 2 + 1, (s + e) / 2 + 1, e, left, right);
    }


    public int solution(int[] arr) {
        int answer = 0;

        n = arr.length;
        myArr = new int[n+1];
        for(int i=1; i<=n; i++) {
            myArr[i] = arr[i-1];
        }
        segmentTree = new int[n*4];
        initTree(1, 1, n);

        int startIdx = 1, endIdx = n;
        return getSum(1,1,n, startIdx, endIdx);
    }
}

class Main {
    public static void main(String[] args) {
        int[] a= {1,2,3,4, 5};
        Solution s =new Solution();
        System.out.println(s.solution(a));
    }
}

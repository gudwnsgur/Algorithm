import java.util.HashSet;

class Solution {
    public int solution(int[] elements) {
        int answer = 0;
        HashSet<Integer> set = new HashSet<>();
        int[] arr = new int[elements.length];

        for(int i=0; i<elements.length; i++) {
            for(int j=0; j<arr.length; j++) {
                arr[j] += elements[(j+i)%elements.length];
                if(!set.contains(arr[j])) {
                    set.add(arr[j]);
                    answer++;
                }
            }
        }
        return answer;
    }
}


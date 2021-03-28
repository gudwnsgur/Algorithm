import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        ArrayList<String> arr = new ArrayList<>();

        for(int i=0; i<numbers.length; i++) arr.add(Integer.toString(numbers[i]));

        Collections.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return Integer.compare(Integer.parseInt(o2 + o1), Integer.parseInt(o1 + o2));
            }
        });

        int zeroCnt = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr.get(i).equals("0")) zeroCnt++;
            answer+= arr.get(i);
        }
        if(zeroCnt != arr.size()) return answer;
        return "0";
    }
}
class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}


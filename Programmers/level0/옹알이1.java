class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        for(int i=0; i<babbling.length; i++) {
            boolean possible = true;
            String str = babbling[i];
            for(int j=0; j<babbling[i].length();) {
                if (str.startsWith("aya", j)) j += 3;
                else if (str.startsWith("ye", j)) j += 2;
                else if (str.startsWith("woo", j)) j += 3;
                else if (str.startsWith("ma", j)) j += 2;
                else {
                    possible = false;
                    break;
                }
            }
            if(possible) answer++;
        }
        return answer;
    }
}

class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        for (int i = 0; i <= t.length() - p.length(); i++) {
            answer += Long.parseLong(t.substring(i, i + p.length())) > Long.parseLong(p)
                    ? 0 : 1;
        }
        return answer;
    }
}

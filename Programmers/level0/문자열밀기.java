class Solution {
    public int solution(String a, String b) {
        for (int i = 0; i < a.length(); i++) {
            if ((a.substring(a.length() - i) + a.substring(0, a.length() - i)).equals(b))
                return i;
        }
        return -1;
    }
}

import java.util.*;

class Solution {

    long getGCD(long a, long b) {
        if(a < b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        while(b != 0) {
            long tmp = a%b;
            if(tmp == 0) return b;
            a = b;
            b = tmp;
        }
        return b;
    }


    public long solution(int w, int h) {
        long ww = w, hh = h, gcd = getGCD(ww, hh);
        return ww*hh - (ww/gcd + hh/gcd - 1) * gcd;
    }
}


class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
    }
}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tk;

    static boolean isPalindrome(String s) {
        int left = 0, right = s.length()-1;
        while(left < right) {
            if(s.charAt(left) != s.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        String s = br.readLine();
        while(!s.equals("0")) {
            System.out.println(isPalindrome(s) ? "yes" : "no");
            s = br.readLine();
        }
    }
}

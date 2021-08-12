import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n, result = 0;

    static boolean isGoodWord(String str) {
        if(str.length() % 2 != 0 ) return false;
        Stack<Character> s = new Stack<Character>();
        for(int i=0; i<str.length(); i++) {
            char ch = str.charAt(i);
            if(s.isEmpty()) s.push(ch);
            else if(s.peek() != ch) s.push(ch);
            else s.pop();
        }
        return s.isEmpty();
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++) {
            String str = br.readLine();
            if(isGoodWord(str)) result++;
        }
        System.out.println(result);
    }
}

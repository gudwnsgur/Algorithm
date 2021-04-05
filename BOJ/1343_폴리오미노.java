import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Pair{
    char ch;
    int cnt;
    Pair(char ch, int cnt) {
        this.ch = ch;
        this.cnt = cnt;
    }
}
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        ArrayList<Pair> arr = new ArrayList<>();
        int idx = 0;
        while(idx < str.length()) {
            int cnt = 1;
            char ch = str.charAt(idx);
            idx++;
            while(idx < str.length() && ch == str.charAt(idx)) {
                cnt++;
                idx++;
            }
            if(ch == 'X' && cnt % 2 == 1) {
                System.out.println(-1);
                return;
            }
            arr.add(new Pair(ch, cnt));
        }
        for (Pair pair : arr) {
            if(pair.ch == '.') for(int j=0; j<pair.cnt; j++) System.out.print('.');
            else {
                for(int j=0; j < pair.cnt - pair.cnt%4 ; j++) System.out.print('A');
                for(int j=0; j < pair.cnt%4 ; j++) System.out.print('B');
            }
        }
        System.out.println();
    }
}
